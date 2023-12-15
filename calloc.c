#include <stdlib.h>
#include "shell.h"
/**
 * _calloc -  take stwo arguments and allocates memory
 * @memb: number of elements
 * @sz: size of the elements in bytes
 * Return:null
 */
void *_calloc(unsigned int memb, unsigned int sz)
{
	void *p = NULL;
	unsigned int i;

	if (memb == 0 || sz == 0)
	{
		return (NULL);
	}
	p = malloc(memb * sz);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (memb * sz); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}

