#include "monty.h"

/**
 *sarrdup - safe array duplicate
 *@src: array to be duplicated
 *Return: a double pointer to the newly allocated array
 */
char **sarrdup(char **src)
{
	char **tmp = smalloc(sizeof(char *) * (arlen(src) + 2));
	char **_tmp = tmp;

	while (*src)
		*_tmp = _strdup(*src), _tmp++, src++;
	*_tmp = NULL;
	return (tmp);

}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{

	char *copy, *_copy;

	if (!str)
		return (NULL);
	copy = smalloc((strlen(str) + 1) * sizeof(char));
	_copy = copy;

	while (*str)
		*_copy = *str, str += 1, _copy += 1;

	*_copy = '\0';
	return (copy);
}

/**
 *freedll - frees a doubly linked list
 *@head: a pointer to the head of the doubly linked list
 */
void freedll(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

