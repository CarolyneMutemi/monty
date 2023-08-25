#include "monty.h"

/**
 * free_stack - frees a dlistint_t list.
 * @top: pointer to the top of the stack.
 * Return: nothing.
 */

void free_stack(stack_t *top)
{
	stack_t *ptr = top;
	stack_t *temp;

	if (top)
	{
		while (ptr->next)
		{
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		free(ptr);
	}
}
