#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to be concatenated to
 * @src: string to concatenate from
 *
 * Return: a pointer to dest string
 */

char *_strcat(char *dest, char *src)
{
	int i, len1, len2;

	len1 = 0;
	len2 = 0;
	while (*(dest + len1) != '\0')
	{
		len1++;
	}
	while (*(src + len2) != '\0')
	{
		len2++;
	}

	for (i = 0; i <= len2; i++)
	{
		*(dest + (len1 + i)) = *(src + i);
	}
	return (dest);
}


/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second stirng
 *
 * Return: 0 on success, -1 if it fails
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			return (-1);
		}
	}

	return (0);
}


/**
 * _strncmp - compares two strings to a certain point
 * @s1: first string
 * @s2: second string
 * @len: length to be compared
 *
 * Return: 0 on success, -1 if it fails
 */

int _strncmp(char *s1, char *s2, int len)
{
	for (; *s1 && *s2 && len >= 0; len--)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			return (-1);
		}
	}

	return (0);
}


/**
 * _strcpy - copies string from src to dest
 * @dest: string to be copied to
 * @src: string to copy from
 *
 * Return: a pointer to dest string
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	while (*(src + len) != '\0')
	{
		len++;
	}

	for (i = 0; i <= len; i++)
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}


/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: a pointer to the duplicate string
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int i, size;

	if (str == NULL)
	{
		return (NULL);
	}

	for (size = 0; *(str + size) != '\0';)
	{
		size++;
	}

	dup = malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);
}
