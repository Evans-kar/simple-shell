#include "shell.h"

/**
 * read_help - Read bultin text
 * @mm: Env copy
 * Return: number of characters to write.
 */

ssize_t read_help(char **mm)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_all.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(mm);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_cdhelp - Reads dc text
 * @mm: Env copy
 * Return: number of letters to display
 */

ssize_t read_cdhelp(char **mm)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_cd.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(mm);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_exithelp - Read text iniput file
 * @mm: Env copy
 * Return: number of letters to write
 */

ssize_t read_exithelp(char **mm)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_exit.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(mm);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_helphelp - read help text in input
 * @mm: Env copy
 * Return: number of letters to write
 */

ssize_t read_helphelp(char **mm)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_help.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(mm);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}
