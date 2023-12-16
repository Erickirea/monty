#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: pointer to the stack head
 * @line_number: line number in monty file
 */
void rotl(stack **head, _attribute_((unused))
		unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * rotr - rotates the stack to the bottom
 * @head: pointer to the stack head
 * @line_number: line number in monty
 */
void rotr(stack_t **head, __attribute__((unused))
		unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
