#include "monty.h"

void rotr_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;
    int num;
    (void)line_number;

    ptr = *stack;

    if (!ptr)
    {}
    else
    {
        while (ptr->next)
        {
            ptr = ptr->next;
        }

        num = ptr->n;

        while (ptr->prev)
        {
            ptr->n = ptr->prev->n;
            ptr = ptr->prev;
        }
        ptr->n = num;
    }
}
