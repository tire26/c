#define MAX_SIZE 25
#define MAX_STR 256
#define NUM_SUBJECTS 15
#include <ctype.h>
void clearArrayInt(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}
void clearArray(char *fio1, int size)
{
    for (int i = 0; i < size; i++)
    {
        fio1[i] = '\0';
    }
}
void upperNumGroup(char fio1[MAX_SIZE])
{
    fio1[0] = toupper(fio1[0]);
    fio1[2] = toupper(fio1[2]);
    fio1[7] = toupper(fio1[7]);
}
void printArray(char *string)
{
    int size = 0;
    size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        printf("%c", string[i]);
    }
}
void clearALL(char *all_string, char *fio, char *num_Group, char *course, char *email)
{
    clearArray(all_string, MAX_STR);
    clearArray(fio, MAX_SIZE);
    clearArray(num_Group, MAX_SIZE);
    clearArray(course, MAX_SIZE);
    clearArray(email, MAX_SIZE);
}
void clearArray2(char **fio1, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
        {
            {
                fio1[i][j] = '\0';
            }
        }
}
/*int transfer(int *teleport)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    int k = strlen(buffer);
    for (int i = 0; i < k; i++)
    {
        if (!isdigit(buffer[i]))
        {
            printf("Îøèáêà\n");
            return 1;
        }
    }
    *teleport = atoi(buffer);
    return 0;
}*/
void swapNumbers(int *num1, int *num2)
{
    char buffer = '\0';
    buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}

void bubbleSort3(char *a, size_t size)
{
    size_t i;
    int tmp;
    char flag;
    do
    {
        flag = 0;
        for (i = 1; i < size; i++)
        {
            if (a[i] > a[i - 1])
            {
                tmp = a[i] - '0';
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                flag = 1;
            }
        }
    } while (flag);
}