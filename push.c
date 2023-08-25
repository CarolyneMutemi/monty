#include "monty.h"

void push_top(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *list;
	(void)line_number;

	top = *stack;
	list = malloc(sizeof(stack_t));

	if (!list)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	list->n = data;
	list->next = NULL;
	list->prev = NULL;
	if (!top)
		*stack = list;
	else
	{
		list->next = *stack;
		top->prev = list;
		*stack = list;
	}
}
