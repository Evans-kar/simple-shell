#include "shell.h"
/**
 * printprompt - prints a prompt
 */
void printprompt(void)
{
        const char *prompt = "shell $ ";

        if (isatty(STDIN_FILENO))
        {
                write(STDOUT_FILENO, prompt, strlen(prompt);
        }
}
/**
 * mygetline - reads user input from stdin
 * Return: characters read
 */
char mygetline(int argc, char **argv, char **env)
{
        char *store = NULL, *store_copy = NULL;
        size_t n = 0;
        ssize_t rchar;
        const char *delim = "\n";
        char *token;
        int num = 0;
        int i;

        (void)argc; (void)env;

        rchar = getline(&store, &n, stdin);

        if (rchar == -1)
        {
                perror("Error: exiting shell\n");
                exit(0);
        }
        store_copy = malloc(sizeof(char) * rchar);
        if (!store_copy)
        {
                perror("Error: memory allocation fail");
                exit(1);
        }
        strcpy(store_copy, store);
        token = strtok(store, delim);

        while (!token)
        {
                num++;
                token = strtok(NULL, delim);
        }
        num++;

        argv = malloc(sizeof(char *) * num);

        token = strtok(store_copy, delim);

        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);

                token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        printf("%s\n", store);

        if (!rchar)
        {
                free(store);
                exit(2);
        }
        if (store[rchar - 1] == '\n')
        {
                store[rchar - 1] = '\0';
        }
        return (rchar);
}
int main(void)
{
        while(1)
        {
                printprompt();
                mygetline();
        }
        return (0);

}
