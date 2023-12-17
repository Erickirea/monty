#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the monty file
 * Return: no return
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n;
	temp->next->n = aux;
}
