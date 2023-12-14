#include "shell.h"
/**
 * _updatepwd - cahnges the pwd of the old variable
 * @buff: points old print working directory
 * @env: copy of envir var
 * Return: the string  env var
 */
void _updatepwd(char *buff, char **env)
{
	char *entirepwd;
	char str[] = "PWD=";
	int i = 0, j = 0, cont = 0, k = 0, nalen = 0, bafflen = 0;

	entirepwd = str_concat(str, buff);
	for (i = 0; env[i] != NULL; i++, cont = 0)
	{
		for (j = 0; env[i][j] != '\0' && j < 4; j++)
		{
			if (env[i][j] == str[j])
			{
				cont++;
			}
			else
				break;
		}
		if (cont == 4)
			break;
	}
	if (cont == 4)
	{
		nalen = _strlen(env[i]);
		bafflen = _strlen(entirepwd);
		if (bafflen < nalen)
		{
			for (k = 0; entirepwd[k] != '\0'; k++)
				env[i][k] = entirepwd[k];
			for (; k < nalen; k++)
				env[i][k] = 0;
		}
		else
		{
			env[i] = _realloc(env[i], nalen, bafflen + 1);
			for (k = 0; entirepwd[k] != '\0'; k++)
				env[i][k] = entirepwd[k];
		}
	}
	free(entirepwd);
}
/**
 * _updateoldpwd - changes OLDPWD enviroment variable
 * @buff: pointer to old print working directory
 * @env: copy of envir vars
 * Return: string in PWD env variable
 */
void _updateoldpwd(char *buff, char **env)
{
	char *entirepwd;
	char str[] = "OLDPWD=";
	int i = 0, j = 0, cont = 0, k = 0, nalen = 0, bafflen = 0;

	entirepwd = str_concat(str, buff);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; env[i][j] != '\0' && j < 7; j++)
		{
			if (env[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 7)
			break;
	}
	if (cont == 7)
	{
		nalen = _strlen(env[i]);
		bafflen = _strlen(entirepwd);
		if (bafflen < nalen)
		{
			for (k = 0; entirepwd[k] != '\0'; k++)
				env[i][k] = entirepwd[k];
			for (; k < nalen; k++)
				env[i][k] = 0;
		}
		else
		{
			env[i] = _realloc(env[i], nalen, bafflen + 1);
			for (k = 0; entirepwd[k] != '\0'; k++)
				env[i][k] = entirepwd[k];
		}
	}
	free(entirepwd);
}
