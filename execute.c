#include "shell.h"

/**
 * exe - executes new processes
 * @line: user input
 * @ar: array to be handled by execve
 * @dup_line: duplicate of line
 * @tkn_chk: tokens to be checked
 * @av: argument vector
 * @failed_cmds: number of commands that have failed
 *
 * Return: 0 for success
 */

int exe(char *line, char **ar, char *dup_line, char **tkn_chk, char **av,
		int failed_cmds)
{
	int status = 0, onpath = -1;
	pid_t child;
	struct stat *status_buffer;

	status_buffer = malloc(sizeof(struct stat));
	if (stat(ar[0], status_buffer) == -1)
	{
		onpath = find_on_path(ar);
		if (onpath == 0)
		{
			free(status_buffer);
			return (0);
		}
	}
	child = fork();
	if (child == 0)
	{
		if (execve(ar[0], ar, environ) == -1)
		{
			_printf("%s: %d: %s: Not Found\n", av[0], failed_cmds, ar[0]);
			free(status_buffer);
			free_mem(line, ar, dup_line, tkn_chk);
			_exit(-1);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	free(status_buffer);
	if (status == 0)
		errno = 0;
	else if (status == 512)
		errno = 2;
	else if (status == 65280)
		errno = 127;
	return (0);
}
