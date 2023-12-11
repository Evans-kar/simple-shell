char *getenv(const char *name)
{
	char **arrays;
	char *arrays_variable;
	int current, arrays_len;

	arrrays_variable = malloc(sizeof(char *) * arrays);
	if (!arrays_variable)
	{
		free(arrays_variable);
		exit(0);
	}
	arrays_variable = _strcpy(arrays);
	arrays_len[current] = arrays_variable[current];
}
