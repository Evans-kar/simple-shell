#include "shell.h"
/**
 *rev - checks if the input is env or not
 *@pp: Array of inputs from user
 *@LL: Counts the number of loops
 *@vv: User input
 *@mm: Input arguments
 *@ee: Env copy
 *@ff: number of Env copies
 *@lli: All inputs
 * Return: -1 or 0
 */
int rev(char **pp, int LL, char *lli, char **vv, char ***mm, int *ee, char *ff)
{
	int AAvalenv = 0, BBvalcd = 0, CCother = -1, DDvalex = 0, EEvalhel = 0;
	int FFvalunset = 0, GGvalset = 0;

	FFvalunset = _isunsetenv(pp, *mm, ee, LL, vv);
	if (FFvalunset == 0)
		return (FFvalunset);
	GGvalset = _issetenv(pp, mm, ee, LL, vv);
	if (GGvalset == 0)
	return (GGvalset);
	DDvalex = _isexit(pp, LL, lli, vv, *mm, ff);
	if (DDvalex == 0)
		return (DDvalex);
	EEvalhel = _ishelp(pp, LL, vv, *mm);
	if (EEvalhel == 0)
		return (EEvalhel);
	AAvalenv = _isenv(pp, *mm);
	BBvalcd = _iscd(pp, LL, vv, *mm);
	if (AAvalenv == 0)
		return (AAvalenv);
	if (BBvalcd == 0)
		return (BBvalcd);
	return (CCother);
}
/**
 * functions - Identify functions
 *@lline: input from user
 *@lloop: loop count
 *@aargv: args from user
 *@mm: env copy
 *@ee: count of elements in cp
 *@ff: complete input of user
 */
void functions(char *lline, int lloop,
		char *aargv[], char ***mm, int *ee, char *ff)
{
	char **aargs = NULL;
	int vvalue = 1, ii = 0;

	lline = _comments(lline);
	aargs = parsing(lline);
	if (aargs)
	{
		for (ii = 0; aargs[ii] != NULL; ii++)
			;
		vvalue = rev(aargs, lloop, lline, aargv, mm, ee, ff);
		if (vvalue != 0)
		{
			aargs = checkbin(aargs, *mm);
			if (aargs)
				_frk(aargs, lline, ii, lloop, aargv, *ee, *mm, ff);
		}
		free_grid(aargs, ii);
		free(lline);
	}
	else
	{
		free(lline);
		fflush(STDIN_FILENO);
	}
	_put_err(aargs, lloop, 0, aargv);
}
/**
 * _noargv - shell form without filename at input
 * @aargv: args found from  in the input
 * @eenvp: env variables
 */
void _noargv(char *aargv[], char *eenvp[])
{
	char *lline = NULL, **mm = NULL, *pp = NULL, *ppr1 = NULL;
	int ee = 0, *pploop, ii = 0, ssem = 0;
	static int lloop;

	lloop = 0;
	pploop = &lloop;
	while (1)
	{
		if (lloop == 0)
		{
			mm = create_env(eenvp);
			for (ee = 0; mm[ee] != NULL; ee++)
				;
		}
		lline = _getline(pploop, mm, ee);
		ssem = semicolon(lline, lloop, aargv);
		if (!(ssem == 1))
		{
			pp = _strtoky2(lline, ";\n");
			while (pp)
			{
				ppr1 = _calloc(_strlen(pp) + 2, sizeof(char));
				for (ii = 0; pp[ii] != '\0'; ii++)
					ppr1[ii] = pp[ii];
				ppr1[ii] = '\n';
				ppr1[ii + 1] = '\0';
				functions(ppr1, lloop, aargv, &mm, &ee, lline);
				pp = _strtoky2(NULL, ";\n");
			}
		}
		free(lline);
	}
}
