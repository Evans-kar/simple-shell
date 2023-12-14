#include "shell.h"

/**
 * _verifypath - check if the path has a collon  at the begining
 *@pth: searches for executable
 *@pd: string inside pwd environment variable
 *Return: path, or pwd
 */
char *_verifypath(char *pth, char *pd)
{
	int aa = 0, cc = 0, ii = 0;
	char *newpath = NULL;

	while (pth[cc] != '\0')
		cc++;
	while (pth[aa] != '\0')
	{
		if (pth[0] == ':')
		{
			newpath = _calloc(cc + 1, sizeof(char));
			newpath[0] = pd[0];
			for (ii = 0; pth[ii] != '\0'; ii++)
				newpath[ii + 1] = pth[ii];
			free(pth);
			pth = newpath;
			aa++;
			cc++;
		}
		else if (pth[aa] == ':' && pth[aa + 1] == ':')
		{
			newpath = _calloc(cc + 1, sizeof(char));
			for (ii = 0; ii <= aa; ii++)
				newpath[ii] = pth[ii];
			newpath[ii] = pd[0];
			for (ii = ii + 1; pth[ii] != '\0'; ii++)
				newpath[ii] = pth[ii - 1];
			free(pth);
			aa++;
			pth = newpath;
		}
		aa++;
	}
	return (pth);
}
/**
 *_getpath - gets string in PATH
 * @mm: environment variables
 * Return: string inside PATH
 */
char *_getpath(char **mm)
{
	int ii, jj, kk = 0, ww = 0, ccont = 0;
	char str[] = "PATH=";
	char *pth;

	for (ii = 0; mm[ii] != NULL; ii++)
	{
		for (jj = 0; mm[ii][jj] != '\0'; jj++)
		{
			if (ccont == 5)
				break;
			if (mm[ii][jj] == str[jj])
				ccont++;
			else
				break;
		}
		if (ccont == 5)
			break;
	}
	kk = ccont;
	if (ccont == 5)
	{
		while (mm[ii][kk] != '\0')
		{
			ww++;
			kk++;
		}
		if (ww == 0)
			return (NULL);
		pth = _calloc(ww + 1, sizeof(char));
		if (pth == NULL)
			return (NULL);
		kk = 5;
		while (mm[ii][kk] != '\0')
		{
			pth[kk - 5] = mm[ii][kk];
			kk++;
		}
		return (pth);
	}
	return (NULL);
}
/**
 * checkbin - checks if arg[0] has /bin/
 * @bb: input of user
 * @mm: copy of env
 * Return: 0.
 */

char **checkbin(char **bb, char **mm)
{
	unsigned int ii = 0, jj = 0, kk = 0;
	struct stat veri;
	char *path, *tokens, *buf, *newpath;
	char *valor;

	ii = _strlen(bb[0]);
	if (bb == NULL || ii == 0)
		return (NULL);
	path = _getpath(mm);
	if (path == NULL)
		return (bb);
	newpath = _verifypath(path, ".");
	tokens = _strtoky(newpath, ":");
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		while (tokens[jj] != '\0')
			jj++;
		buf = _calloc((jj + 2), sizeof(char));
		if (buf == NULL)
			perror("No memory");
		for (kk = 0; kk < jj; kk++)
			buf[kk] = tokens[kk];
		buf[kk] = '/';
		valor = str_concat(buf, bb[0]);
		if (stat(valor, &veri) == 0)
		{
			bb[0] = _realloc2(buf, bb[0], ii, _strlen(valor));
			free(buf), free(valor);
			free(newpath);
			return (bb);
		}
		tokens = _strtoky(NULL, ":");
		jj = 0;
		free(buf), free(valor);
	}
	free(newpath);
	return (bb);
}

