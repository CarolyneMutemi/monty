#include "monty.h"

void check(stack_t **top, char **arr, bool error, bool *mode, unsigned int line)
{
	instruction_t pall = {"pall", &print_all};
	instruction_t push = {"push", &push_top};
	instruction_t pint = {"pint", &print_top};
	instruction_t pop = {"pop", &pop_top};
	instruction_t swap = {"swap", &swap_data};
	instruction_t add = {"add", &add_data};
	instruction_t nop = {"nop", &nothing};
	instruction_t sub = {"sub", &sub_data};
	instruction_t div = {"div", &div_data};
	instruction_t mul = {"mul", &mul_data};
	instruction_t mod = {"mod", &mod_data};
	instruction_t pchar = {"pchar", &print_top_char};
	instruction_t pstr = {"pstr", &print_string};
	instruction_t rotl = {"rotl", &rotl_stack};
	instruction_t rotr = {"rotr", &rotr_stack};
	instruction_t stack = {"stack", &stack_mode};
	instruction_t queue = {"queue", &queue_mode};

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

		if (*mode == false)
			end(top);
		else
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
	else if (strlen(arr[0]) == strlen(sub.opcode) && strstr(arr[0], sub.opcode))
	{
		sub.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(div.opcode) && strstr(arr[0], div.opcode))
	{
		div.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(mul.opcode) && strstr(arr[0], mul.opcode))
	{
		mul.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(mod.opcode) && strstr(arr[0], mod.opcode))
	{
		mod.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(pchar.opcode) && strstr(arr[0], pchar.opcode))
	{
		pchar.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(pstr.opcode) && strstr(arr[0], pstr.opcode))
	{
		pstr.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(rotl.opcode) && strstr(arr[0], rotl.opcode))
	{
		rotl.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(rotr.opcode) && strstr(arr[0], rotr.opcode))
	{
		rotr.f(top, line);
	}
	else if (strlen(arr[0]) == strlen(stack.opcode) && strstr(arr[0], stack.opcode))
	{
		*mode = true;
	}
	else if (strlen(arr[0]) == strlen(queue.opcode) && strstr(arr[0], queue.opcode))
	{
		*mode = false;
	}
	else if ((strlen(arr[0]) == 1 && isspace(arr[0][0])) || strlen(arr[0]) == 0)
    {}
	else if (!check_string(arr[0]))
	{}
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line, arr[0]);
        exit(EXIT_FAILURE);
    }
}
