#include "shell.h"
/**
 * _yesargv - shell form without filename at input
 * @aargv: args found from in the input
 * @eenvp: env variables in shell
 */
void _yesargv(char *aargv[], char *eenvp[])
{
	char *lline = NULL, **mm = NULL, *pp = NULL, *ppr1 = NULL;
	int ee = 0, *pploop, ii, ssem;
	static int lloop;

	lloop = 0;
	pploop = &lloop;
	while (1)
	{
		if (lloop == 0)
		{
			mm = create_env(eenvp);
			for (ee = 0; mm[ee] != NULL; ee++)
				;
		}
		lline = _getlineav(pploop, mm, ee, aargv);
		ssem = semicolon(lline, lloop, aargv);
		if (!(ssem == 1))
		{
			pp = _strtoky2(lline, ";\n");
			while (pp)
			{
				ppr1 = _calloc(_strlen(pp) + 2, sizeof(char));
				for (ii = 0; pp[ii] != '\0'; ii++)
					ppr1[ii] = pp[ii];
				ppr1[ii] = '\n';
				ppr1[ii + 1] = '\0';
				functions(ppr1, lloop, aargv, &mm, &ee, lline);
				pp = _strtoky2(NULL, ";\n");
			}
		}
		free(lline);
	}
}
