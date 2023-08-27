#include "monty.h"

bool check_string(char *s)
{
    int i;
    bool check = true;
    for (i = 0; s[i]; i++)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]))
        {
            check = false;
            break;
        }
    }
    return check;
}