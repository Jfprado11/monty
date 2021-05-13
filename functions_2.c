#include "monty.h"
/**
 * func_swap - Function to swap the first two nodes.
 * @head: head of doubly linked list.
 * @line: lines of readed text.
 */
void func_swap(stack_t **head, unsigned int line)
{
	int i = 0;
	stack_t *tmp = *head;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *head;
	    tmp = (*head)->next;
	    tmp->prev = NULL;
	    (*head)->next = tmp->next;
	    tmp->next->prev = (*head);
	    tmp->next = (*head);
	    (*head)->prev = tmp;
		*head = tmp;
	}
}
