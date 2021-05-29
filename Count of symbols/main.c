#include <stdlib.h>
#include <stdio.h>
int  main() {
    /*int num, A;
    while ((A = getchar()) != EOF) {
        if (A == '\n') num++;
    }
    printf("%d", num);*/
    int A, B, C, D, max;
    scanf("%d%d%d", &A, &B, &C);
    /*if(A > B){
        C += A;
    }
    else
    {
       C += B; 
    }
    if(A > B){
        C += A;
    }
    else
    {
        C += B;
    }*/
    // выражение 1 ? выражение2 : выражение3
    D+=(A>B) ? A : B;
    printf("%d %d", C, D);
    for (int i = 0; i < max;i++){
        //
        if(A < B){
            continue;
        } 
        //
    }
    for (int i = 0; i < max;i++){
        //
        if(A > B){
        } 
        //
    }
}
