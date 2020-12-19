#include "monty.h"


/**
 * get_op_func -  selects the correct function to
 * perform the operation asked by the commad
 * @s: input string
 * Return: pointer to a function
 */
void (*get_op_func(char *command))(stack_t **, unsigned int)
{
	instruction_s ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mult", mult},
		{"mod", mod},
		{"comment", comment},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;
	const int num_of_cmds = 16; /*Number of commands in ops*/

	while (i < num_of_cmds)
	{
		if (!strcmp(ops[i].opcode, command))
			return (ops[i].func);
		i++;
	}
	return (NULL);
}






