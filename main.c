#include "monty.h"

/**
* main - entry point.
* @ac: arguments counter.
* @av: arguments vector.
* Return: Always 0.
*/

int main(int ac, char *av[])
{
	unsigned int lines = 1;
	FILE *fd;
	char buf[1024], **tokens = NULL, *delimit = " \t\n\r\a";
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	global.fd_st = fd;
	while (fgets(buf, 1024, fd) != NULL)
	{
		tokens = malloc(sizeof(char *) * strlen(buf));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		tokens = tokenizer(tokens, buf, delimit);
		if (tokens[0] != NULL)
		{
			global.data = tokens[1];
			global.array_st = tokens;
			string_cmp(tokens, lines, &head, fd);
		}
		lines++;
		free_tokenizer(tokens);
	}
	free_stack(head);
	fclose(fd);
	return (EXIT_SUCCESS);
}

/**
 *tokenizer - tokenize the line of the file
 *@array: the array where token are going to be stored
 *@buf: the line to be tokenized
 *@delimit: the delimit to execute tokenize
 *Return: the array with the tokens
 */

char **tokenizer(char **array, char *buf, char *delimit)
{
	int i = 0;
	char *token = NULL;

	token = strtok(buf, delimit);
		while (token)
		{
			array[i] = strdup(token);
			i++;
			token = strtok(NULL, delimit);
		}
		array[i] = NULL;
		return (array);
}
