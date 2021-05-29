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
 * @brief функция ввода имени или создания нового файла
 * 
 * @return int код ошибки (0 нет ошибки, 1 есть ошибка)
 */
int chooseFile(char *fileName)
{
    FILE *currFile = NULL;
    char action;

    printf("Выберите пункт меню:\n1)Выбрать существующий файл.\n2)Создать новый файл/очистить существующий.\n");
    action = getchar();
    fflush(stdin);
    switch (action)
    {
    case '1': //выбор существующего файла
    {
        printf("Введите имя существующего файла: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            printf("Ошибка открытия файла. Повторите попытку.\n");
            return 1;
        }
        else
        {
            currFile = fopen(fileName, "r");
            printf("Файл успешно найден.\n");
            fclose(currFile);
            return 0;
        }
        break;
    }
    case '2': //создание нового файла
    {
        printf("Введите имя файла, который необходимо создать: ");
        enterCredential(fileName);
        if (fopen(fileName, "r") == NULL)
        {
            currFile = fopen(fileName, "w");
            fclose(currFile);
            printf("Файл успешно создан.\n");
            return 0;
        }
        else
        {
            printf("Такой файл уже существует, нажмите 1, если вы хотите очистить его, иначе любую другю клавишу.\n");
            if (getchar() == '1')
            {
                currFile = fopen(fileName, "w");
                fclose(currFile);
                fflush(stdin);
                printf("Файл успешно очищен.\n");
                return 0;
            }
            else
            {
                currFile = fopen(fileName, "r");
                fclose(currFile);
                fflush(stdin);
                printf("Файл не был очищен.\n");
                return 0;
            }
        }
        break;
    }
    default: //введен другой символ
    {
        // system("cls");
        printf("Незивестная операция. Повторите попытку.\n");
        return 1;
    }
    }
}