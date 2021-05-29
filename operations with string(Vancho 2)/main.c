#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define max_size 30
#define result 256

void enterGroup(char* group)    //функция ввода группы с клавиатуры
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
void clearArray(char* array, int array_size)    //функция чистки массива, указываем название массива и его размер
{
    for (int i=0; i<array_size; i++)
    {
        array[i]='\0';
    }
}
void enterArrayName(char* array)    //функция для тупого ввода фио с клавиатуры, указываем название массива
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
int checkArrayName(char* array)    //функция проверки фио
{
    int k = strlen(array);
    k--; //убирает последний элемент массива, который служит пробелом после каждого элемента фио
    for (int i=0; i<k; i++)
    {
        if(!isalpha(array[i]))
        {
            printf("Ошибка, повторите попытку\n");
            clearArray(array, strlen(array));
            return 0;
        }
    }
    return 1;
}
void checkClass(char* array)    //функция для проверки первой буквы фио на разряд
{
    if (islower(array[0]))
    {
        array[0]=toupper(array[0]);
    }
}
void printArray(char* array)    //вывод массива
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
    printf("Нажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
    do
    {
        scanf("%d", &file);
        switch(file)
        {
        case 1:
            printf("Задайте путь к рабочему файлу: ");
            scanf("%s", &TargetFile);
            NameFile = fopen(TargetFile,"r");
            if(NameFile == 0)
            {
                printf("Файл не найден, попробуйте ещё раз или создайте новый рабочий файл\n");
                printf("Нажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
                errorCode = 1;
            }
            else
            {
                printf("Файл найден\n");
                errorCode = 0;
            }
            fclose(NameFile);
            break;
        case 2:
            printf("Укажите полный путь к создаваемому файлу: ");
            scanf("%s", &TargetFile);
            NameFile = fopen(TargetFile,"w");
            printf("Файл успешно создан\n");
            fclose(NameFile);
            errorCode = 0;
            break;
        default:
            printf("Ошибка, повторите попытку\nНажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
        }if(errorCode==0) break;
    }while(file!=1||file!=2);
    printf("Меню:\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
    do
    {
        scanf("%d", &operation);
        getchar(); // пожирает перенос строки
        printf("\n");
        switch(operation)
        {
        case 1:
            printf ("Введите фамилию студента на английском\n");
            do
            {
                enterArrayName(surName);
            }while(checkArrayName(surName)==0);
            printf ("Введите имя студента на английском\n");
            do
            {
                enterArrayName(name);
            }while(checkArrayName(name)==0);
            printf ("Введите отчество студента на английском\n");
            do
            {
                enterArrayName(middleName);
            }while(checkArrayName(middleName)==0);
            checkClass(surName);
            checkClass(name);
            checkClass(middleName);
            strcat(massive, "Студент ");
            strcat(massive,surName);
            strcat(massive,name);
            strcat(massive,middleName);
            printf("Введите группу\n"); // M30-135B-20
            enterGroup(group);
            while(!isalpha(group[0])||!isalpha(group[7])||!isdigit(group[1])||!isalpha(group[2])||!isdigit(group[4])||!isdigit(group[5])||!isdigit(group[6])||!isdigit(group[9])||!isdigit(group[10]))
            {
                clearArray(group, max_size);
                enterGroup(group);
            }
            strcat(massive, "группа ");
            strcat(massive, group);
            char numberCourse[2];
            numberCourse[0]=group[4];
            strcat(massive, numberCourse);
            strcat(massive," курс.");
            NameFile = fopen(TargetFile,"a");
            fprintf(NameFile,massive);
            fprintf(NameFile,"\n");
            fclose(NameFile);
            clearArray(surName, max_size);
            clearArray(name, max_size);
            clearArray(middleName, max_size);
            clearArray(group,max_size);
            clearArray(massive, result);
            printf("\nМеню:\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
            break;
        case 2:
            printf("Список студентов:\n");
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
            printf("\nМеню:\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
            break;
        case 3:
            NameFile = fopen(TargetFile, "w");
            fclose(NameFile);
            printf("Меню:\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
            break;
        case 4:
            errorCode = 1;
            printf("Нажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
            do
            {
                scanf("%d", &file);
                switch(file)
                {
                case 1:
                    printf("Задайте путь к рабочему файлу: ");
                    scanf("%s", &TargetFile);
                    NameFile = fopen(TargetFile,"r");
                    if(NameFile == 0)
                    {
                        printf("Файл не найден, попробуйте ещё раз или создайте новый рабочий файл\n");
                        printf("Нажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
                        errorCode = 1;
                    }
                    else
                    {
                        printf("Файл найден\n");
                        errorCode = 0;
                    }
                    fclose(NameFile);
                    break;
                case 2:
                    printf("Укажите полный путь к создаваемому файлу: ");
                    scanf("%s", &TargetFile);
                    NameFile = fopen(TargetFile,"w");
                    printf("Файл успешно создан\n");
                    fclose(NameFile);
                    errorCode = 0;
                    break;
                default:
                    printf("Ошибка, повторите попытку\nНажмите (1), чтобы ввести путь к рабочему файлу\nНажмите (2), чтобы создать рабочий файл\n");
                }if(errorCode==0) break;
            }while(file!=1||file!=2);
            printf("\nМеню:\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("\nОшибка, повторите попытку\n(1) - добавить студента\n(2) - вывести список студентов\n(3) - очистка файла\n(4) - изменить рабочий файл\n(0) - закрыть программу\n\n");
            break;
        }
    }while(operation!=0);
    return 0;
}