#define MAX_SIZE 25
#define MAX_STR 256
#include <ctype.h>
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
void enterCredential(char *array)
{
    char buffer = '\0';
    for (int i = 0; i < MAX_SIZE; i++)
    {
        buffer = getchar();
        if ('\n' == buffer)
        {
            array[i] = ' ';
            break;
        }
        else
        {
            array[i] = buffer;
        }
    }
}
void clearArray2(int *array, int size1, int size2)
{
    for ( size_t i = 0; i < size1; i++ )
    {
        for ( size_t j = 0; j < size2; j++ ) array[i * size2 + j] =  0;
    }
}
int transfer(int *teleport)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer)-1]='\0';
    int k = strlen(buffer);
    for(int i=0; i<k; i++)
    {
        if(!isdigit(buffer[i]))
        {
            printf("Îøèáêà\n");
            return 1;
        }
    }
    *teleport = atoi(buffer);
    return 0;
}