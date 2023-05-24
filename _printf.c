#include "shell.h"

/**
 * _printf - prints string with formatted variables
 * @format: string to format and print
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	int i, chk, char_count;
	va_list args;
	fmt_check fmtspec[] = {
		{"%", check_format},
		{"\\", check_format},
		{NULL, NULL}
	};

	va_start(args, format);
	i = 0;
	chk = 0;
	char_count = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == *(fmtspec[0].ltr))
		{
			chk += fmtspec[0].type(&args, format, i);
			if (chk == -1)
			{
				return (-1);
			}
			char_count += chk;
			i++;
			while (format[i] == ' ')
			{
				i++;
			}
			chk = 1;
		}
		if (chk == 0)
		{
			_putchar(format[i]);
			char_count++;
		}
		chk = 0;
		i++;
	}
	va_end(args);

	return (char_count);
}


/**
 * check_format - checks format modifier
 * @args: pointer to list of arguments
 * @format: string
 * @i: index of the modifier
 *
 * Return: number of printed characters
 */

int check_format(va_list *args, const char *format, int i)
{
	int j, count;
	fmt fmtmods[] = {
		{"s", print_string},
		{"i", print_digit},
		{"d", print_digit},
		{NULL, NULL}
	};

	j = 0;
	count = 0;
	i++;
	if (format[i] == ' ')
	{
		while (format[i] == ' ')
			i++;
	}
	if (format[i] == '%')
	{
		_putchar('%');
		return (1);
	}
	if (format[i] == 'n')
	{
		_putchar('\n');
		return (1);
	}

	while (fmtmods[j].type != NULL && *(fmtmods[j].ltr) != format[i])
		j++;
	if (fmtmods[j].type == NULL)
		return (-1);
	count = fmtmods[j].type(args);
	return (count);
}
