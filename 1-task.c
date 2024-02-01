#include "monty.h"
#define _GNU_SOURCE
/**
 * pint - print top
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	while (ptr)
	{
		if (ptr->prev == NULL)
			break;
		ptr = ptr->prev;
	}
	printf("%d\n", ptr->n);
}
