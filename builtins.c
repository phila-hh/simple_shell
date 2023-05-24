#include "shell.h"

/**
 * check_builtin - checks if the command entered is a built-in
 * @line: user input
 * @ar1: array to be handled by execve
 * @dup_line: duplicate of line
 * @ar2: token to be checked
 *
 * Return: 0 on success
 */

int check_builtin(char *line, char **ar1, char *dup_line, char **ar2)
{
	int i;

	if (_strcmp(ar1[0], "exit") == 0)
	{
		free_mem(line, ar1, dup_line, ar2);
		_exit(errno);
	}
	if (_strcmp(ar1[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			_puts(environ[i]);
			write(1, "\n", 1);
		}
		return (2);
	}
	if (_strcmp(ar1[0], "cd") == 0)
	{
		change_dir(ar1);
		return (2);
	}
	return (0);
}


/**
 * change_dir - changes directory to ar
 * @ar: the directory to change to
 *
 * Return: void
 */

void change_dir(char **ar)
{
	int i;
	char *home_val = NULL, *home = NULL;

	if (ar[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			if (_strncmp("HOME=", environ[i], 5) == 0)
			{
				home = _strdup(environ[i]);
				strtok(home, "=");
				home_val = strtok(NULL, "=");
				break;
			}
		}
	}
	else
	{
		home_val = ar[1];
	}
	chdir(home_val);
	free(home);
}
