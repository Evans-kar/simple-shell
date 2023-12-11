#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * mygetline - gets users input from stdin
 * Return: user input in the buffer
 */
char *mygetline(void)
{
	char *store = NULL;
	size_t n = 0;
	ssize_t rchar;

	rchar = getline(&store, &n, stdin);

	if (rchar == -1)
	{
		perror("Error: exiting the shell\n");
		free(store);
		exit(1);
	}
	if (store[rchar - 1] == '\n')
	{
		store[rchar -1] = '\0';
	}
	return store;
}
/**
 * parse - splits a string using delimiters
 * @str: string to split
 * Return: an array of parsed string
 */
char **parse(char *str, const char *delim)
{
	char **arrays = NULL;
	char *token;
	int iterator = 0;

	delim = "\n\t\r";
	
	arrays = malloc(sizeof(char *) * BUFFER_SIZE);
	if (arrays == NULL)
	{
		perror("Error allocating memory");
		exit(1);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		arrays[iterator] = strdup(token);
		if (arrays[iterator] == NULL)
		{
			perror("Error allocating memory");
			exit(1);
		}
		iterator++;
		token = strtok(NULL, delim);
	}
	arrays[iterator] = NULL;

	return arrays;
}
/**
 * main - this is the loop on how the shell will work
 * Return: 0 (success)
 */
int main(void)
{
    const char *prompt = "$ ";
    char *input;
    char **arrays;
    pid_t child_pid;
    int status;

    do
    {
        write(STDOUT_FILENO, prompt, strlen(prompt));
        input = mygetline();
        arrays = parse(input, NULL);

        if (arrays[0] == NULL)
        {
            // Free memory and continue if the input is empty
            free(input);
            free(arrays);
            continue;
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error creating child process");
            exit(1);
        }
        if (child_pid == 0)
        {
            // In the child process, execute the command
            if (execvp(arrays[0], arrays) == -1)
            {
                perror("Error executing command");
                exit(1);
            }
        }
        else
        {
            // In the parent process, wait for the child to finish
            waitpid(child_pid, &status, 0);

            // Free memory
            free(input);
            for (int i = 0; arrays[i] != NULL; i++)
            {
                free(arrays[i]);
            }
            free(arrays);
        }
    } while (1);

    return 0;
}
