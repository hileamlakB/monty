#include "monty.h"

/**
 * main - entry point of the intepreter
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success, and error messages as specified
 in error.h
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	ssize_t read_stat = -1;
	char *line = NULL;
	size_t buffsize = 0;
	int reading = 1, line_number = 1;
	stack_t *head = NULL;
	extern char data_mod[6];

	/*check if there is correct argument number*/
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*safely open the file*/
	fd = sopen(argv[1]);

	/*Set the default data structure mode to stack*/
	strcpy(data_mod, "stack");

	/*Read one line at a time*/
	/*Check if it is correct*/
	/*Execute that line*/
	while (reading)
	{
		read_stat = getline(&line, &buffsize, fd);
		if (read_stat == -1)
		{
			reading = 0;
			break;
		}
		interpret(line, line_number, &head);
		line_number += 1;
	}

	if (line)
		free(line);
	if (head)
		freedll(head);
	/*Close the file before exiting*/
	fclose(fd);
	exit(EXIT_SUCCESS);
}
