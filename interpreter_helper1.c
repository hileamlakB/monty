#include "monty.h"

/**
 * push - pushes a new element to the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void push(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *new_node, *_head = *head;
	extern char *data_mod;

	if (token.argc != 1)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Create a node and give it the required values*/
	new_node = smalloc(sizeof(stack_t));
	new_node->n = token.args;

	/*if the data mode is stack store the data in front*/
	if (!strcmp(data_mode, "stack"))
	{
		new_node->prev = NULL;
		new_node->next = _head;
		if (_head)
			_head->prev = new_node;
		_head = new_node;
	}
	else if (!strcmp(data_mod, "queue"))
	{
		/*go to the end of the file*/
		while (_head->next)
			_head = _head->next;
		new_node->prev = _head;
		new_node->next = NULL;
		_head->next = new_node;
	}
}

/**
 * pall - prints all value of the stack starting from top to bottom
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pall(stack_t **head, unsigned int line_number, code_args_t token)
{
}


/**
 * pint - prints top element of stack followed by new line
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pint(stack_t **head, unsigned int line_number, code_args_t token)
{
}


/**
 * pop - removes top element of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pop(stack_t **head, unsigned int line_number, code_args_t token)
{
}


/**
 * swap - swaps the top two elements of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void swap(stack_t **head, unsigned int line_number, code_args_t token)
{
}
