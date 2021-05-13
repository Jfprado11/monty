#ifndef _HEADER_H
#define _HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_structure - extern global variable.
 * @data: Data readed from the file.
 * @array_st: Array.
 * @fd_st: file readed.
 */
typedef struct global_structure
{
char *data;
char **array_st;
FILE *fd_st;
} global_struct;

extern global_struct global;
void string_cmp(char **array, unsigned int line, stack_t **head, FILE *fd);
char **tokenizer(char **array, char *buf, char *delimit);
void func_push(stack_t **head, unsigned int line);
void func_pall(stack_t **head, unsigned int line);
void free_stack(stack_t *head);
void free_tokenizer(char **free_token);
void func_pint(stack_t **head, unsigned int line);
void func_pop(stack_t **head, unsigned int line);
void func_swap(stack_t **head, unsigned int line);
void func_add(stack_t **head, unsigned int line);
void func_nop(stack_t **head __attribute__((unused)), unsigned int line);
global_struct global;

#endif /*_HEADER_H_*/
