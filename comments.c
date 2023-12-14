#include "shell.h"

/**
 * semicolon - search if in the input has ";" or a ";;"
 * @ln: Complete the user input
 * @lp: Loop counter
 * @arg: Argument string array
 * Return: 1 upon success 0 on faulure
 */
int semicolon(char *ln, int lp, char **arg)
{
	int valid = 0, cont = 0;

	while (ln[cont] != '\0')
	{
		if (ln[0] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, arg[0], _strlen(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(lp);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";", 1);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		if (ln[cont] == ';' && ln[cont + 1] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, arg[0], _strlen(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(lp);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";;", 2);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		cont++;
	}
	return (valid);
}
/**
 *_comments - remove comments
 *@ln: User input
 * Return: input
 */
char *_comments(char *ln)
{
	int aa = 0, cc = 0, flag = 0;

	while (ln[cc] != '\0')
		cc++;
	while (ln[aa] != '\0')
	{
		if (ln[0] == '#')
		{
			flag = 1;
			break;
		}
		if (ln[aa] == '#' && ln[aa - 1] == ' ')
		{
			flag = 1;
			break;
		}
		aa++;
	}
	if (flag == 1)
	{
		for (; aa < cc; aa++)
			ln[aa] = 0;
	}
	return (ln);
}

