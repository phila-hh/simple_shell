#include "main.h"

/**
 * interactive - checks whether or not the shell is in interactive mode
 * @info: pointer to struct info_t
 *
 * Return: 1 if shell is in interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - checks whether or not a character is a delimeter
 * @c: character to be checked
 * @delim: the delimeter string
 *
 * Return: 1 if it is a delimeter, 0 otherwise
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);
		}
	}

	return (0);
}


/**
 * _isalpha - checks if a character is in the alphabet
 * @c: input character to be checked
 *
 * Return: 1 if true, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
 * _atoi - converts string to integer
 * @s: string to be converted
 *
 * Return: 0 if failure, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}

	if (sign == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}

	return (output);
}
