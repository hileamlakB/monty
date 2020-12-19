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

/**
 * interpret - iterprets a singe line code
 * according the rules  specified by the monty
 * language
 * @line - a string holding a command
 */
void interpret(char *line, int line_number, stack_t **head)
{
	char *cmd = trims(line), *tmp = NULL, *errmsg = NULL;
	void (*func)(stack_t **, unsigned int) = NULL;

	/*Parse the command name and the arguments into the token*/
	tmp = strtok(cmd, " ");

	/*Get the corrspondng fuction to the opcode and callit*/
	func = get_op_func(tmp);
	if (func)
		func(head, line_number);
	else
	{
		/*hande the case if no commad is found for the opcode*/
		num = itoa(line_number);
		errmsg = smalloc(strlen("L: unknown instruction ") + strlen(num) + strlen(token.cmd) + 4);
		strcpy(errmsg, "L");
		strcat(errmsg, num);
		strcat(errmsg, ": unknown instruction ");
		strcat(errmsg, token.cmd);

		dprintf(2, "%s\n", errmsg);
		free(errmsg);
		exit(EXIT_FAILURE);
	}
}


