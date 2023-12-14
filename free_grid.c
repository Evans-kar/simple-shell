#include "shell.h"
/**
 * free_grid -frees a matrix.
 * @ggrid: this it the matrix
 * @hheight: height of the matrix
 * Return: null
 */
void free_grid(char **ggrid, int hheight)
{
	int ii;

	for (ii = 0; ii < hheight; ii++)
	{
		free(ggrid[ii]);
	}
	free(ggrid);
}
