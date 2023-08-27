#include "monty.h"

void sub_data(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *ptr = *stack;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	res = ptr->next->n - ptr->n;
	ptr->next->n = res;
	pop_top(stack, line_number);
}