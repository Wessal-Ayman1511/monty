#include "LIFO_FIFO.h"
/**
 * accesFile- read file linely
 * @openFile: input
 * Return: void
*/
void accesFile(FILE *openFile)
{
	unsigned int lineNum = 0;
	size_t size = 0;
	char *lineBuff = NULL;
	char *arg = NULL;
	char *op = NULL;
	stack_t *stack = NULL;

	while (getline(&lineBuff, &size, openFile) != -1)
	{
		lineNum++;
		op = strtok(lineBuff, " \n");
		if (op == NULL || strchr(op, '#') != NULL)
			continue;
		if (strcmp(op, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if (arg != NULL && validArg(arg))
			{
				push(&stack, lineNum, arg);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNum);
				free(op);
				freeStack(&stack);
				fclose(openFile);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			getFunc(op, &stack, lineNum, openFile);
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
				{"pint", pint}
				};
	while (i < 1)
	{
		if (strcmp(codes[i].opcode, opcode) == 0)
		{
			codes[i].f(ptrStack, line);
			return;
		}
	i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	free(opcode);
	freeStack(ptrStack);
	fclose(f);
	exit(EXIT_FAILURE);


}
