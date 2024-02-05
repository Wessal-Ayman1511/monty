#include "monty.h"
/**
 * sub - subtraction
 * @stack: input
 * @l: the line number
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int l)
{
		stack_t *ptr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * mul - multiply
 * @stack: input
 * @l: the line number
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int l)
{
		stack_t *ptr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * div - divide
 * @stack: input
 * @l: the line number
 * Return: Nothing.
 */
void div(stack_t **stack, unsigned int l)
{
		stack_t *ptr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(ptr);
}
/**
 * mod - moduls
 * @stack: mod
 * @l: the line number
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int l)
{
		stack_t *ptr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(ptr);
}
