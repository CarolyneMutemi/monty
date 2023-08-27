#include "monty.h"

void rotl_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;
    int num;
    (void)line_number;

    ptr = *stack;

    if (!ptr)
    {}
    else
    {
        num = ptr->n;
        while (ptr->next)
        {
            ptr->n = ptr->next->n;
            ptr = ptr->next;
        }
        ptr->n = num;
    }
}