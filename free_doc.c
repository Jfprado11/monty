#include "monty.h"
/**
 *free_stack - liberated the stack
 *@head: the stack
 *
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}

/**
 *free_tokenizer - free the array
 *@free_token: the array
 */
void free_tokenizer(char **free_token)
{
	int i = 0;

	while (free_token[i])
	{
		free(free_token[i]);
		i++;
	}
	free(free_token);
}
