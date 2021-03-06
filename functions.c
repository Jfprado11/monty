#include "monty.h"

/**
*string_cmp - compare the opcodes if exits.
*@array: the opcode and its arguments
*@line: the line readed of the file
*@head: data structure Doubly linked list
*@fd: Readed file.
*/

void string_cmp(char **array, unsigned int line, stack_t **head, FILE *fd)
{
	instruction_t cmp_op[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{NULL, NULL}
	};
	int i = 0;

	if (array[0][0] == '#')
		return;
	while (cmp_op[i].opcode != NULL)
	{
		if (strcmp(array[0], cmp_op[i].opcode) == 0)
		{
			cmp_op[i].f(head, line);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, array[0]);
	free_tokenizer(array);
	if (*head != NULL)
		free_stack(*head);
	fclose(fd);
	exit(EXIT_FAILURE);
}
/**
 *func_push - pushes a value into the stack
 *@head: the stack
 *@line: line readed
 */

void func_push(stack_t **head, unsigned int line)
{
	stack_t *new_node = NULL;
	char *num = global.data;
	int check = 0;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	check = check_idigit(num);
	if (check == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_tokenizer(global.array_st);
		free_stack(*head);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = atoi(global.data);
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
/**
 *func_pall - print the stack
 *@head: the stack
 *@line: line readed
 */

void func_pall(stack_t **head, unsigned int line __attribute__((unused)))
{
	stack_t *aux = NULL;

	if (*head == NULL)
		return;
	aux = *head;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 *func_pint - print the top of the stack
 *@head: the stack
 *@line: line readed
 */
void func_pint(stack_t **head, unsigned int line)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_tokenizer(global.array_st);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 *func_pop - Function to renove the top of the element.
 *@head: Pointer head of duobly linked list.
 *@line: Lines of readed file.
 */

void func_pop(stack_t **head, unsigned int line)
{
	stack_t *aux = NULL;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_tokenizer(global.array_st);
		fclose(global.fd_st);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		aux = *head;
		aux = (*head)->next;
		free(*head);
		*head = aux;
		aux = NULL;
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}
