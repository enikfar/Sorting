#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void free_array(char **array, int rows)
{
    int row, col;

    for (row = 0; row < rows; row++)
    {
        free(array[row]);
    }
}
void print_array(char **array, int length)
{
    int row, col;

    for (row = 0; row < length; row++)
    {
        printf("%s \n", array[row]);
    }
}
int strcicmp(void *p, void *q)
{
    char *pp = *(char **)p;
    char *qq = *(char **)q;
    for (; *pp; ++pp)
        *pp = tolower(*pp);
    for (; *qq; ++qq)
        *qq = tolower(*qq);
    return strcmp(pp, qq);
}

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
    return -strcmp(pp, qq);
}
long mystrtol(char *start, char **rest)
{
    char *p;
    long result = 0;
    p = start;
    int is_neg = 0;
    long acc = 0;
    while (isspace(*p))
    {
        p += 1;
        acc++;
    }
    if (*p == '-')
    {
        is_neg = 1;
        p += 1;
        acc++;
    }
    if (*p == '+')
    {
        p += 1;
        acc++;
    }

    while (1)
    {
        int digit;
        if ((*p >= '0') && (*p <= '9'))
        {
            digit = (*p - '0');
	    p++;
            acc++;
        }
        else
        {
            break;
        }
        result = result * 10 + digit;
    }
    *rest = p;
    printf("%d\n",result);
    if(is_neg){
    return ( (-1) * result);
    }


    return result;
}
int num_cmp(void *p, void *q)
{
    char *rest = NULL;
    char *rest2 = NULL;
    char *pp = *(char **)p;
    char *qq = *(char **)q;
    if (((mystrtol(pp, &rest)) - (mystrtol(qq, &rest2))) == 0)
    {
        return strcmp(rest, rest2);
    }
    else
    {
        return ((mystrtol(pp, &rest)) - (mystrtol(qq, &rest2)));
    }
}

int main(int arg_count, char **arg_values)
{
    // for (int i = 0; i < arg_count; i++)
    // {
    //     printf("%d: %s\n", i, arg_values[i]);
    // }
    char ch = getchar();
    char **strings;
    strings = malloc(1024 * 1024);
    int row = 0;
    while ((ch != EOF))
    {
        int col = 0;
        // strings[row] = malloc(1024);
        char *word;
        word = malloc(1024 * sizeof(char) + 1);

        while (ch != '\n')
        {
            if (ch == EOF)
            {
                break;
            }
            // printf("%d \n", col);
            word[col] = ch;
	    ch = getchar();
            col++;
        }
        // printf("%d\n", row);

        word[col] = '\0';
	ch = getchar();

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

    if (arg_count > 1)
    {
        for (int i = 1; i < arg_count; i++)
        {
            if (strcmp(arg_values[i], "-f") == 0)
            {
                ;
                qsort(strings, (row - 1), sizeof(char *), strcicmp);
                print_array(strings, row);
            }
            else if (strcmp(arg_values[i], "-r") == 0)
            {
                qsort(strings, (row - 1), sizeof(char *), rev_cmp);
                print_array(strings, row);
            }
            else if (strcmp(arg_values[i], "-h") == 0)
            {
                qsort(strings, (row - 1), sizeof(char *), cmp);
                print_array(strings, row);
            }
            else if (strcmp(arg_values[i], "-n") == 0)
            {
                qsort(strings, row , sizeof(char *), num_cmp);
                print_array(strings, row);
            }
            else
            {
                printf("wrong flag");
            }
        }
    }
    free_array(strings, row);
    return 0;
}
