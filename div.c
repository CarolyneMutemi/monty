#include "monty.h"

void div_data(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *ptr = *stack;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	    exit(EXIT_FAILURE);
	}

    if (ptr->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

	res = ptr->next->n / ptr->n;
	ptr->next->n = res;
	pop_top(stack, line_number);
}
