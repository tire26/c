#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iso646.h>
#include <ctype.h>
#define MAX_SIZE 25
#define MAX_STR 256
int main()
{
    int d;
    int *pAbc = malloc(MAX_STR);
    int **Array2;
    int *Rows;
    int Size, Num;
    printf("Razmernost vvedite ");
    scanf("%i", &Size);
    Array2 = calloc(Size, sizeof(int*));
    Rows = malloc(sizeof(int) * Size);
    for (int i = 0; i < Size; i++)
    {
        Array2[i] = calloc(Rows[i], sizeof(int));
        for (int j = 0; j < Size; j++)
        {
            Array2[i][j] = i + j;
            printf("%i ", Array2[i][j]); 
        }
        printf("\n");
        free(Array2[i]);
    }
    free(Array2);
    free(Rows);
    return 0;
}