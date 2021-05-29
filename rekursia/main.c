#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iso646.h>
#include <ctype.h>
#include "function.c"
int faktorial(int a)
{
    if (a != 0)
        return faktorial(a - 1) * a;
    else
        return 1;
}
int degree(int a, int b)
{
    if (b != 0)
    {
        return a *  degree(a, b - 1);
    }
    else
        return 1;
}
int main()
{
    int num1 = 0, num2 = 0;
    int num = 0;
    printf("Enter !a\n");
    scanf("%i", &num);
    printf("%i\n", faktorial(num));
    printf("Entere a^b\n");
    scanf("%i %i", &num1,&num2);
    printf("%i",degree(num1, num2));
}