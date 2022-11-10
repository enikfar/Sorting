#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void free_array(char **array, int rows) // this free the array after sorting
{

    for (int row = 0; row < rows; row++)

    {
        free(array[row]);
    }
}
void print_array(char **array, int length)
{

    for (int row = 0; row < length; row++)
    {
        printf("%s \n", array[row]);
    }
}
int strcicmp(const void *p, const void *q) // this function compare the strigns- case insensitive
{
    char *pp = *(char **)p;
    char *qq = *(char **)q;

    if (((pp[0] >= 'A') && (pp[0] <= 'Z')) && ((qq[0] >= 'A') && (qq[0] <= 'Z'))) // if both of them start with upper case, I just subtract them

    {

        if ((pp[0] - qq[0]) > 0)
        {
            return 1;
        }
        if ((pp[0] - qq[0]) < 0)
        {
            return (-1);
        }
        else
        {
            return 0;
        }
    }
    if (((pp[0] >= 'A') && (pp[0] <= 'Z'))) // if one of them start with upper case
    {

        if (((pp[0]) - (qq[0] - 32)) > 0)
        {
            return 1;
        }
        if (((pp[0]) - (qq[0] - 32)) < 0)
        {
            return (-1);
        }
        else
        {
            return -1;
        }
    }
    if (((qq[0] >= 'A') && (qq[0] <= 'Z')))
    {

        if (((pp[0] - 32) - (qq[0])) > 0)
        {
            return 1;
        }
        if (((pp[0] - 32) - (qq[0])) < 0)
        {
            return (-1);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return strcmp(pp, qq); // if none of them are in alphabets, then we do the usual papers
    }
}

int cmp(const void *p, const void *q) // just normal comarsion of the strings
{
    char *pp = *(char **)p;
    char *qq = *(char **)q;

    return strcmp(pp, qq);
}
int rev_cmp(const void *p, const void *q) // reverseing order
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
    while (isspace(*p)) // remove all the leading spaces
    {
        p += 1;
        acc++;
    }
    if (*p == '-') // determine the sign
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
            break; // I finish the while when ther is no number
        }
        result = result * 10 + digit;
    }
    *rest = p;

    if (is_neg)
    {
        return ((-1) * result);
    }

    return result;
}
int num_cmp(const void *p, const void *q)
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

    char ch = getchar();
    char **strings;
    strings = malloc(1024 * 1024);
    int row = 0;
    while ((ch != EOF))
    {
        int col = 0;

        char *word;
        word = malloc(1024 * sizeof(char) + 1);

        while (ch != '\n')
        {
            if (ch == EOF)
            {
                break;
            }

            word[col] = ch;
            ch = getchar();
            col++;
        }

        word[col] = '\0';
        ch = getchar();

        strings[row] = word;

        row++;
    }

    if (arg_count > 1)
    {
        for (int i = 1; i < arg_count; i++)
        {
            if (strcmp(arg_values[i], "-f") == 0)
            {

                qsort(strings, (row), sizeof(char *), strcicmp);
            }
            else if (strcmp(arg_values[i], "-r") == 0)
            {
                qsort(strings, (row), sizeof(char *), rev_cmp);
            }
            else if (strcmp(arg_values[i], "-h") == 0)
            {
                qsort(strings, (row), sizeof(char *), cmp);
            }
            else if (strcmp(arg_values[i], "-n") == 0)
            {
                qsort(strings, row, sizeof(char *), num_cmp);
            }
            else
            {
                printf("wrong flag");
                exit(0);
            }
        }
    }
    else
    {
        qsort(strings, (row - 1), sizeof(char *), cmp);
    }
    print_array(strings, row);
    free_array(strings, row);
    return 0;
}
