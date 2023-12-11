#include "shell.h"
#define BUF_SIZE 2048
/**
 * _iscd - findsif the file is cd inbuld
 * @pp: array of pointers and input of users
 * @lloop: loops and counts
 * @vv: arguments in the input
 * @env: copy of  env variables
 * Return: -1  0 and if exist cd in args[0]
 */
int _iscd(char **pp, int lloop, char *vv[], char **env)
{
	char str[] = "cd";
	int ii = 0, ccont = 0, vvalor = -1;

	while (pp[0][ii] != '\0')
	{
		if (ii < 2)
		{
			if (pp[0][ii] == str[ii])
				ccont++;
		}
		ii++;
	}
	if (ii == 2)
		ccont++;

	if (ccont == 3)
	{
		_cd(pp, lloop, vv, env);
		vvalor = 0;
	}
	else if (ccont == 2)
	{
		_put_err(pp, lloop, 3, vv);
		vvalor = 0;
	}
	return (vvalor);
}

/**
 * _cleancd - cleans the buffer
 * @cc: pointer to buffer
 * Return: -1  0 and  cd in args[0]
 */
void _cleancd(char *cc)
{
	int ii;

	for (ii = 0; ii < BUF_SIZE; ii++)
		cc[ii] = 0;
}

/**
 * _fullcd - fill buffer to be pointed
 * @ff: pointer to buffer to be pointed
 * @aaux: pointer to aux in the buffer
 * Return: -1 , 0 and cd if its in args[0]
 */
void _fullcd(char *ff, char *aaux)
{
	int ww;

	for (ww = 0; aaux[ww] != '\0'; ww++)
		ff[ww] = aaux[ww];
	for (; ww < BUF_SIZE; ww++)
		ff[ww] = 0;
}
/**
 * _cd - Changes the  directory
 * @aa: input of user
 * @lloop: counts the loops
 * @vv: args in the  input
 * @env: copy of env vars
 * Return:-1 and 0 if success
 */
void _cd(char **aa, int lloop, char *vv[], char **env)
{
	int vvalor = 0, zz = 0;
	static char bbuf[BUF_SIZE];
	static int ww = 1;
	char *hhome, aaux[BUF_SIZE] = {0};

	currentstatus(&zz);
	if (ww == 1)
	{ hhome = _gethome(env);
		if (!hhome)
			getcwd(hhome, BUF_SIZE);
		_updateoldpwd(getcwd(bbuf, BUF_SIZE), env);
		_fullcd(bbuf, _gethome(env));
		ww++;
	}
	if (aa[1] == NULL)
	{
		_cleancd(bbuf);
		getcwd(bbuf, BUF_SIZE);
		_updateoldpwd(bbuf, env);
		vvalor = chdir((const char *)_gethome(env));
		_updatepwd(_gethome(env), env);
	}
	else if (aa[1][0] == '-' && aa[1][1] == '\0')
	{
		_cleancd(aaux), getcwd(aaux, BUF_SIZE);
		_updateoldpwd(aaux, env);
		write(STDOUT_FILENO, bbuf, BUF_SIZE);
		write(STDOUT_FILENO, "\n", 1);
		vvalor = chdir((const char *) bbuf);
		_updatepwd(bbuf, env), _fullcd(bbuf, aaux);
	}
	else
	{
		_cleancd(bbuf), getcwd(bbuf, BUF_SIZE);
		_updateoldpwd(bbuf, env);
		vvalor = chdir((const char *)aa[1]);
		_updatepwd(aa[1], env);
	}
	if (vvalor == -1)
		_put_err(aa, lloop, 1, vv);
}

