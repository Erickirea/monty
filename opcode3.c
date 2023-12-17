#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @head: pointer to the stack head
 * @line_number: file line in the monty file
 */
void add(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}

/**
 * nop - doesn't do anything
 * @head: pointer to the stack head
 * @line_number: file line in the monty file
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;
}

/**
 * sub - subtracts top element from second top element
 * @head: pointer to the stack head
 * @line_number: file line in the monty file
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
 * f_div - divides the top two elements of the stack
 * @head: pointer to the stack head
 * @line_number: file line in the monty file
 */
void f_div(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = temp->next->n / temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
