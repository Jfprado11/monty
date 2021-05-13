#include "header.h"
/**
* main - entry point.
* @ac: arguments counter.
* @av: arguments vector.
* Return: Always 0.
*/
int main(int ac, char *av[])
{
	int i = 0, lines = 1;
	FILE *fd;
	char buf[1024], **tokens = NULL, *delimit = " \t\n\r\a", *token = NULL;
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
	while (fgets(buf, 1024, fd) != NULL)
	{
		i = 0;
		tokens = malloc(sizeof(char *) * strlen(buf));
		token = strtok(buf, delimit);
		while (token)
		{
			tokens[i] = strdup(token);
			i++;
			token = strtok(NULL, delimit);
		}
		tokens[i] = NULL;
		global_data = tokens[1];
		i = 0;
		while(tokens[i] != NULL)
		{
			/**printf("%s\n", tokens[i]);*/
			i++;
		}
		string_cmp(tokens, lines, &head);
		lines++;
		free_tokenizer(tokens);
	}
    free_stack(head);
	fclose(fd);
	return (0);
}

void free_tokenizer(char **free_token)
{
	int i = 0;
	while(free_token[i])
	{
		free(free_token[i]);
		i++;
	}
	free(free_token);
}