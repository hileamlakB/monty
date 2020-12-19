#ifndef MONTY
#define MONTY

/*Liberaries*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * Description: opcode and its respctive function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **, unsigned int);
} instruction_t;

/**
* struct code_token_s - a command and its argument
* @cmd: command string
* @args: a list of the aguments
* @argc: number of arguments to excpect
*/
typedef struct code_token_s
{
	char *cmd;
	int args;
	int argc;
}code_token_t

/*loader*/
FILE *sopen(char *);

/*memory_utils*/
void freedp(char **);
int arlen(char **);
void trims(char **, char *);
void *smalloc(unsigned int);
void *srealloc(void *, unsigned int);

/*Interpreter funnction*/
void (*get_op_func(char *))(stack_t **, unsigned int);
void interpret(char *line);

/*Interpreter helpers*/
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void div(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void comment(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
#endif /*MONTY*/
