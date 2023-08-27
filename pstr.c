#include "monty.h"

void print_string(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr = *stack;
    (void)line_number;

    while (ptr && ptr->n != 0 && ((ptr->n > 64 && ptr->n < 91) || (ptr->n > 96 && ptr->n < 123)))
    {
        printf("%c", ptr->n);
        ptr = ptr->next;
    }
    printf("\n");
}