#include "shell.h"

/**
 * _errorcd - writes the error
 * @ptr: pointer of an array
 * Return: null.
 */
void _errorcd(char **ptr)
{
	int aa = 2;

	write(STDERR_FILENO, ptr[0], 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, ptr[1], _strlen(ptr[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
/**
 * _errorexit - writes the error
 * @ptr: input pointer
 * Return: null.
 */
void _errorexit(char **ptr)
{
	int aa = 2;

	write(STDERR_FILENO, ptr[0], 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, ptr[1], _strlen(ptr[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
/**
 * _errorhelp - writes the error
 * @ptr: input pointer to an array
 * Return: null.
 */
void _errorhelp(char **ptr)
{
	int aa = 2;

	write(STDERR_FILENO, ptr[0], 4);
	write(STDERR_FILENO, ": no help topics match '", 24);
	write(STDERR_FILENO, ptr[1], _strlen(ptr[1]));
	write(STDERR_FILENO, "'. Try 'help help' or 'man -k '", 31);
	write(STDERR_FILENO, ptr[1], _strlen(ptr[1]));
	write(STDERR_FILENO, "' or info '", 11);
	write(STDERR_FILENO, ptr[1], _strlen(ptr[1]));
	write(STDERR_FILENO, "'\n", 2);
	currentstatus(&aa);
}
/**
 * _errorgarbage - writes the error
 * @ptr: input pointer to an array
 * Return: null.
 */
void _errorgarbage(char **ptr)
{
	int aa = 2;

	write(STDERR_FILENO, ptr[0], _strlen(ptr[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	currentstatus(&aa);
}
/**
 * _errorenv - writes the error
 * @ptr: input pointer to an array
 * Return: null.
 */
void _errorenv(char **ptr)
{
	int aa = 2;

	write(STDERR_FILENO, ptr[0], _strlen(ptr[0]));
	write(STDERR_FILENO, ": unable to add/rm variable ", 28);
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
