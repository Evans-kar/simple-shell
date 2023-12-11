#include "shell.h"
#include <unistd.h>
#include <stdio.h>
/**
 * mygetline - gets user input from the stdin
 */
char *mygetline(void)
{
	char *store = NULL;
	size_t n = 0;
	ssize_t rchar;

	/*Reads input from stdin and store it in the rchar*/
	rchar = getline(&store, &n, stdin);

	/*Checks if user input in rchar is EOF or it failed*/
	if (rchar == -1)
	{
		perror("Error: exiting shell\n");
		free(store);
		exit(0);
	}

	/*Checks if the last char in string is a newline char */
	if (store[rchar - 1] == '\n')
	{
		store[rchar - 1] = '\0';
	}
	return (store);
}
