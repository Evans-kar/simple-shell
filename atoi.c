#include "shell.h"
/**
 * _atoi - converts arry of string to  integers.
 * @ss: pinters to arrays of intagers.
 * Return: returns the get number of args
 */
int _atoi(char *ss)
{
	unsigned int ccont1 = 0, aa, bb, cc, nnum = 0, ttam;
	int aaux2 = 1;

	while (*(ss + ccont1) != '\0')
	{
		ccont1++;
	}
	for (aa = 0; aa < ccont1; aa++)
	{
		if (*(ss + aa) >= '0' && *(ss + aa) <= '9')
			break;
	}
	for (bb = aa; bb < ccont1; bb++)
	{
		if (!(*(ss + bb) >= '0' && *(ss + bb) <= '9'))
			break;
	}
	for (cc = 0; cc < aa; cc++)
	{
		if (*(ss + cc) == '-')
			aaux2 = aaux2 * (-1);
	}
	ttam = bb - aa;
	while (ttam >= 1)
	{
		nnum = (nnum * 10) + (*(ss + aa) - '0');
		aa++;
		ttam--;
	}
	nnum = nnum * aaux2;
	return (nnum);
}
