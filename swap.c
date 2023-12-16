#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the monty file
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
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
	h = *head;
	aux = h->n;
	h->next->n = aux;
}
