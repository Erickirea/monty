#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @head: pointer to the stack head
 * @line_number: line number to monty file
 */
void mul(stack **head, unsigned int line_number)
{
	stack *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->next->n * temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}

/**
 * mod - computes the rest of the division of second element
 * @head: pointer to the stack head
 * @line_number: line number in monty file
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = temp->next->n % temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}

/**
 * pchar - prints the char at the top of stack
 * @head: pointer to the stack head
 * @line_number: line number in monty
 */
void pchar(stack **head, unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to the stack head
 * @line_number: line number in monty file
 */
void pstr(stack **head, unsigned int line_number)
{
	stack_t **temp;
	(void)line_number;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
