#include "shell.h"
#include <unistd.h>
#include <string.h>
#define STDOUT_FILENO 1
/**
 * main - this is the loop on how the shell will work
 * Return: 0 (success)
 */
int main(void)
{
	const char *prompt = "$ ";

	do {
		write(STDOUT_FILENO, promp, strlen(prompt));
		mygetline();
		parse();
	}
	while (1);

	return (0);
}
