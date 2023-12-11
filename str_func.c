#include "shell.h"

/**
 * str_concat - Create an array
 * @ar1: Array 1
 * @ar2: Array 2
 * Return: A pointer
 */
char *str_concat(char *ar1, char *ar2)
{
	char *pp;
	unsigned int a = 0, b = 0, f, d = 0;

	if (ar1 == NULL)
	{
		ar1 = "";
	}
	if (ar2 == NULL)
	{
		ar2 = "";
	}
	while (*(ar1 + a) != '\0')
	{
		a++;
	}
	while (ar2[b])
	{
		b++;
	}
	pp = _calloc(a + b + 1, sizeof(char));
	if (!pp)
	{
		return (NULL);
	}
	else
	{
		for (f = 0; f < a; f++)
		{
			pp[f] = ar1[f];
		}
		for (f = a; f <= (a + b); f++, d++)
		{
			pp[f] = ar2[d];
		}
		return (pp);
	}
}

/**
 * _strlen - Finds the length of a string
 * @str: String in question
 * Return: 0.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

