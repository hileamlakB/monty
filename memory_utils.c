#include "monty.h"

/**
 *trims - trims space in front of a string and more than one spaces in between
 *@str: pointer to the string to be edited
 *@strt: string to be trimed
 */
void trims(char **str, char *strt)
{
	char *new = smalloc(sizeof(char) * 1), *_str = strt, *tmp;
	int first = 1, count = 1, index = 0;

	*new = '\0';
	while (*_str)
	{
		if ((*_str == ' ' || *_str == '\t') && first)
			_str++;
		else if ((*_str == ' ' || *_str == '\t') && count)
			count++, _str++;
		else if (*_str != ' ' && *_str != '\t')
		{
			tmp = smalloc(sizeof(char) * (strlen(new) + 3));
			if (!tmp)
				exit(-1);
			strcpy(tmp, new);
			if (count > 1)
				tmp[index] = ' ', index++;

			tmp[index] = *_str;
			tmp[index + 1] = '\0';
			free(new);
			first = 0, count = 1, new = tmp, index++, _str++;
		}
	}
	*str = new;
}
/**
 *smalloc - allocates a memory location and returns a pointer
 *@size: amount to be  allocated
 *Return: a generic pointer allocated or -1 on faliure
 */
void *smalloc(unsigned int size)
{
	char *pointer = malloc(size);
	void *_pointer = NULL;
	unsigned int i = 0;

	if (!pointer)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < size)
	{
		pointer[i] = '\0';
		i += 1;
	}
	_pointer = (void *)pointer;
	return (_pointer);
}
