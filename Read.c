#include "monty.h"

char **read1(char *buffer)
{
	char **arr = malloc(2 * sizeof(char *));
	char d[] = " ";
	int lim = 0;

	for (int i = 0; i < 2; i++)
		arr[i] = malloc(100 * sizeof(char));

	trim(buffer);
	char *portion = strtok(buffer, d);

	while (portion != NULL && lim < 2)
	{
		strcpy(arr[lim], portion);
		lim++;
		portion = strtok(NULL, d);
	}
	return (arr);
}
