#include "shell.h"
/**
 * print_number - Prints numbers
 * @nn: Print parameters
 * Return: null
 */
void print_number(int nn)
{
	unsigned int jj, ccount = 1;
	char aa;
	unsigned int vvar1, nnum, vvar2, vvar3 = 1;

	vvar2 = nn;
	nnum = vvar2;
	while (nnum > 9)
	{
		nnum = nnum / 10;
		ccount++;
		vvar3 = vvar3 * 10;
	}
	for (jj = 1; jj <= ccount; jj++)
	{
		vvar1 = vvar2 / vvar3;
		vvar2 = vvar2 % vvar3;
		vvar3 = vvar3 / 10;
		aa = '0' + vvar1;
		write(STDERR_FILENO, &aa, 1);
	}
}
