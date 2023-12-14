#include "shell.h"

/**
 * _signal - handle signal
 * @sg: signal to react to
 */
void _signal(int sg)
{
	(void)sg;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

