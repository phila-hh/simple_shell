#include "main.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string input
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: comparison result
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - function that checks if needle starts with haystack
 * @haystack: string to search in
 * @needle: substring to search for
 *
 * Return: address of next character in haystack, otherwise NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - function that concatenates two strings
 * @dest: pointer to destination buffer
 * @src: pointer to source buffer
 *
 * Return: pointer to concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
