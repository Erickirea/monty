#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to the head of the stack
 * @line_number: file line in the monty line
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - prints the value at the top of the stack
 * @head: pointer to the head of the stack
 * @line_number: file line in the monty line
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
