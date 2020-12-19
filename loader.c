#include "monty.h"

/**
 *sopen - opens a script file for the montey interpreter
 * if it is possible
 * @name: name of the file
 * Return: the file descriptor and -1 on faliure
 */
int sopen(char *name)
{
	char *path = NULL, *currentdir = NULL;
	int fd;
	char *errmsg = NULL;

	if (!name || strlen(name) <= 0)
		return (-1);

	if (name[0] != '.' && name[0] != '~' && name[0] != '/')
	{
		currentdir = getenv("PWD");
		path = smalloc(strlen(currentdir) + strlen(name) + 4);
		strcpy(path, currentdir);
		strcat(path, "/");
		strcat(path, name);
	}
	else
		path = strdup(name);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		errmsg = smalloc(strlen("Error: Can't open file ") + strlen(name) + 4);
		strcpy(errmsg, "Error: Can't open file ");
		strcat(errmsg, name);
		strcat(errmsg, "\n");
		dprintf(2, "%s", errmsg);
		free(errmsg);
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

	return (fd);
}

