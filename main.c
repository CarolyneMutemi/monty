#include "monty.h"
int data = 0;

int main(int argc, char **argv)
{
    FILE *file;
    stack_t *top;
    char buffer[1024];
    char **arr;
    int line;
    bool error;
    size_t i;
    int y;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    top = NULL;
    line = 0;
    
    while (1)
    {
        fgets(buffer, 1024, file);
        line++;
        if (feof(file) || ferror(file)) break;
        error = false;
        arr = read1(buffer);
        if (arr[1][0] == '-' || arr[1][0] == '+')
        {
            for (i = 1; i < strlen(arr[1]); i++)
            {
                if (!isdigit(arr[1][i]))
                {
                    error = true;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < strlen(arr[1]); i++)
            {
                if (!isdigit(arr[1][i]))
                {
                    error = true;
                    break;
                }
            }
        }

        data = atoi(arr[1]);
        check(&top, arr, error, line);
        for (y = 0; y < 2; y++) free(arr[y]);
        free(arr);
    }

    free_stack(top);
    fclose(file);
    return 0;
}
