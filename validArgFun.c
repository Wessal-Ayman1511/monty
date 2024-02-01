#include "LIFO_FIFO.h"
/**
 * validArg - valid push arguments
 * @token: input
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
