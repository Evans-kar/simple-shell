#include "shell.h"
#define BUF_SIZE 2048
/**
 * _iscd - findsif the file is cd inbuld
 * @p: array of pointers and input of users
 * @loop: loops and counts
 * @v: arguments in the input
 * @env: copy of  env variables
 * Return: -1  0 and if exist cd in args[0]
 */
int _iscd(char **p, int loop, char *v[], char **env)
{
	char str[] = "cd";
	int i = 0, cont = 0, valor = -1;

	while (p[0][i] != '\0')
	{
		if (i < 2)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 2)
		cont++;

	if (cont == 3)
	{
		_cd(p, loop, v, env);
		valor = 0;
	}
	else if (cont == 2)
	{
		_put_err(p, loop, 3, v);
		valor = 0;
	}
	return (valor);
}

/**
 * _cleancd - cleans the buffer
 * @c: pointer to buffer
 * Return: -1  0 and  cd in args[0]
 */
void _cleancd(char *c)
{
	int i;

	for (i = 0; i < BUF_SIZE; i++)
		c[i] = 0;
}

/**
 * _fullcd - fill buffer to be pointed
 * @f: pointer to buffer to be pointed
 * @aux: pointer to aux in the buffer
 * Return: -1 , 0 and cd if its in args[0]
 */
void _fullcd(char *f, char *aux)
{
	int w;

	for (w = 0; aux[w] != '\0'; w++)
		f[w] = aux[w];
	for (; w < BUF_SIZE; w++)
		f[w] = 0;
}
/**
 * _cd - Changes the  directory
 * @a: input of user
 * @loop: counts the loops
 * @v: args in the  input
 * @env: copy of env vars
 * Return:-1 and 0 if success
 */
void _cd(char **a, int loop, char *v[], char **env)
{
	int valor = 0, z = 0;
	static char buf[BUF_SIZE];
	static int w = 1;
	char *home, aux[BUF_SIZE] = {0};

	currentstatus(&z);
	if (w == 1)
	{ home = _gethome(env);
		if (!home)
			getcwd(home, BUF_SIZE);
		_updateoldpwd(getcwd(buf, BUF_SIZE), env);
		_fullcd(buf, _gethome(env));
		w++;
	}
	if (a[1] == NULL)
	{
		_cleancd(buf);
		getcwd(buf, BUF_SIZE);
		_updateoldpwd(buf, env);
		valor = chdir((const char *)_gethome(env));
		_updatepwd(_gethome(env), env);
	}
	else if (a[1][0] == '-' && a[1][1] == '\0')
	{
		_cleancd(aux), getcwd(aux, BUF_SIZE);
		_updateoldpwd(aux, env);
		write(STDOUT_FILENO, buf, BUF_SIZE);
		write(STDOUT_FILENO, "\n", 1);
		valor = chdir((const char *) buf);
		_updatepwd(buf, env), _fullcd(buf, aux);
	}
	else
	{
		_cleancd(buf), getcwd(buf, BUF_SIZE);
		_updateoldpwd(buf, env);
		valor = chdir((const char *)a[1]);
		_updatepwd(a[1], env);
	}
	if (valor == -1)
		_put_err(a, loop, 1, v);
}

