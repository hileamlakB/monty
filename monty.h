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
* struct code_args_s -  argument information
* @args: a list of the aguments
* @argc: number of arguments to passed
* 0 - means none,
* 1 - means 1,
* 2 - more than one
*/
typedef struct code_args_s
{
	int args[2];
	int argc;
}code_args_t

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
void interpret(char *, int, stack_t **);

/*Interpreter helpers*/
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void comment(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*error_utils*/
void perr_line(char *, int, char *);
void perr(char *, char *);

#endif /*MONTY*/
