#include "shell.h"
#include <limits.h>
/**
 *_type - Receive the type of exit
 * @pp: User's input
 * @LL: Loop counter
 * @ll: input user
 * @ii: Pointer counter
 * @vv: arguments in input
 * @mm: copy of environmental variables
 * @ee: number of elements in m
 * @ff: input complete
 */
void _type(char **pp, int LL, char *ll,
		int ii, char **vv, char **mm, int ee, char *ff)
{
	unsigned int  c = 0, flag = 0;
	long int valor = 0;

	if (pp[1] == NULL || (pp[1][0] == '0' && pp[1][1] == '\0'))
	{
		free(ll), free(ff), free_grid(pp, ii), free_grid(mm, ee);
		exit(currentstatus(NULL));
	}
	else
	{
		while (pp[1][c] != '\0')
		{
			if ((pp[1][0] != '+' && pp[1][0] != '-') &&
			    (pp[1][c] < 48 || pp[1][c] > 57))
			{
				flag = 1;
				break;
			}
			c++;
		}
		if (flag == 1)
			_put_err(pp, LL, 1, vv);
		else
		{ valor = _atoi(pp[1]);
			if (!(valor > INT_MAX) && valor > 0)
			{
				valor = valor % 256;
				free(ll), free(ff), free_grid(pp, ii);
				free_grid(mm, ee), exit(valor);
			}
			else if (valor < 0)
			{
				_put_err(pp, LL, 1, vv);
				free(ll), free(ff), free_grid(pp, ii);
				free_grid(mm, ee), exit(2);
			}
			else
				_put_err(pp, LL, 1, vv);
		}
	}
}
/**
  * _isexit - finds if line input is exit therefore process termination
  * @pp: User's input
  * @LL: Loop counter
  * @ll: input user
  * @vv: arguments in input
  * @mm: copy of environmental variables
  * @ff: input complete
  * Return: The exit status
  */
int _isexit(char **pp, int LL, char *ll, char **vv, char **mm, char *ff)
{
	char str[] = "exit";
	int i, cont = 0, salida = -1, x = 0, e = 0;

	for (x = 0; pp[x] != NULL; x++)
		;
	for (e = 0; mm[e] != NULL; e++)
		;
	i = 0;
	while (pp[0][i] != '\0')
	{
		if (i < 4)
		{
			if (pp[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 4)
		cont++;

	if (cont == 5)
	{
		_type(pp, LL, ll, x, vv, mm, e, ff);
		salida = 0;
	}
	else if (cont == 4)
	{
		salida = 0;
		_put_err(pp, LL, 3, vv);
	}
	return (salida);
}

