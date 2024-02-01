#include "monty.h"
#define _GNU_SOURCE
/**
 * pop - removes the top element of stack
 * @s: pointer to the head node pointer of stack
 * @l: the line number
 * Return: Nothing.
 */
void pop(stack_t **s, unsigned int l)
{
	if (s == NULL || *s == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l);
		exit(EXIT_FAILURE);
	}

	if ((*s)->next != NULL)
	{
		*s = (*s)->next;
		free((*s)->prev);
		(*s)->prev = NULL;
	}
	else
	{
		free(*s);
		*s = NULL;
	}
}
