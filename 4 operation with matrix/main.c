#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "function.c"
#define MAX 16
#define MAX_SIZE 25
#define MAX_STR 256
int main()
{
    char line[MAX_STR];
    char *lineSep = "";
    FILE *files = NULL;
    struct matrixStruct
    {
        int matrix1[MAX][MAX];
        int matrix2[MAX][MAX];
        int matrix3[MAX][MAX];
        int MAXi, MAXj, max_number, min_number, sum_even, sum_odd, MINi, MINj;
    };
    struct matrixStruct matrix;
    clearArray(line, MAX_STR);
    clearArray2(matrix.matrix1, MAX, MAX);
    clearArray2(matrix.matrix2, MAX, MAX);
    clearArray2(matrix.matrix3, MAX, MAX);
    int i = 0, j = 0, num = 0, stop_number = 0;
    if ((files = fopen("test.txt", "r")) == NULL)
    {
        perror("Error occured while opening, please shure that you listed right file path ");
        exit(0);
    }
    while (!feof(files))
    {
        printf("\n");
        fgets(line, MAX_STR, files);
        if(isdigit(line[strlen(line) - 1])) line[strlen(line)] = ' ';
        if(line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
        lineSep = strtok(line, " ");
        j = 0;
        while (lineSep != NULL)
        {
            printf("[%s] ", lineSep);
            matrix.matrix1[i][j] = atoi(lineSep);
            lineSep = strtok(NULL, " ");
            j++;
        }
        i++;
    }
    matrix.MAXi = i;
    matrix.MAXi = j;
    printf("\n");
    for (i = 0; i < matrix.MAXi; i++)
    {
        for (j = 0; j < matrix.MAXi; j++)
        {
            if (matrix.matrix1[i][j] % 2 == 0)
            {
                matrix.sum_even += matrix.matrix1[i][j];
            }
            else
            {
                matrix.sum_odd += matrix.matrix1[i][j];
            }
            if (i == 0 && j == 0)
            {
                matrix.max_number = matrix.matrix1[i][j];
                matrix.min_number = matrix.matrix1[i][j];
            }
            if (matrix.matrix1[i][j] > matrix.max_number)
            {
                matrix.max_number = matrix.matrix1[i][j];
            }
            else if (matrix.matrix1[i][j] < matrix.min_number)
            {
                matrix.min_number = matrix.matrix1[i][j];
            }
        }
    }
    fflush(stdin);
    printf("Sum of even numbers %d\n Sum of odd numbers %d\n Max element %d\n Min element %d\n Sum of all elements %d\n", matrix.sum_even, matrix.sum_odd, matrix.max_number, matrix.min_number, (matrix.sum_even + matrix.sum_odd));
    int operation;
    do
    {
        printf("\nchose operation:\n sum with  matrix 2 - 0\n multiplicationy with number - 1\n subtraction with  matrix 2 - 2\n transpoose your matrix- 3\n stop programm - 4\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 0:
        {
            for (int i = 0; i < matrix.MAXi; i++)
            {
                for (int j = 0; j < matrix.MAXi; j++)
                {
                    printf("Enter element of matrix 2 (%d)(%d)\n", i, j);
                    scanf("%d", &matrix.matrix2[i][j]);
                }
            }
            for (i = 0; i < matrix.MAXi; i++)
            {
                for (j = 0; j < matrix.MAXi; j++)
                {
                    matrix.matrix3[i][j] = matrix.matrix2[i][j] + matrix.matrix1[i][j];
                    printf("new element[%d][%d] - %d\n ", i, j, matrix.matrix3[i][j]);
                }
            }
            break;
        }
        case 1:
        {
            printf("Entere number  ");
            scanf("%d", &num);
            for (i = 0; i < matrix.MAXi; i++)
            {
                for (j = 0; j < matrix.MAXi; j++)
                {
                    matrix.matrix3[i][j] = matrix.matrix1[i][j] * num;
                    printf("new element[%d][%d] - %d\n ", i, j, matrix.matrix3[i][j]);
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < matrix.MAXi; i++)
            {
                for (int j = 0; j < matrix.MAXi; j++)
                {
                    printf("Enter element of matrix 2 (%d)(%d)\n", i, j);
                    scanf("%d", &matrix.matrix2[i][j]);
                }
            }
            for (i = 0; i < matrix.MAXi; i++)
            {
                for (j = 0; j < matrix.MAXi; j++)
                {
                    matrix.matrix3[i][j] = abs(matrix.matrix2[i][j] - matrix.matrix1[i][j]);
                    printf("new element[%d][%d] - %d\n ", i, j, matrix.matrix3[i][j]);
                }
            }

            break;
        }
        case 3:
        {
            int size = 0;
            if (matrix.MAXi > matrix.MAXj)
            {
                size = matrix.MAXi;
            }
            else
            {
                size = matrix.MAXj;
            }
            int buf;
            for (i = 0; i < size; i++)
            {
                for (j = 1 + i; j < size; j++)
                {
                    buf = matrix.matrix1[i][j];
                    matrix.matrix1[i][j] = matrix.matrix1[j][i];
                    matrix.matrix1[j][i] = buf;
                }
            }
            for (i = 0; i < matrix.MAXj; i++)
            {
                printf("\n");
                for (j = 0; j < matrix.MAXi; j++)
                {
                    printf("%d ", matrix.matrix1[i][j]);
                }
            }
            break;
        }
        case 4:
        {
            stop_number = 1;
            break;
        }
        default:
        {
            printf("not work");
            break;
        }
        }
    } while (stop_number != 1);
}