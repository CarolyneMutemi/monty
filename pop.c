#include "monty.h"

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (ptr->next)
		ptr->next->prev = NULL;
	*stack = ptr->next;
	free(ptr);
	ptr = NULL;
}
