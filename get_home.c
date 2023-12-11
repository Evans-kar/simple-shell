#include "shell.h"

/**
 * _gethome -  gets envenviroment HOME
 * @mm: copy of env variables
 *Return: string inside  HOME env variable
 */
char *_gethome(char **mm)
{
	int ii, jj, kk, ccont = 0;
	char str[] = "HOME=";
	char *hhome = NULL;

	for (ii = 0; mm[ii] != NULL; ii++)
	{
		for (jj = 0; mm[ii][jj] != '\0'; jj++)
		{
			if (ccont == 5)
				break;
			if (mm[ii][jj] == str[jj])
				ccont++;
			else
				break;
		}
		if (ccont == 5)
			break;
	}
	if (ccont == 5)
	{
		hhome = mm[ii];
		for (kk = 0; kk < 5; kk++)
		{
			hhome++;
		}
	}
	return (hhome);
}
