#include "shell.h"
/**
 * _put_err - Prints an error
 * @ptr: pointer
 * @lp: number of loops
 * @sg: signal
 * @vv: input args
 * Return: Null.
 */
void _put_err(char **ptr, int lp, int sg, char *vv[])
{
	static int pr = 1;


	if (sg == 0)
		pr = 0;
	pr++;
	if (sg == 3)
		pr = 3;
	if (sg == 4)
		pr = 4;
	if (sg == 5)
		pr = 5;
	if (pr == 2 || (pr == 3 && sg == 3) || (pr == 4 && sg == 4)
	    || (pr == 5 && sg == 5))
	{
		write(STDERR_FILENO, vv[0], _strlen(vv[0]));
		write(STDERR_FILENO, ": ", 2);
		print_number(lp);
		write(STDERR_FILENO, ": ", 2);
	}
	if (pr == 2)
		_builtinerr(ptr);
	else if (pr == 3 && sg == 3)
	{
		_errorgarbage(ptr);
		pr = 1;
	}
	else if (pr == 4 && sg == 4)
	{
		write(STDERR_FILENO, ptr[0], _strlen(ptr[0]));
		write(STDERR_FILENO, ": Permission denied\n", 20);
	}
	else if (pr == 5 && sg == 5)
		_builtinerr2(ptr);
}

/**
 * _builtinerr - Prints an error message
 * @ptr: pointer to the input
 * Return: null.
 */
void _builtinerr(char **ptr)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int ii = 0, jj = 0, ccont = 0, ccont2 = 0;

	while (ptr[0][jj] != '\0')
		jj++;
	if (jj == 2)
	{
		for (; ii < 2; ii++)
			if (ptr[0][ii] == str1[ii])
				ccont++;
		if (ccont == 2)
			_errorcd(ptr);
	}
	if (jj == 4)
	{
		for (ii = 0 ; ii < 4; ii++)
			if (ptr[0][ii] == str2[ii])
				ccont++;
		if (ccont == 4)
			_errorexit(ptr);
		for (ii = 0; ii < 4; ii++)
			if (ptr[0][ii] == str3[ii])
				ccont2++;
		if (ccont2 == 4)
			_errorhelp(ptr);
	}
}
/**
 * _builtinerr2 - prints an error
 * @ptr: Pointer to the input
 * Return: null.
 */
void _builtinerr2(char **ptr)
{
	char str1[9] = "unsetenv", str2[7] = "setenv";
	int ii = 0, jj = 0, ccont = 0;

	while (ptr[0][jj] != '\0')
		jj++;
	if (jj == 8)
	{
		for (; ii < 8; ii++)
			if (ptr[0][ii] == str1[ii])
				ccont++;
		if (ccont == 8)
			_errorenv(ptr);
	}
	if (jj == 6)
	{
		for (; ii < 6; ii++)
			if (ptr[0][ii] == str2[ii])
				ccont++;
		if (ccont == 6)
			_errorenv(ptr);
	}
}
