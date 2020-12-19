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
	int fd = -1;


	/*check if there is correct argument number*/
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*safely open the file*/
	fd = sopen(argv[1]);

	/*Read one line at a time*/
	/*Check if it is correct*/
	/*Execute that line*/
	while ()
	{

	}

	/*Close the file before exiting*/
	close(fd);
	exit(EXIT_SUCCESS);
}

