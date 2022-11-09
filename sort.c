#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// void free_array(int *array[])
// {
//     int row, col;

//     for (row = 0; row < ROWS; row++)
//     {
//         free(array[row]);
//     }
// }

// int strcicmp(void *a, void *b)
// {
//     for (;; a++, b++)
//     {
//         int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
//         if (d != 0 || !*a)
//             return d;
//     }
// }

int cmp(void *p, void *q)
{
    char *pp = *(char **)p;
    char *qq = *(char **)q;
    // printf("%s\n", pp);
    // printf("%s\n", qq);

    return strcmp(pp, qq);
}
int rev_cmp(void *p, void *q)
{
    char *pp = *(char **)p;
    char *qq = *(char **)q;
    // printf("%s\n", pp);
    // printf("%s\n", qq);

    return -strcmp(pp, qq);
}
int main(int arg_count, char **arg_values)
{
    // for (int i = 0; i < arg_count; i++)
    // {
    //     printf("%d: %s\n", i, arg_values[i]);
    // }
    char ch;
    char **strings;
    strings = malloc(1024 * 1024);
    int row = 0;
    while ((ch != EOF))
    {
        int col = 0;
        // strings[row] = malloc(1024);
        char *word;
        word = malloc(1024);

        while ((ch = getchar()) != '\n')
        {
            if (ch == EOF)
            {
                break;
            }
            // printf("%d \n", col);
            word[col] = ch;
            col++;
        }
        // printf("%d\n", row);

        word[col] = '\0';

        strings[row] = word;
        // printf("\n %s", strings[row - 2]);
        // printf(" \n here");
        // printf("\n %s", word);
        row++;
        if (ch == EOF)
        {
            strings[row] = malloc(1024);
            strings[row] = '\0';
        }
    }

    // qsort(strings, (row - 1), sizeof(char *), cmp);

    // free_array(strings);
    return 0;

    if (arg_count > 1)
    {
        for (int i = 1; i < arg_count; i++)
        {
            // if (strcmp(arg_values[i], "-f") == 0)
            // {

            //     qsort(strings, (row - 1), sizeof(char *), strcicmp);
            // }
            if (strcmp(arg_values[i], "-r") == 0)
            {
                qsort(strings, (row - 1), sizeof(char *), rev_cmp);
                printf("here");
            }
            // if (strcmp(arg_values[i], "-n") == 0)
            // {
            //     qsort(strings, (row - 1), 1024, numeric_compar);
            // }
        }
    }

    int i = 0;

    for (i; i < row - 1; i++)
    {
        printf("\n %s", strings[i]);
    }
}