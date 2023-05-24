#include "shell.h"

/**
 * main - entry point of the program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	size_t buffer_size;
	char *input_line;
	int i, token_count, cmd_count, sh_interaction;

	buffer_size = 0;
	input_line = NULL;
	token_count = 0;
	cmd_count = 1;

	signal(SIGINT, SIG_IGN);
	sh_interaction = isatty(STDIN_FILENO);
	if (sh_interaction == 0 && ac == 1)
	{
		while (getline(&input_line, &buffer_size, stdin))
		{
			token_count = num_count(input_line);
			parse(input_line, token_count, av, cmd_count);
			input_line = NULL;
		}
		free(input_line);
		return (0);
	}

	while (sh_interaction)
	{
		write(1, "($) ", 4);
		token_count = 0;
		i = getline(&input_line, &buffer_size, stdin);
		if (i < 0)
		{
			free(input_line);
			write(1, "\n", 1);
			break;
		}
		token_count = num_count(input_line);
		parse(input_line, token_count, av, cmd_count);
		cmd_count++;
		input_line = NULL;
	}
	return (0);
}
