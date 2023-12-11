#include "shell.h"
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
 * parse - splits a string using delimitors
 * @str: string to split
 */
char **parse(char *str)
{
	char **arrays = NULL;
	char *splits;
	int iterator = 0;
	const char *delim = "\n";

	arrays = malloc(sizeof(char *) * BUFFER_SIZE);
	splits = strtok(str,delim);
	iterator = 0;

	while (splits != NULL)
	{
		splits = strtok(NULL, delim);
		iterator+=1;
	}
	iterator+=1;

	arrays[iterator] = splits;
	arrays[iterator] = NULL;

	return (arrays);
}
