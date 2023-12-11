#include "shell.h"
/**
 * _isenv - finds if the input is env
 * @ptr: pointers array
 * @env: env copy
 * Return: -1 on  failure or 0 on success
 */
int _isenv(char **ptr, char **env)
{
	char str[4] = "env";
	int ii = 0, jj = 0, ccont = 0;

	while (ptr[0][jj] != '\0')
		jj++;
	if (jj == 3)
	{
		while (ii < 3)
		{
			if (ptr[0][ii] == str[ii])
				ccont++;
			ii++;
		}
		if (ccont == 3)
		{
			_env(env);
			return (0);
		}
	}
	return (-1);
}
/**
 * create_env - create a copy of env
 * @env: env
 * Return: arr of ptr to store elements of env
 */
char **create_env(char *env[])
{
	int ii, jj = 0, cc = 0;
	static char **myenv;

	for (ii = 0; env[ii] != NULL; ii++)
		;
	myenv = _calloc(ii + 1, sizeof(char *));
	if (!myenv)
		return (NULL);
	while (env[jj] != NULL)
	{
		cc = 0;
		while (env[jj][cc] != '\0')
			cc++;
		myenv[jj] = _calloc(cc + 1, sizeof(char));
		if (myenv[jj] == NULL)
		{
			free_grid(myenv, jj);
			return (NULL);
		}
		for (ii = 0; ii < cc; ii++)
			myenv[jj][ii] = env[jj][ii];
		jj++;
	}
	myenv[jj] = NULL;
	return (myenv);
}
/**
 * _env - prints environment var
 * @env: copy of environmental variables
 */
void _env(char **env)
{
	int ii;

	for (ii = 0; env[ii] != NULL; ii++)
	{
		write(STDOUT_FILENO, env[ii], _strlen(env[ii]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

