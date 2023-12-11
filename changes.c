#include "shell.h"
/**
 * _updatepwd - cahnges the pwd of the old variable
 * @buff: points old print working directory
 * @env: copy of envir var
 * Return: the string  env var
 */
void _updatepwd(char *buff, char **env)
{
	char *eentirepwd;
	char str[] = "PWD=";
	int ii = 0, jj = 0, ccont = 0, kk = 0, nvlen = 0, bufflen = 0;

	eentirepwd = str_concat(str, buff);
	for (ii = 0; env[ii] != NULL; ii++, ccont = 0)
	{
		for (jj = 0; env[ii][jj] != '\0' && jj < 4; jj++)
		{
			if (env[ii][jj] == str[jj])
			{
				ccont++;
			}
			else
				break;
		}
		if (ccont == 4)
			break;
	}
	if (ccont == 4)
	{
		nvlen = _strlen(env[ii]);
		bufflen = _strlen(eentirepwd);
		if (bufflen < nvlen)
		{
			for (kk = 0; eentirepwd[kk] != '\0'; kk++)
				env[ii][kk] = eentirepwd[kk];
			for (; kk < nvlen; kk++)
				env[ii][kk] = 0;
		}
		else
		{
			env[ii] = _realloc(env[ii], nvlen, bufflen + 1);
			for (kk = 0; eentirepwd[kk] != '\0'; kk++)
				env[ii][kk] = eentirepwd[kk];
		}
	}
	free(eentirepwd);
}
/**
 * _updateoldpwd - changes OLDPWD enviroment variable
 * @buff: pointer to old print working directory
 * @env: copy of envir vars
 * Return: string in PWD env variable
 */
void _updateoldpwd(char *buff, char **env)
{
	char *eentirepwd;
	char str[] = "OLDPWD=";
	int ii = 0, jj = 0, ccont = 0, kk = 0, nvlen = 0, bufflen = 0;

	eentirepwd = str_concat(str, buff);
	for (ii = 0; env[ii] != NULL; ii++)
	{
		for (jj = 0; env[ii][jj] != '\0' && jj < 7; jj++)
		{
			if (env[ii][jj] == str[jj])
				ccont++;
			else
				break;
		}
		if (ccont == 7)
			break;
	}
	if (ccont == 7)
	{
		nvlen = _strlen(env[ii]);
		bufflen = _strlen(eentirepwd);
		if (bufflen < nvlen)
		{
			for (kk = 0; eentirepwd[kk] != '\0'; kk++)
				env[ii][kk] = eentirepwd[kk];
			for (; kk < nvlen; kk++)
				env[ii][kk] = 0;
		}
		else
		{
			env[ii] = _realloc(env[ii], nvlen, bufflen + 1);
			for (kk = 0; eentirepwd[kk] != '\0'; kk++)
				env[ii][kk] = eentirepwd[kk];
		}
	}
	free(eentirepwd);
}
