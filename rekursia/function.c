#define MAX_SIZE 25
#define MAX_STR 256
#include <ctype.h>
void clearArray(char *fio1, int size)
{
    fio1--;
    for (int i = 0; i < size; i++, fio1++)
    {
        *fio1 = ' ';
    }
}
void upperNumGroup(char fio1[MAX_SIZE])
{
    fio1[0] = toupper(fio1[0]);
    fio1[2] = toupper(fio1[2]);
    fio1[7] = toupper(fio1[7]);
}
void printArray(char string[MAX_SIZE])
{
    int size = 0;
    size = strlen(string[MAX_SIZE]);
    for (int i = 0; i < size; i++)
    {
        printf("%c\n", string[size]);
    }
}