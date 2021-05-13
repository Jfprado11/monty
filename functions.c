#include "header.h"
/**
*
*
*/
void string_cmp(char **array, int line, stack_t **head)
{
	instruction_t cmp_op[] = {
		{"push", func_push},
		{"pall" , func_pall},
		{NULL, NULL}
	};
	int i = 0;
	while (cmp_op[i].opcode != NULL)
	{
		if (strcmp(array[0], cmp_op[i].opcode) == 0)
		{
			cmp_op[i].f(head, line);
		}
		i++;
	}
}
/**
 * 
 *  
 */
void func_push(stack_t **head, int line)
{
	stack_t *new_node = NULL;
	new_node = malloc(sizeof(stack_t));
	new_node->prev = NULL;
	new_node->n = atoi(global_data);
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
/**
 * 
 * 
 */
void func_pall(stack_t **head, int line)
{
	stack_t *aux;
	aux = *head;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
