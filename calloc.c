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
	void *pp = NULL;
	unsigned int ii;

	if (memb == 0 || sz == 0)
	{
		return (NULL);
	}
	pp = malloc(memb * sz);
	if (pp == NULL)
	{
		return (NULL);
	}
	for (ii = 0; ii < (memb * sz); ii++)
	{
		*((char *)(pp) + ii) = 0;
	}
	return (pp);
}

