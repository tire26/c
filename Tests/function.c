#define MAX_SIZE 25
#define MAX_STR 256
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iso646.h>
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
void printArray(char *string)
{
    int size = 0;
    size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        printf("%c", string[i]);
    }
}
#include <stdio.h>

/**
 * @brief ������� ����� ����� ��� �������� ������ �����
 * 
 * @return int ��� ������ (0 ��� ������, 1 ���� ������)
 */
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    char action;

    printf("�������� ����� ����:\n1)������� ������������ ����.\n2)������� ����� ����/�������� ������������.\n");
    action = getchar();
    fflush(stdin);
    switch (action)
    {
    case '1': //����� ������������� �����
    {
        printf("������� ��� ������������� �����: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("������ �������� �����. ��������� �������.\n");
            return 1;
        }
        else
        {
            currFile = fopen(fileName, "r");
            printf("���� ������� ������.\n");
            fclose(currFile);
            return 0;
        }
        break;
    }
    case '2': //�������� ������ �����
    {
        printf("������� ��� �����, ������� ���������� �������: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            currFile = fopen(fileName, "w");
            fclose(currFile);
            printf("���� ������� ������.\n");
            return 0;
        }
        else
        {
            printf("����� ���� ��� ����������, ������� 1, ���� �� ������ �������� ���, ����� ����� ����� �������.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                fflush(stdin);
                printf("���� ������� ������.\n");
                return 0;
            }
            else
            {
                currFile = fopen(fileName, "r");
                fclose(currFile);
                fflush(stdin);
                printf("���� �� ��� ������.\n");
                return 0;
            }
        }
        break;
    }
    default: //������ ������ ������
    {
        // system("cls");
        printf("����������� ��������. ��������� �������.\n");
        return 1;
    }
    }
}