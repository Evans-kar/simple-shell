#include "shell.h"
/**
 * _sch - Looks for a cheracter
 * @ss: string to be changed
 * @cc: character being looked for
 * Return: 1 on success
 */
int _sch(char *ss, char cc)
{
	int contr = 0;

	while (ss[contr] != '\0')
	{
		if (ss[contr] == cc)
		{
			break;
		}
		contr++;
	}
	if (ss[contr] == cc)
		return (1);
	else
		return (0);
}
/**
 * _strtoky - tokenizes a string
 * @ss: string to tokenize
 * @dd: delimiter
 * Return: The first string
 */
char *_strtoky(char *ss, char *dd)
{
	static char *timo;
	int ii = 0, jj = 0;

	if (!ss)
		ss = timo;
	while (ss[ii] != '\0')
	{
		if (_sch(dd, ss[ii]) == 0 && ss[ii + 1] == '\0')
		{
			timo = ss + ii + 1;
			*timo = '\0';
			ss = ss + jj;
			return (ss);
		}
		else if (_sch(dd, ss[ii]) == 0 && _sch(dd, ss[ii + 1]) == 0)
			ii++;
		else if (_sch(dd, ss[ii]) == 0 && _sch(dd, ss[ii + 1]) == 1)
		{
			timo = ss + ii + 1;
			*timo = '\0';
			timo++;
			ss = ss + jj;
			return (ss);
		}
		else if (_sch(dd, ss[ii]) == 1)
		{
			jj++;
			ii++;
		}
	}
	return (NULL);
}
/**
* _strtoky2 - tokenized with;
* @ss: string to be tokenized
* @dd: delimiter
* Return: first string
*/
char *_strtoky2(char *ss, char *dd)
{
	static char *timo;
	int i = 0, j = 0;

	if (!ss)
		ss = timo;
	while (ss[i] != '\0')
	{
		if (_sch(dd, ss[i]) == 0 && ss[i + 1] == '\0')
			i++;
		else if (_sch(dd, ss[i]) == 0 && _sch(dd, ss[i + 1]) == 0)
			i++;
		else if (_sch(dd, ss[i]) == 0 && _sch(dd, ss[i + 1]) == 1)
		{
			timo = ss + i + 1;
			*timo = '\0';
			timo++;
			ss = ss + j;
			return (ss);
		}
		else if (_sch(dd, ss[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
