#include "shell.h"
/**
 * _issetenv - cheks if the line input is setenv
 * @iu: input form user
 * @env: Environment variables duplicate
 * @lp: Numbeer of loops
 * @ag: Input agruments
 * @en: Element count in _env
 * Return: -1 if fails or 0 if success
 */
int _issetenv(char **iu, char ***env, int *en, int lp, char *ag[])
{
	char str[] = "setenv";
	int AAi = 0, BBcont = 0, CCsalida = -1;

	AAi = 0;
	while (iu[0][AAi] != '\0')
	{
		if (AAi < 6)
		{
			if (iu[0][AAi] == str[AAi])
				BBcont++;
		}
		AAi++;
	}
	if (AAi == 6)
		BBcont++;
	if (BBcont == 7)
	{
		if (iu[1] != NULL && iu[2] != NULL)
			_setenv(iu, env, en, lp, ag);
		else
			_put_err(iu, lp, 5, ag);
		CCsalida = 0;
		currentstatus(&CCsalida);
	}
	else if (BBcont == 6)
	{
		CCsalida = 0;
		_put_err(iu, lp, 3, ag);
		currentstatus(&CCsalida);
	}
	return (CCsalida);
}
/**
 * _setenv - sets input line
 * @iu: input form user
 * @env: Environment variables duplicate
 * @lp: Numbeer of loops
 * @ag: Input agruments
 * @en: Element count in _env
 * Return: void
 */
void _setenv(char **iu, char ***env, int *en, int lp, char *ag[])
{
	int i, lg, j, k = 0, cont = 0, p2len = 0, myenvlen = 0;
	char *entirenv, *withequal;

	lg = _strlen(iu[1]);
	withequal = str_concat(iu[1], "=");
	entirenv = str_concat(withequal, iu[2]);
	for (i = 0; (*env)[i] != NULL; i++, cont = 0)
	{
		for (j = 0; iu[1][j] != '\0' && j < lg; j++)
		{
			if (iu[1][j] == (*env)[i][j])
				cont++;
		}
		if (cont == lg)
			break;
	}
	if (cont == lg)
	{
		myenvlen = _strlen((*env)[i]), p2len = _strlen(iu[2]);
		if (p2len < myenvlen)
		{
			for (k = 0; entirenv[k] != '\0'; k++)
				(*env)[i][k] = entirenv[k];
			for (; k < myenvlen; k++)
				(*env)[i][k] = 0;
		}
		else
		{
			(*env)[i] = _realloc((*env)[i], myenvlen, _strlen(entirenv));
			for (k = 0; entirenv[k] != '\0'; k++)
				(*env)[i][k] = entirenv[k];
		} free(withequal), free(entirenv), *en = *en;
	}
	else if (cont != lg && iu[1] != NULL && iu[2] != NULL)
	{
		_setenvcreat(env, en, entirenv);
		free(withequal), free(entirenv);
	}
	else
		_put_err(iu, lp, 5, ag);
}
/**
 * _setenvcreat - function to add or modify the env string
 * @env: the copy of the  env
 * @en: number of elements in em
 * @AAentirenv: concatenate arguments
 */
void _setenvcreat(char ***env, int *en, char *AAentirenv)
{
	int AAi = 0, BBk = 0;
	char **CCnew = NULL;

	CCnew = _calloc(*en + 2, sizeof(char *));
	for (AAi = 0; (*env)[AAi] != NULL; AAi++)
	{
		for (BBk = 0; (*env)[AAi][BBk]; BBk++)
			;
		CCnew[AAi] = _calloc(BBk + 1, sizeof(char));
		for (BBk = 0; (*env)[AAi][BBk] != '\0'; BBk++)
			CCnew[AAi][BBk] = (*env)[AAi][BBk];
	}
	CCnew[AAi] = _calloc(_strlen(AAentirenv) + 1, sizeof(char));
	for (BBk = 0; AAentirenv[BBk] != '\0'; BBk++)
		CCnew[AAi][BBk] = AAentirenv[BBk];
	CCnew[AAi + 1] = NULL;
	*en = *en + 1;
	free_grid((*env), *en);
	(*env) = CCnew;
}
