#include "monty.h"
/**
 * freeStack - frees a list.
 * @head: head of list
 * Description: free list
 * Return: Nothing
 */
void freeStack(stack_t **head)
{

	stack_t *ptr = NULL;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		ptr = (*head)->next;
		free(*head);
		(*head) = ptr;
	}
}
