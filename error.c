#include "main.h"

/**
 * _eputs - prints a string input
 * @str: string input to be printed
 *
 * Return: void
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
	{
		return;
	}

	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}


/**
 * _eputchar - function that writes character c to stderr
 * @c: character input to be printed
 *
 * Return: 1 on success, -1 otherwise
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}


/**
 * _putfd - writes the character c to given file descriptor
 * @c: character input to be printed
 * @fd: filedescriptor to write character c to
 *
 * Return: 1 on success, -1 otherwise
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}


/**
 * _putsfd - function that prints an input string to file descriptor
 * @str: string input to be printed
 * @fd: filedescriptor to write the string to
 *
 * Return: number of characters printed
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
	{
		return (0);
	}

	while (*str)
	{
		i += _putfd(*str++, fd);
	}

	return (i);
}
