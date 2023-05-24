#include "shell.h"

/**
 * parse - converts user input in to tokens
 * @line: user input to be parsed
 * @token_count: number of tokens
 * @av: array of arguments
 * @cmd_count: number of commands that have been entered
 *
 * Return: 0 on success
 */

int parse(char *line, int token_count, char *av[], int cmd_count)
{
	int i, builtin, exval;
	char *p, *dup_line;
	char **ar1, **ar2;
	char *del = "\t\r\n\f\v";

	ar1 = malloc(sizeof(char *) * token_count);
	ar2 = NULL;
	dup_line = _strdup(line);

	p = strtok(dup_line, del);
	if (p == NULL)
	{
		free_mem(line, ar2, dup_line, ar1);
		return (0);
	}

	i = 0;
	for (; p != NULL; p = strtok(NULL, del))
	{
		ar1[i++] = p;
	}

	ar2 = malloc(sizeof(char *) * (token_count + 1));
	for (i = 0; i < token_count; i++)
	{
		ar2[i] = _strdup(ar1[i]);
	}
	ar2[i] = NULL;

	exval = 0;
	builtin = check_builtin(line, ar2, dup_line, ar1);
	if (builtin == 0)
	{
		exval = exe(line, ar2, dup_line, ar1, av, cmd_count);
	}
	free_mem(line, ar2, dup_line, ar1);

	return (exval);
}


/**
 * free_mem - frees memory
 * @line: line to be freed
 * @ar1: first array to be freed
 * @dup_line: duplicate line to be freed
 * @ar2: second array to be freed
 *
 * Return: void
 */

void free_mem(char *line, char **ar1, char *dup_line, char **ar2)
{
	int i;

	i = 0;
	if (ar1 != NULL)
	{
		while (ar1[i] != NULL)
		{
			free(ar1[i]);
			i++;
		}
		free(ar1);
	}

	if (dup_line != NULL)
	{
		free(dup_line);
	}
	if (line != NULL)
	{
		free(line);
	}

	i = 0;
	if (ar2 != NULL)
	{
		free(ar2);
	}
}


/**
 * num_count - counts number of tokens to be created
 * @line: user input to get tokens from
 *
 * Return: number of tokens
 */

int num_count(char *line)
{
	int i, token_count, check;

	token_count = 0;
	check = 1;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
		{
			check = 1;
		}
		else if (check == 1)
		{
			check = 0;
			++token_count;
		}
	}

	return (token_count);
}
