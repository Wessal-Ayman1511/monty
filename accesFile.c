#include "LIFO_FIFO.h"
/**
 * accesFile- read file linely
 * @openFile: input
 * Return: void
*/
void accesFile(FILE *openFile)
{
	int lineNum = 0; 
	size_t size = 0; 
	char *lineBuff = NULL, *arg = NULL, *op = NULL;
	stack_t *stack = NULL;


	while(getline(&lineBuff, &size, openFile))
	{
		lineNum++;
		op = strtok(lineBuff, " \n");
		if (op == NULL || strchr(op, "#") != NULL);
		continue;
		if (strcmp(op, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if(arg != NULL && validArg(arg))
			{
				push(&stack, lineNum, arg);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNum);
				free(op);
				free_stack(&stack);
				fclose(openFile);
				exit(EXIT_FAILURE);
			}
		}
		else{
			getFunc(*op, &stack, lineNum, openFile);
		}

	}
	free(op);
	freeStack(&stack);
}
/**
 * getFunc- function that return the correct func
 * @opcode: input
 * @f: input
 * @ptrStack: input
 * @line: input
 * Return: void
*/
void getFunc(char *opcode, stack_t **ptrStack, int line, FILE *f)
{
	int i = 0;
	instruction_t codes[] = {
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop}};
	while(i < 5)
	{
		if (strcmp(codes[i].opcode, opcode) == 0)
		{
			codes[i].f(ptrStack, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	free(opcode);
	free_stack(ptrStack);
	fclose(f);
	exit(EXIT_FAILURE);


}
/**
 * vaidArg - valid push arguments
 * @arg: input
 * Return: bool
 */
bool validArg(char *token)
{
	int c = 0;

	for ( ; token[c]; c++)
	{
		if (token[0] == '-')
			continue;

		if (isdigit(token[c]) == 0)
			return (false);
	}
	return (true);
}
/**
 * free_stack - frees a list.
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
