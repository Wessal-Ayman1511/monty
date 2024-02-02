#include "monty.h"

/**
 * push - pushes node
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * @data: arguments
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line, char *data)
{
	stack_t *new = NULL;


	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(data);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;

	(*stack) = new;
}
/**
 * pall - prints the data
 * @stack: input
 * @line: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *ptr;
	(void)line;

	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
