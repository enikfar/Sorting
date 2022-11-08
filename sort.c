#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define COLS 1048576;
#define ROWS 1024;
//folding_case = FALSE;
void initializer(int *array[])
{ //initialize the two 2d array to null byte
    int row, col;

    for (row = 0; (row < ROWS); row++)

    {

        // currently has no actual row
        array[row] = malloc((ROWS + 1) * sizeof(int));

        // Now we can use it
        for (col = 0; col < (COLS + 1); col++)
        {
            array[row][col] = '\0';
        }
    }
}

int main(int arg_count, char **arg_values)
{

    for (int i = 0; i < arg_count; i++)
    {
        printf("%d: %s\n", i, arg_values[i]);
    }
    int ch;
    int *b[ROWS];
    initializer(b);

    return 0;
}
