#include "LIFO_FIFO.h"
/**
 * swap - swaps
 * @stack: pointer to the head node pointer of stack
 * @l: the line number
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int l)
{
	int d;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	d = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = d;
}
