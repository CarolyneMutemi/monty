#include "monty.h"

size_t len(stack_t *stack)
{
	stack_t *ptr = stack;
	size_t count = 0;

	if (!ptr)
		return (0);
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

void swap_data(stack_t **stack, unsigned int line_number)
{
	int num, num2;
	stack_t *ptr = *stack;

	if (len(ptr) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	num = ptr->n;
	num2 = ptr->next->n;
	ptr->n = num2;
	ptr->next->n = num;
}
