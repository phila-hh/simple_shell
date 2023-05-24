#include "shell.h"

/**
 * execute_path - function to access PATH
 * @p: directory in path to access
 * @tokens: array of tokens to check for
 *
 * Return: void
 */

void execute_path(char *p, char **tokens)
{
	int status = 0, len1, len2;
	pid_t child;
	char *new_p = NULL;

	for (len1 = 0; *(p + len1) != '\0'; len1++)
		;
	for (len2 = 0; tokens[0][len2] != '\0'; len2++)
		;
	new_p = malloc(sizeof(char) * (len1 + len2 + 2));
	_strcpy(new_p, p);
	_strcat(new_p, "/");
	_strcat(new_p, tokens[0]);
	new_p[(len1 + len2 + 1)] = '\0';

	child = fork();
	if (child == 0)
	{
		if (access(new_p, X_OK) == 0)
		{
			execve(new_p, tokens, environ);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	if (status == 0)
	{
		errno = 0;
	}
	free(new_p);
}


/**
 * find_on_path - find PATH in environ
 * @tokens: token to pass along to PATH
 *
 * Return: 0 on success
 */

int find_on_path(char **tokens)
{
	int i, onpath = 0;
	char *p = NULL, *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = _strdup(environ[i]);
			strtok(path, "=");
			p = strtok(NULL, "=");
			onpath = search_path(p, tokens);
			break;
		}
	}
	free(path);

	return (onpath);
}


/**
 * search_path - search PATH
 * @p: part of PATH to search in
 * @tokens: array of tokens
 *
 * Return: 0 on success
 */

int search_path(char *p, char **tokens)
{
	struct dirent *d;
	int found = 0, onpath = -1;

	p = strtok(p, ":");
	while (p != NULL && found != 1)
	{
		DIR *dr = opendir(p);

		if (dr == NULL)
		{
			return (0);
		}

		while ((d = readdir(dr)) != NULL)
		{
			if (_strcmp(d->d_name, tokens[0]) == 0)
			{
				execute_path(p, tokens);
				onpath = 0;
				found = 1;
				break;
			}
		}
		closedir(dr);
		if (found == 0)
		{
			p = strtok(NULL, ":");
		}
	}
	return (onpath);
}
