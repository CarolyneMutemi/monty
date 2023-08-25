#include "monty.h"
int data = 0;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *top = NULL;
    char buffer[1024];
    char **arr;
    int line = 0;
    bool error;
    
    while (1)
    {
        fgets(buffer, 1024, file);
        line++;
        if (feof(file) || ferror(file)) break;
        error = false;
        arr = read1(buffer);
        for (int i = 0; i < strlen(arr[1]); i++)
        {
            if (!isdigit(arr[1][i]))
            {
                error = true;
                break;
            }
        }

        data = atoi(arr[1]);
        check(&top, arr, error, line);
        for (int i = 0; i < 2; i++) free(arr[i]);
        free(arr);
    }

    free_stack(top);
    fclose(file);
    return 0;
}
