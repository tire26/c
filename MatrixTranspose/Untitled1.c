#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_SIZE 4
#define MIN_SIZE 2
#define MAX_NUM 100
#define MIN_NUM -10
int main(){
    int matrix [MAX_SIZE][MAX_SIZE];
    setlocale(LC_ALL,"RU");
    int i, j, MAXi, MAXj;
    do{
        printf("Entere matrix height \n");
        scanf("%d",MAXi);
        printf("Entere matrix length \n");
        scanf("%d",MAXj);
    }while(MAXi <= MIN_SIZE || MAXj <= MIN_SIZE || MAXi >= MAX_SIZE || MAXj >= MAX_SIZE);
    printf("Entere matrix elements\n");
    for(i = 1;i < MAXi + 1;i++){
        for (j = 1;j < MAXj + 1;j++){
            printf("element(%d)(%d) ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int size = 0;
    if (MAXi > MAXj){
        size = MAXi;
    }
    else{
        size = MAXj;
    }
    int buf;
    for (i=1;i < size;i++){
        for (j = 1 + i;j < size + 1;j++){
            buf = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = buf;

        }
    }
    for (i = 1; i < MAXj  + 1;i++){
             printf("\n");
        for(j=1;j < MAXi + 1;j++){
            printf("%d ", matrix[i][j]);
        }
    }
}
