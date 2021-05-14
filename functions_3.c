#include "monty.h"
/**
 *func_div - subtract the top element from the second top.
 *@head: the linked list.
 *@line: the line of the number.
 */
void func_div(stack_t **head, unsigned int line)
{
	stack_t *aux = *head;
	int div = 0, i = 0;

	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line);
			free_tokenizer(global.array_st);
			free_stack(*head);
			fclose(global.fd_st);
			exit(EXIT_FAILURE);
		}
		aux = *head;
		aux = aux->next;
		div = aux->n / (*head)->n;
		aux->n = div;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
}

/**
 *func_mul - mult the top element from the second top.
 *@head: the linked list.
 *@line: the line of the number.
 */
void func_mul(stack_t **head, unsigned int line)
{
	stack_t *aux = *head;
	int mul = 0, i = 0;

	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = *head;
		aux = aux->next;
		mul = aux->n * (*head)->n;
		aux->n = mul;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
}
/**
 *func_mod - take the mod the top element from the second top.
 *@head: the linked list.
 *@line: the line of the number.
 */
void func_mod(stack_t **head, unsigned int line)
{
	stack_t *aux = *head;
	int mod = 0, i = 0;

	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line);
			free_tokenizer(global.array_st);
			free_stack(*head);
			fclose(global.fd_st);
			exit(EXIT_FAILURE);
		}
		aux = *head;
		aux = aux->next;
		mod = aux->n % (*head)->n;
		aux->n = mod;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
}
