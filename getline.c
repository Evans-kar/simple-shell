#include "shell.h"
/**
 * salida3 - normal output
 * @mm: it the copy of the enviroment vars
 * @ee: total number of m
 */
void salida3(char **mm, int ee)
{
	free_grid(mm, ee);
	exit(currentstatus(NULL));
}
/**
 *salida2 - out puts with the ctr
 *@mm: copy of env varss
 *@ee: number of elements in m
 *@lline: total inputs from the users
 */
void salida2(char **mm, int ee, char *lline)
{
	free(lline);
	free_grid(mm, ee);
	write(STDIN_FILENO, "#cisfun$ ", 9);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}
/**
 * salida1 - outputs  the normal output
 * @mm: it the copy of the enviroment vars
 * @ee: total number of m
 */

void salida1(char **mm, int ee)
{
	free_grid(mm, ee);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}
/**
 * _getline - fun that reads user input
 * @aa: ptr to loop counter
 * @ee: length of m
 * @mm: copy of environmental
 * Return: NULL.
 */
char  *_getline(int *aa, char **mm, int ee)
{
	char lletter[1] = {0}, *lline = NULL;
	size_t bbufsize = 0;
	static int nnum = 1;

	if (nnum == 2)
	salida2(mm, ee, lline);
	for (; (nnum != 0); bbufsize = 0, free(lline))
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		*aa = *aa + 1;
		signal(SIGINT, _signal);
		for (; ((nnum = read(STDIN_FILENO, lletter, 1)) > 0); bbufsize++)
		{
			if (bbufsize == 0)
				lline = _calloc(bbufsize + 3, sizeof(char));
			else
				lline = _realloc(lline, bbufsize, bbufsize + 3);
			if (!lline)
			{
				nnum = 0;
				break;
			}
			lline[bbufsize] = lletter[0], lline[bbufsize + 1] = '\n';
			lline[bbufsize + 2] = '\0';
			if (lline[bbufsize] == '\n')
				break;
		}
		if (nnum == 0 && bbufsize == 0)
			break;
		else if (nnum == 0 && bbufsize != 0)
		{
			nnum = 2;
			break;
		}
		else if (lline[0] != '\n')
			return (lline);
	}
	if (nnum == 0)
		salida1(mm, ee);
	return (lline);
}
/**
 * _getlineav - reads what the user input;
 * @aa: ptr  to loop counter
 * @ee: length of enviromen varialble
 * @mm: copy of environmental varialbles
 * @av: arguments in input from the user
 * Return: line  otherwise NULL.
 */
char  *_getlineav(int *aa, char **mm, int ee, char **av)
{
	char lletter[1] = {0}, *lli = NULL;
	size_t bbz = 0;
	static unsigned int nnum = 1;
	static int  ffd;

	for (; (nnum != 0); bbz = 0, free(lli))
	{
		ffd = open(av[1], O_RDONLY);
		if (ffd == -1)
		{ close(ffd), free_grid(mm, ee);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": 0: ", 5);
			write(STDERR_FILENO, "Can't open ", 11);
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1), exit(127);
		}
		*aa = *aa + 1;
		while ((nnum = read(ffd, lletter, 1)) > 0)
		{
			if (bbz == 0)
				lli = _calloc(bbz + 3, sizeof(char));
			else
				lli = _realloc(lli, bbz, bbz + 3);
			if (!lli)
			{
				nnum = 0;
				break;
			}
			lli[bbz] = lletter[0], lli[bbz + 1] = '\n';
			lli[bbz + 2] = '\0', bbz++;
		}
		if (nnum == 0 && bbz == 0)
			break;
		else if (lli[0] != '\n')
			return (lli);
	}
	if (nnum == 0)
		close(ffd), salida3(mm, ee);
	return (lli);
}

