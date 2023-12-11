#include "shell.h"
/**
 * Counter - Counter to number of lim
 * @LL: Input string;
 * @lim: character to be found in LL
 * Return: number of characters found
 */
int Counter(char *LL, char *lim)
{
	int ct = 0, num = 0, ct2 = 0;

	while (lim[ct2] != '\0')
	{
		ct = 0;
		while (LL && LL[ct] != '\0')
		{
			if (LL[ct] != lim[ct2])
			{
				if (LL[ct + 1] == lim[ct2] || LL[ct + 1] == '\0')
					num++;
			}
			ct++;
		}
		ct2++;
	}
	return (num);
}
/**
 * parsing - Creates a delimiter array of characters
 * @ln: Usuer input
 * Return: n sized array of pointers
 */
char **parsing(char *ln)
{
	char *token = NULL, **p = NULL;
	int length = 0, j = 0, i = 0, buffsize = 0;

	if (ln == NULL)
		return (NULL);
	buffsize = Counter(ln, " \t");
	p = _calloc((buffsize + 1), sizeof(char *));
	if (!p)
	{
		perror("No memory");
		return (NULL);
	}
	token = _strtoky(ln, " \t\n");
	if (!token)
	{
		free(p);
		return (NULL);
	}
	while (token)
	{
		while (token[length] != '\0')
			length++;
		p[j] = _calloc((length + 1), sizeof(char));
		if (p[j] == NULL)
		{
			free_grid(p, j);
			perror("No memory");
			return (NULL);
		}
		for (i = 0; i < length; i++)
			p[j][i] = token[i];
		length = 0;
		j++;
		token = _strtoky(NULL, " \t\n");
	}
	p[j] = NULL;
	return (p);
}
