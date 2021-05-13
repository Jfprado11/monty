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
		if (tmp->next != NULL)
			tmp->next->prev = (*head);
	    tmp->next = (*head);
	    (*head)->prev = tmp;
		*head = tmp;
	}
}
/**
 * func_add - Function to add the first two nodes.
 * @head: head of doubly linked list.
 * @line: lines of readed text.
 */
void func_add(stack_t **head, unsigned int line)
{
	stack_t *aux = *head;
	int sum = 0, i = 0;

	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = *head;
		aux = aux->next;
		sum = aux->n + (*head)->n;
		aux->n = sum;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
}

/**
 * func_nop - Function does nothing.
 * @head: head of doubly linked list.
 * @line: lines of readed text.
 */
void func_nop(stack_t **head __attribute__((unused)), unsigned int line)
{
	unsigned int i = 0;

	i = i + line;
}
