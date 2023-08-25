#include "monty.h"

void trim(char *s)
{
	int i = strlen(s) - 1;

	while (i > 0)
	{
		if (isspace(s[i]))
			i--;
		else
			break;
	}

	s[i + 1] = '\0';
}
