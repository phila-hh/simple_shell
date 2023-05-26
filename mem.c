#include "main.h"

/**
 * bfree - function that frees a pointer
 * @ptr: pointer to be freed
 *
 * Return: 1 on success, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
