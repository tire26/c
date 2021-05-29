#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iso646.h>
#include <ctype.h>
#include "function.c"
#include <windows.h>
#define MAX_SIZE 25
#define MAX_STR 256
#define NUM_SUBJECTS 15
int main()
{
    FILE *files = NULL;
    int break_cycle = 0, string_email = 0, sobaka = 0, size = 0, check = 0;
    float sum = 0.0, count = 0.0;
    char cycle;
    char buffer_array[MAX_STR];
    char buffer;
    struct StudentStruct
    {
        char all_string[MAX_STR];
        char fio[3 * MAX_SIZE];
        char num_Group[MAX_SIZE];
        char email[MAX_SIZE];
        char marks[MAX_STR];
        char middle_mark[NUM_SUBJECTS];
        int array[MAX_STR];
        char s_array[MAX_SIZE];
    };
    struct StudentStruct student;
    clearArray(student.middle_mark, 3);
    clearALL(student.all_string, student.fio, student.num_Group, student.marks, student.email);
    clearArray(student.s_array, MAX_SIZE);
    system("cls");
    do
    {
        do
        {

            printf("\nEnter information about student in file- 1\nClean out file - 2\nSee information in file - 3\nExit from programm - 4\n");
            printf("Choose option:  ");
            cycle = getche();
            printf("\n");
            while (isalpha(cycle))
            {
                printf("Wrong type, should be digit, try again - ");
                cycle = getche();
                printf("\n");
            }
            switch (cycle)
            {
            case '1':
            {
                fflush(stdin);
                clearALL(student.all_string, student.fio, student.num_Group, student.marks, student.email);
                count = 0;
                int i = 0;
                if ((files = fopen("student_list_file.txt", "a")) == NULL)
                {
                    perror("Error occured while opening student_list_file.txt");
                    exit(0);
                }
                printf("Enter your name, surname and patronymic, in type Ivan(name) Goncharov(surname) Sergeevich(patronymic) then put button enter\n");
                do
                {
                    count = 0;
                    do
                    {
                        buffer = getchar();
                        if (isalpha(buffer) || buffer == ' ' || buffer == '\n')
                        {
                            if (buffer == '\n')
                            {
                                student.fio[i] = '\0';
                            }
                            else
                            {
                                student.fio[i] = buffer;
                            }
                        }
                        else
                        {
                            buffer = '\0';
                            count = 1;
                        }
                        i++;
                    } while (!(buffer == '\n'));
                    if (count == 1)
                    {
                        i = 0;
                        clearArray(student.fio, 3 * MAX_SIZE);
                        printf("Was entered wrong symbol, try again\n");
                    }
                } while (count == 1);
                buffer = '\0';
                fflush(stdin);
                printf("Enter number of group\n");
                do
                {
                    for (int i = 0; i < 11; i++)
                    {

                        buffer = getchar();
                        student.num_Group[i] = buffer;
                    }
                } while (!isalpha(student.num_Group[0]) || !isalpha(student.num_Group[7]) || !isdigit(student.num_Group[1]) || !isdigit(student.num_Group[2]) || !isdigit(student.num_Group[4]) || !isdigit(student.num_Group[5]) || !isdigit(student.num_Group[6]) || !isdigit(student.num_Group[9]) || !isdigit(student.num_Group[10]));
                upperNumGroup(student.num_Group);
                fflush(stdin);
                printf("Enter your email\n");
                buffer = '\0';
                do
                {
                    buffer = '\0';
                    sobaka = 0;
                    i = 0;
                    do
                    {
                        buffer = getchar();
                        student.email[i] = buffer;
                        if (buffer == '@')
                        {
                            sobaka++;
                        }
                        i++;
                    } while (buffer != '\n');
                    string_email = strlen(student.email);
                    if ((student.email[0] != '@') && (student.email[string_email - 1] != '@') && (student.email[string_email - 2] != '@') && ((student.email[string_email - 3] == '.') || (student.email[string_email - 4] == '.')) && (student.email[string_email - 4] != '@') && (sobaka == 1))
                    {
                        count = 1;
                    }
                    else
                    {
                        clearArray(student.email, MAX_SIZE);
                        printf("Was entered wrong email, try again\n");
                    }
                } while (count == 0);
                fflush(stdin);
                printf("Enter marks of student\n");
                buffer = '\0';
                for (i = 0; i < MAX_STR; i++)
                {
                    buffer = getchar();
                    if (isdigit(buffer) || buffer == '\n')
                    {
                        if (buffer == '\n')
                        {
                            student.marks[i] = '\0';
                            i = MAX_STR;
                        }
                        else
                        {
                            student.marks[i] = buffer;
                            sum = sum + (student.marks[i] - '0');
                        }
                    }
                    else
                    {
                        i--;
                        printf("Was enetered wrong symbol, try again\n");
                    }
                }
                printf("Enter size of matrix\n");
                scanf("%i", &size);
                fflush(stdin);
                clearArrayInt(student.array, MAX_STR);
                printf("Enter elements of array\n");
                do
                {
                    for (int j = 0; j < size; j++)
                    {
                        fgets(buffer_array, MAX_SIZE, stdin);
                        for (i = 0; i < 256; i++)
                        {
                            if (isdigit(buffer_array[i]) || buffer_array[i] == '\n')
                            {
                                if (buffer_array[i] == '\n')
                                {
                                    i = 256;
                                }
                                else
                                {
                                    student.array[j] = atoi(buffer_array);
                                    i = 256;
                                }
                            }
                            else
                            {
                                printf("Was enetered not a digit\n");
                                check += 1;
                            }
                        }
                    }
                } while (check >= 1);
                do
                {
                    check = 0;
                    for (int i = 0; i < size; i++)
                    {
                        if (student.array[i] < student.array[i + 1])
                        {
                            check++;
                            swapNumbers(&student.array[i], &student.array[i + 1]);
                        }
                    }
                } while (check > 0);
                clearArray(buffer_array, MAX_STR);
                for (i = 0; i < size; i++)
                {
                    sprintf(buffer_array, "%d ", student.array[i]);
                    strcat(student.s_array, buffer_array);
                }
                count = strlen(student.marks);
                sprintf(student.middle_mark, "%f", sum / count);
                strcat(student.all_string, "Student:");
                strcat(student.all_string, student.fio);
                strcat(student.all_string, student.num_Group);
                strcat(student.all_string, " email of student:");
                strcat(student.all_string, student.email);
                strcat(student.all_string, " marks of student: ");
                strcat(student.all_string, student.marks);
                strcat(student.all_string, " Sort array ");
                strcat(student.all_string, student.s_array);
                fprintf(files, "%s\n", student.all_string);
                fclose(files);
                clearArray(student.all_string, MAX_STR);
                break;
            }
            break;
            case '2':
            {
                fflush(stdin);
                if ((files = fopen("student_list_file.txt", "w")) == NULL)
                {
                    perror("Error occured while opening student_list_file.txt");
                    exit(0);
                }
                fclose(files);
            }
            break;
            case '3':
            {
                if ((files = fopen("student_list_file.txt", "r")) == NULL)
                {
                    perror("Error occured while opening student_list_file.txt");
                    exit(0);
                }
                printf("List of students\n");
                while (!feof(files))
                {
                    fgets(student.all_string, MAX_SIZE, files);
                    if (!feof(files))
                    {
                        printArray(student.all_string);
                    }
                }
                fclose(files);
            }
            break;
            case '4':
            {
                break_cycle = 1;
            }
            break;
            default:
            {
                printf("Error, unidentified comand\nTry again - ");
            }
            break;
            }
        } while (!strchr("1234", cycle));
    } while (break_cycle == 0);
}