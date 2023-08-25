#include "monty.h"

void check(stack_t **top, char **arr, bool error, unsigned int line)
{
	instruction_t pall = {"pall", &print_all};
	instruction_t push = {"push", &push_top};
	instruction_t pint = {"pint", &print_top};
	instruction_t pop = {"pop", &pop_top};
	instruction_t swap = {"swap", &swap_data};
	instruction_t add = {"add", &add_data};
	instruction_t nop = {"nop", &nothing};

	if (strlen(arr[0]) ==  strlen(pall.opcode) && strstr(arr[0], pall.opcode))
	{
		pall.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(push.opcode) && strstr(arr[0], push.opcode))
	{
		if (error)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		push.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(pint.opcode) && strstr(arr[0], pint.opcode))
	{
		pint.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(pop.opcode) && strstr(arr[0], pop.opcode))
	{
		pop.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(swap.opcode) && strstr(arr[0], swap.opcode))
	{
		swap.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(add.opcode) && strstr(arr[0], add.opcode))
	{
		add.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(nop.opcode) && strstr(arr[0], nop.opcode))
	{
		nop.f(top, line);
	}
	else if ((strlen(arr[0]) == 1 && isspace(arr[0][0])) ||  arr[0][0] == 0)
	{}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, arr[0]);
		exit(EXIT_FAILURE);
	}
}
