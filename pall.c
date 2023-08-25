#include "monty.h"

void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{};
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
