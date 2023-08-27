#include "monty.h"

void print_top_char(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr = *stack;

    if (ptr == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (ptr->n < 65 || (ptr->n > 90 && ptr->n < 97) || ptr->n > 122)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", ptr->n);
}