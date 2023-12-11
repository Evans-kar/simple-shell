#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *getenv(const char *name)
{
    extern char **environ;
    int iterator = 0;

    while (environ[iterator] != NULL)
    {
        char *temp_storage = environ[iterator];
        char *equal_sign = strchr(temp_storage, '=');

        if (equal_sign != NULL)
        {
            *equal_sign = '\0'; // Null-terminate before the '=' sign
            if (strcmp(name, temp_storage) == 0)
            {
                // Return the value part after the '=' sign
                return equal_sign + 1;
            }
            *equal_sign = '='; // Restore the original string
        }

        iterator++;
    }

    return NULL;
}

char *mygetline(void)
{
    char *store = NULL;
    size_t n = 0;
    ssize_t rchar;

    rchar = getline(&store, &n, stdin);

    if (rchar == -1)
    {
        perror("Error: getline failed");
        free(store);
        exit(EXIT_FAILURE);
    }

    if (store[rchar - 1] == '\n')
    {
        store[rchar - 1] = '\0';
    }
    
    return store;
}

char **parse(char *str, const char *delim)
{
    char **arrays = NULL;
    char *splits;
    int iterator = 0;
    int array_size = BUFFER_SIZE; // Initial allocation size

    arrays = malloc(sizeof(char *) * array_size);
    if (arrays == NULL)
    {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    splits = strtok(str, delim);

    while (splits != NULL)
    {
        arrays[iterator] = strdup(splits);
        splits = strtok(NULL, delim);
        iterator++;

        // Check if we need to reallocate memory for arrays
        if (iterator >= array_size)
        {
            array_size += BUFFER_SIZE;
            arrays = realloc(arrays, sizeof(char *) * array_size);
            if (arrays == NULL)
            {
                perror("Error: ");
                exit(EXIT_FAILURE);
            }
        }
    }
    arrays[iterator] = NULL;

    return arrays;
}

int main(void)
{
    char *prompt = "shell $ ";
    char *input;
    char *path;
    char **arrays;
    pid_t cid;
    int status;

    do {
        write(STDOUT_FILENO, prompt, _strlen(prompt));
        input = mygetline();
        arrays = parse(input, " "); // Update delimiter to space
        if (arrays[0] == NULL)
            continue;

        // Find the full path to the executable in the PATH variable
        path = find_executable_path(arrays[0]);
        if (path == NULL)
        {
            printf("Command not found: %s\n", arrays[0]);
            continue;
        }

        cid = fork();
        if (cid == -1)
        {
            perror("Error:");
            exit(EXIT_FAILURE);
        }
        if (cid == 0)
        {
            execve(path, arrays, environ);
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    } while (1);

    return 0;
}
