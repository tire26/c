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
    int break_cycle = 1;
    int i = 0;
    char buffer;
    int num_subjects = 0;
    struct student_inf
    {
        char subject_name[MAX_SIZE][NUM_SUBJECTS];
        char name[MAX_SIZE];
        int marks[MAX_STR];
        int num_subjects[NUM_SUBJECTS];
    };
    struct student_inf student;
    clearArray(student.name, MAX_SIZE);
    int count = 0;
    int x = 0;
    do
    {
        do
        {
            printf("Choose option(1 - enterte info or 2 - extit from programm): ");
            x = getche();
            printf("\n");
            switch (x)
            {
            case '1':
            {
                fflush(stdin);
                printf("Entere your surname then put button enter\n");
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
                                student.name[i] = '\0';
                            }
                            else
                            {
                                student.name[i] = buffer;
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
                        clearArray(student.name, 3 * MAX_SIZE);
                        printf("Was entered wrong symbol, try again\n");
                    }
                } while (count == 1);
                fflush(stdin);
                do
                {
                    printf("Entere count of subjects: ");
                    num_subjects = getchar() - '0';
                    if (isalpha(num_subjects))
                        count = 1;
                    else
                        break;
                } while (count == 1);
                fflush(stdin);
                for (int j = 0; j < num_subjects; j++)
                {
                    do
                    {
                        printf("Entere name of subject: ");
                        i = 0;
                        count = 0;
                        do
                        {
                            buffer = getchar();
                            if (isalpha(buffer) || buffer == ' ' || buffer == '\n')
                            {
                                if (buffer == '\n')
                                {
                                    student.subject_name[i][j] = '\0';
                                }
                                else
                                {
                                    student.subject_name[i][j] = buffer;
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
                            clearArray2(student.subject_name, MAX_SIZE, NUM_SUBJECTS);
                            printf("Was entered wrong symbol, try again\n");
                        }
                    } while (count == 1);
                    fflush(stdin);
                }
            }
            break;
            case '2':
                break_cycle = 0;
                break;
            }
        } while (!strchr("12", x));
    } while (break_cycle == 1);
    return 0;
}