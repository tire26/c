#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_SIZE 16
#define MAX_ALL 256
void swapNumbers(int *num1, int *num2)
{
    int buffer = 0;
    buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}
int main()
{
    int MAX_i, MAX_j, MAX_ALL1, i, j;
    int count = 0;
    int array[MAX_SIZE][MAX_SIZE];
    int array2[MAX_ALL];
    printf("Entere count of string\n");
    scanf("%d", &MAX_i);
    printf("\nEntere count of coloumn\n");
    scanf("%d", &MAX_j);
    for (i = 0; i < MAX_i; i++)
    {
        for (j = 0; j < MAX_j; j++)
        {
            printf("\nEntere an element of matrix[%d][%d]  ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    i = 0;
    j = 0;
    MAX_ALL1 = MAX_i * MAX_j;
    for (i = 0; i < MAX_i; i++)
    {
        for (j = 0; j < MAX_j; j++)
        {
            array2[count] = array[i][j];
            count++;
        }
    }
    int per = 0, check = 0, check_cmp = 0;
    do
    {
        check = 0;
        for (int i = 0; i < MAX_ALL1; i++)
        {
            if (array2[i] > array2[i + 1])
            {
                check++;
                swapNumbers(&array2[i], &array2[i + 1]);
            }
        }
    } while (check > 0);
    count = 0;
    for (i = 0; i < MAX_i; i++)
    {
        printf("\n");
        for (j = 0; j < MAX_j; j++)
        {
           array[i][j] = array2[count];
           count++;
           printf("%d ", array[i][j]);
        } 
    }
}