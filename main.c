#include "LIFO_FIFO.h"
/**
 * main- Entry point
 * @argv: input
 * @argc: input
 * Return: 0
*/
int main(int argc, char *argv[])
{
	FILE *openFile;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile = fopen(argv[1], "r");
	if (!openFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	accesFile(openFile);
	fclose(openFile);
	return (EXIT_SUCCESS);
}
