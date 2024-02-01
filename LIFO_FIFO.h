#ifndef LIFO_FIFO_H
#define LIFO_FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void freeStack(stack_t **head);
void getFunc(char *opcde, stack_t **ptrStack, int line, FILE *f);
void accesFile(FILE *openFile);
bool validArg(char *token);

stack_t *add_dnodeint(stack_t **head, const int n);
void push(stack_t **stack, int unsigned line, char *arg);
void pall(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void pop(stack_t **stack, int unsigned lineNum);
void swap(stack_t **stack, int unsigned lineNum);
void add(stack_t **stack, int unsigned lineNum);
void nop(stack_t **stack, int unsigned lineNum);


















#endif
