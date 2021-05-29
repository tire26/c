#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define max_size 30
#define result 256

void enterGroup(char* group)    //������� ����� ������ � ����������
{
    for (int i=0; i<max_size; i++)
    {
        group[i] = getchar();
        if(group[i]=='\n')
        {
            group[i] = ' ';
            break;
        }
    }
    group[0]=toupper(group[0]);
    group[2]=toupper(group[2]);
    group[7]=toupper(group[7]);
}
void clearArray(char* array, int array_size)    //������� ������ �������, ��������� �������� ������� � ��� ������
{
    for (int i=0; i<array_size; i++)
    {
        array[i]='\0';
    }
}
void enterArrayName(char* array)    //������� ��� ������ ����� ��� � ����������, ��������� �������� �������
{
    char buffer;
    for (int i=0; i<max_size; i++)
        {
            buffer = getchar();
            if(buffer == '\n')
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
int checkArrayName(char* array)    //������� �������� ���
{
    int k = strlen(array);
    k--; //������� ��������� ������� �������, ������� ������ �������� ����� ������� �������� ���
    for (int i=0; i<k; i++)
    {
        if(!isalpha(array[i]))
        {
            printf("������, ��������� �������\n");
            clearArray(array, strlen(array));
            return 0;
        }
    }
    return 1;
}
void checkClass(char* array)    //������� ��� �������� ������ ����� ��� �� ������
{
    if (islower(array[0]))
    {
        array[0]=toupper(array[0]);
    }
}
void printArray(char* array)    //����� �������
{
    int k = strlen(array);
    for (int i=0; i<k; i++)
        {
            printf("%c", array[i]);
        }
    if(array[k-1]!='\n')
    {
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL,"");
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    char surName[max_size]="";
    char name[max_size]="";
    char middleName[max_size]="";
    char group[max_size]="";
    char massive[result]="";
    char TargetFile[result]="";
    FILE *NameFile;
    int operation;
    int file;
    int errorCode = 1;
    printf("������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
    do
    {
        scanf("%d", &file);
        switch(file)
        {
        case 1:
            printf("������� ���� � �������� �����: ");
            scanf("%s", &TargetFile);
            NameFile = fopen(TargetFile,"r");
            if(NameFile == 0)
            {
                printf("���� �� ������, ���������� ��� ��� ��� �������� ����� ������� ����\n");
                printf("������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
                errorCode = 1;
            }
            else
            {
                printf("���� ������\n");
                errorCode = 0;
            }
            fclose(NameFile);
            break;
        case 2:
            printf("������� ������ ���� � ������������ �����: ");
            scanf("%s", &TargetFile);
            NameFile = fopen(TargetFile,"w");
            printf("���� ������� ������\n");
            fclose(NameFile);
            errorCode = 0;
            break;
        default:
            printf("������, ��������� �������\n������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
        }if(errorCode==0) break;
    }while(file!=1||file!=2);
    printf("����:\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
    do
    {
        scanf("%d", &operation);
        getchar(); // �������� ������� ������
        printf("\n");
        switch(operation)
        {
        case 1:
            printf ("������� ������� �������� �� ����������\n");
            do
            {
                enterArrayName(surName);
            }while(checkArrayName(surName)==0);
            printf ("������� ��� �������� �� ����������\n");
            do
            {
                enterArrayName(name);
            }while(checkArrayName(name)==0);
            printf ("������� �������� �������� �� ����������\n");
            do
            {
                enterArrayName(middleName);
            }while(checkArrayName(middleName)==0);
            checkClass(surName);
            checkClass(name);
            checkClass(middleName);
            strcat(massive, "������� ");
            strcat(massive,surName);
            strcat(massive,name);
            strcat(massive,middleName);
            printf("������� ������\n"); // M30-135B-20
            enterGroup(group);
            while(!isalpha(group[0])||!isalpha(group[7])||!isdigit(group[1])||!isalpha(group[2])||!isdigit(group[4])||!isdigit(group[5])||!isdigit(group[6])||!isdigit(group[9])||!isdigit(group[10]))
            {
                clearArray(group, max_size);
                enterGroup(group);
            }
            strcat(massive, "������ ");
            strcat(massive, group);
            char numberCourse[2];
            numberCourse[0]=group[4];
            strcat(massive, numberCourse);
            strcat(massive," ����.");
            NameFile = fopen(TargetFile,"a");
            fprintf(NameFile,massive);
            fprintf(NameFile,"\n");
            fclose(NameFile);
            clearArray(surName, max_size);
            clearArray(name, max_size);
            clearArray(middleName, max_size);
            clearArray(group,max_size);
            clearArray(massive, result);
            printf("\n����:\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
            break;
        case 2:
            printf("������ ���������:\n");
            char tempString[result];
            NameFile = fopen(TargetFile, "r");
            while(!feof(NameFile))
            {
                fgets(tempString, result, NameFile);
                if(!feof(NameFile))
                {
                    printArray(tempString);
                }
            }
            fclose(NameFile);
            printf("\n����:\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
            break;
        case 3:
            NameFile = fopen(TargetFile, "w");
            fclose(NameFile);
            printf("����:\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
            break;
        case 4:
            errorCode = 1;
            printf("������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
            do
            {
                scanf("%d", &file);
                switch(file)
                {
                case 1:
                    printf("������� ���� � �������� �����: ");
                    scanf("%s", &TargetFile);
                    NameFile = fopen(TargetFile,"r");
                    if(NameFile == 0)
                    {
                        printf("���� �� ������, ���������� ��� ��� ��� �������� ����� ������� ����\n");
                        printf("������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
                        errorCode = 1;
                    }
                    else
                    {
                        printf("���� ������\n");
                        errorCode = 0;
                    }
                    fclose(NameFile);
                    break;
                case 2:
                    printf("������� ������ ���� � ������������ �����: ");
                    scanf("%s", &TargetFile);
                    NameFile = fopen(TargetFile,"w");
                    printf("���� ������� ������\n");
                    fclose(NameFile);
                    errorCode = 0;
                    break;
                default:
                    printf("������, ��������� �������\n������� (1), ����� ������ ���� � �������� �����\n������� (2), ����� ������� ������� ����\n");
                }if(errorCode==0) break;
            }while(file!=1||file!=2);
            printf("\n����:\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("\n������, ��������� �������\n(1) - �������� ��������\n(2) - ������� ������ ���������\n(3) - ������� �����\n(4) - �������� ������� ����\n(0) - ������� ���������\n\n");
            break;
        }
    }while(operation!=0);
    return 0;
}