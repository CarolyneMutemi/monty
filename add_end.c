#include "monty.h"

void end(stack_t **stack)
{
    stack_t *new, *ptr;

    ptr = *stack;
    new = malloc(sizeof(stack_t));

    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
    }

    new->n = data;
    new->next = NULL;
    new->prev = NULL;

    if (!ptr)
        *stack = new;
    else
    {
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        new->prev = ptr;
        ptr->next = new;
    }
}