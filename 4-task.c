#include "monty.h"
/**
 * add - adds the top two elements together
 * @stack: pointer to the head node pointer of stack
 * @l: the line number
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int l)
{
		stack_t *ptr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(ptr);
}
