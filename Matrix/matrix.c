#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_SIZE 4
#define MIN_SIZE 2
#define MAX_NUM 100
#define MIN_NUM -10
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int i, j, MAXi, MAXj;
    do
    {
        printf("Entere matrix height \n");
        scanf("%d", &MAXi);
        printf("Entere matrix length \n");
        scanf("%d", &MAXj);
    } while ((MAXi <= MIN_SIZE) || (MAXj <= MIN_SIZE) || (MAXi >= MAX_SIZE) || (MAXj >= MAX_SIZE));
    printf("Entere matrix elements\n");
    for (i = 1; i < MAXi + 1; i++)
    {
        for (j = 1; j < MAXj + 1; j++)
        {
            scanf("%d", &matrix[i][j]);
            printf("element(%d)(%d)"); 
        }
    }
}