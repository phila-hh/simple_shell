#include "shell.h"

/**
 * _puts - writes string to standard output
 * @str: string
 *
 * Return: void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}


/**
 * print_string - prints strings from args
 * @args: pointer to list of arguments
 *
 * Return: number of printed characters
 */

int print_string(va_list *args)
{
	int count;
	char *ar;

	ar = va_arg(*args, char *);
	count = 0;
	while (*ar != '\0')
	{
		_putchar(*ar);
		count++;
		ar++;
	}

	return (count);
}


/**
 * print_digit - prints digits
 * @args: pointer to list of arguments
 *
 * Return: number of printed digits
 */

int print_digit(va_list *args)
{
	int count = 0;
	int n = va_arg(*args, int);
	int i = n;
	int ld = 1;

	if (i < 0)
		i *= -1;

	while (i > 0)
	{
		i /= 10;
		count++;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		ld = n % 10;
		n = n / -10;
	}
	else if (n == 0)
	{
		_putchar('0');
		return (count);
	}
	get_digits(n);
	if (ld < 0)
	{
		_putchar('0' - ld);
	}

	return (count);
}


/**
 * get_digits - get digits
 * @n: number input
 *
 * Return: void
 */

void get_digits(int n)
{
	if (n > 0)
	{
		get_digits(n / 10);
	}
	if (n != 0)
	{
		_putchar('0' + (n % 10));
	}
}


/**
 * _putchar - prints character
 * @c: character to be printed
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
