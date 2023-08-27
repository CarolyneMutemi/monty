#include "monty.h"

void add_data(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *ptr = *stack;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	res = ptr->n + ptr->next->n;
	ptr->next->n = res;
	pop_top(stack, line_number);
}

void nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
