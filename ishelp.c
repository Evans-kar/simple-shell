#include "shell.h"
/**
 * _ishelp -  help builtin finstio
 * @pp: pointer to input
 * @lloop: count loops
 * @vv: args in  the input
 * @mm: copy of env variables
 * Return: 0 if exist -1 if not.
 */
int _ishelp(char **pp, int lloop, char *vv[], char **mm)
{
	char str[] = "help";
	int ii = 0, ccont = 0, ssalida = -1;

	while (pp[0][ii])
	{
		if (ii < 4)
		{
			if (pp[0][ii] == str[ii])
				ccont++;
		}
		ii++;
	}
	if (ii == 4)
		ccont++;

	if (ccont == 5)
	{
		_help(pp, lloop, vv, mm);
		ssalida = 0;
	}
	return (ssalida);
}
/**
 * _help_builtin - Built in help
 * @pp: input pointer
 * @lp: Number of loops
 * @vv: Input arguments
 * @mm: copy of env
 * Return: null.
 */
void _help_builtin(char **pp, int lp, char *vv[], char **mm)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0, cont2 = 0, k = 1;

	while (pp[k] != NULL)
	{
		j = 0;
		cont = 0, cont2 = 0;
		while (pp[k][j] != '\0')
			j++;
		if (j == 2)
		{
			for (i = 0; i < 2; i++)
				if (pp[k][i] == str1[i])
					cont++;
			if (cont == 2)
				read_cdhelp(mm);
			else
				_put_err(pp, lp, 1, vv);
		}
		else if (j == 4)
		{
			for (i = 0 ; i < 4; i++)
				if (pp[k][i] == str2[i])
					cont++;
			if (cont == 4)
				read_exithelp(mm);
			for (i = 0 ; i < 4; i++)
				if (pp[k][i] == str3[i])
					cont2++;
			if (cont2 == 4)
				read_helphelp(mm);
			else if (cont != 4 && cont2 != 4)
				_put_err(pp, lp, 1, vv);
		}
		else
			_put_err(pp, lp, 1, vv);
		k++;
	}
}
/**
* _help- write an error messege
* @pp: input pointer
* @lp: Number of loops
* @vv: Input arguments
* @mm: copy of env
* Return: null
*/
void _help(char **pp, int lp, char *vv[], char **mm)
{
	if (pp[0] != NULL && pp[1] == NULL)
	{
		read_help(mm);
	}
	else
	{
		_help_builtin(pp, lp, vv, mm);
	}
}
