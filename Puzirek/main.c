#include <stdio.h>
#include "Untitled2.c"
#define SIZE 25
int main()
{
  int a[SIZE];
  int *pn;
  printf("Enter razmernost massiva \n");
  scanf("%d", &pn);
  for (int i = 0; i < &pn; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
    if (a[i] > 100 || a[i] < 0)
    {
      fflush(stdin);
      printf("Was entered wrong number(number should be from 0 to 100), try again\n");
      printf("a[%d] = ", i);
      scanf("%d", &a[i]);
    }
  }
  bubbleSort(a, pn);
  for (int i = 0; i < *pn; i++)
    printf("%d ", a[i]);
  return 0;
}
