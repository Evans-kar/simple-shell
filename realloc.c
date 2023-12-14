#include "shell.h"
/**
 * _realloc -ncreases the size and copie
 * @pptr:  pointer to reallocate
 * @oold_size: previous sze of  bytes
 * @nnew_size:  current number of Bytes
 * Return: NULL
 */
void *_realloc(char *pptr, unsigned int oold_size, unsigned int nnew_size)
{
	char *pp = NULL;
	unsigned int ii;

	if (nnew_size == oold_size)
		return (pptr);
	if (pptr == NULL)
	{
		pp = _calloc(nnew_size + 1, sizeof(char));
		if (!pp)
			return (NULL);
		return (pp);
	}
	if (nnew_size == 0 && pptr != NULL)
	{
		free(pptr);
		return (NULL);
	}
	if (nnew_size > oold_size)
	{
		pp = _calloc(nnew_size + 1, sizeof(char));
		if (!pp)
			return (NULL);
		for (ii = 0; ii < oold_size; ii++)
			pp[ii] = *((char *)pptr + ii);
		free(pptr);
	}
	else
	{
		pp = _calloc(nnew_size + 1, sizeof(char));
		if (!pp)
			return (NULL);
		for (ii = 0; ii < nnew_size; ii++)
			pp[ii] = *((char *)pptr + ii);
		free(pptr);
	}
	return (pp);
}

/**
 * _realloc2 - adjusts size and  copy the content
 * @aa: string to copy
 * @pp:  ptr to reallocate
 * @oold: previous number of bytes
 * @nnew_size: current number of Bytes
 * Return: nothing
 */
void *_realloc2(char *aa, char *pp, unsigned int oold, unsigned int nnew_size)
{
	char *ppa = NULL;
	unsigned int ii, jj = 0;

	if (nnew_size == oold)
		return (pp);
	if (pp == NULL || aa == NULL)
	{
		ppa = _calloc(nnew_size + 1, sizeof(char));
		if (!ppa)
			return (NULL);
		return (ppa);
	}
	while (aa[jj] != '\0')
		jj++;
	if (nnew_size == 0 && pp != NULL)
	{
		free(pp);
		return (NULL);
	}
	if (nnew_size > oold)
	{
		ppa = _calloc(nnew_size + 1, sizeof(char));
		if (!ppa)
			return (NULL);
		for (ii = 0; ii < jj; ii++)
			ppa[ii] = aa[ii];
		for (; ii <= nnew_size; ii++)
			ppa[ii] = *((char *)pp + (ii - jj));
		free(pp);
	}
	else
	{
		ppa = _calloc(nnew_size, sizeof(char));
		if (!ppa)
			return (NULL);
		for (ii = 0; ii < nnew_size; ii++)
			ppa[ii] = *((char *)pp + ii);
		free(pp);
	}
	return (ppa);
}
