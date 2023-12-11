#include "shell.h"
/**
 * currentstatus - gets the status
 * @stat: get the pointer inside wait
 * Return: the current status
 */
int currentstatus(int *stat)
{
	static int actual;

	if (stat)
		actual = *stat;
	return (actual);
}
/**
 * _frk - Creates a process and runs it
 * @pp: Pointer array
 * @ll: User input
 * @aa: Pointer number
 * @LL: Number of loops
 * @vv: Loop ags
 * @ee: Length of environment var
 * @mm: Env copy
 * @ff: input
 * Return: Null.
 */

void _frk(char **pp, char *ll, int aa,
		int LL, char **vv, int ee, char **mm, char *ff)
{
	pid_t child_pid;
	int ty = 0, status, exist, execute;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(pp[0], pp, mm) == -1)
		{
			exist = access((const char *) pp[0], F_OK);
			execute = access((const char *) pp[0], X_OK);
			if (exist == 0 && execute == -1)
			{
				_put_err(pp, LL, 4, vv);
				free(ff), free(ll);
				free_grid(pp, aa), free_grid(mm, ee);
				exit(126);
			}
			else
			{
				_put_err(pp, LL, 3, vv);
			}
			free(ff), free(ll);
			free_grid(pp, aa), free_grid(mm, ee);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			ty = WEXITSTATUS(status);
			currentstatus(&ty);
		}
	}
}

