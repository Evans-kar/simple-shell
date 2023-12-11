#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


char **create_env(char *env[]);
void _updateoldpwd(char *buff, char **env);
void _updatepwd(char *buff, char **env);

int _issetenv(char **iu, char ***env, int *en, int lp, char *ag[]);
void _setenv(char **iu, char ***env, int *en, int lp, char *ag[]);
void _setenvcreat(char ***env, int *en, char *AAentirenv);

int _isunsetenv(char **iu, char **env, int *en, int lp, char *ag[]);
void _unsetenv(char **iu, char **env, int *ne, int lp, char *ag[]);
void _errorenv(char **ptr);

void _noargv(char *av[], char *env[]);
void _yesargv(char *av[], char *env[]);
void functions(char *iu, int lp, char *av[], char ***cp, int *ncp, char *np);
int rev(char **ap, int cl, char *iu,
		char **argsi, char ***cp, int *ncp, char *np);
char *str_concat(char *ar1, char *ar2);
int _strlen(char *str);
void *_realloc(char *pptr, unsigned int cold_size, unsigned int nnew_size);
char *_getline(int *aa, char **mm, int ee);
char  *_getlineav(int *aa, char **mm, int ee, char **av);
char **parsing(char *ln);
char *_comments(char *ln);
int semicolon(char *ln, int lp, char **arg);
int currentstatus(int *stat);

void free_grid(char **ggrid, int hheight);
void _frk(char **pp, char *ll, int aa, int LL,
		char **vv, int ee, char **mm, char *ff);
void *_calloc(unsigned int memb, unsigned int sz);
char **checkbin(char **bb, char **mm);
void *_realloc2(char *aa, char *pp, unsigned int cold, unsigned int nnew_size);
int  _isexit(char **pp, int LL, char *ll, char **vv, char **mm, char *ff);
void _signal(int sg);
int _isenv(char **ptr, char **env);
void _env(char **env);
void _cd(char **aa, int lloop, char *vv[], char **env);
int _iscd(char **pp, int lloop, char *vv[], char **env);
char *_gethome(char **mm);
char *_changepwd(void);
char *_changeoldpwd(void);
char *_getpath(char **mm);
int _atoi(char *ss);
char *_strtoky(char *ss, char *dd);
char *_strtoky2(char *ss, char *dd);

#define SIZE 1024

int _ishelp(char **pp, int lloop, char *vv[], char **mm);
void _help_builtin(char **pp, int lp, char *vv[], char **mm);
void _help(char **pp, int lp, char *vv[], char **mm);
ssize_t read_help(char **mm);
ssize_t read_cdhelp(char **mm);
ssize_t read_exithelp(char **mm);
ssize_t read_helphelp(char **mm);

void _put_err(char **ptr, int lp, int sg, char *vv[]);
void _builtinerr(char **ptr);
void _builtinerr2(char **ptr);
void _errorcd(char **ptr);
void _errorexit(char **ptr);
void _errorhelp(char **ptr);
void _errorgarbage(char **ptr);
void print_number(int nn);

#endif
