#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

stud *sortAll(stud *head)
{
    int ch;
    while (1)
    {
        printf("\nWhat is the key to sort the required data:\n");
        printf("1. By Name\n");
        printf("2. By Roll\n");
        printf("3. By Standard\n");
        printf("Your choice: ");
        scanf("%d", &ch);

        if (ch < 1 || ch > 3)
        {
            printf("Invalid choice. Please select 1 to 3.\n");
            continue;
        }
        break;
    }

    sortStudents(head, ch);
    return head;
}

void swapData(stud *a, stud *b)
{
    int tempInt;
    tempInt = a->standard;
    a->standard = b->standard;
    b->standard = tempInt;

    tempInt = a->roll;
    a->roll = b->roll;
    b->roll = tempInt;

    char tempChar = a->section;
    a->section = b->section;
    b->section = tempChar;

    char tempStr[100];

    strcpy(tempStr, a->id);
    strcpy(a->id, b->id);
    strcpy(b->id, tempStr);

    strcpy(tempStr, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempStr);

    strcpy(tempStr, a->dob);
    strcpy(a->dob, b->dob);
    strcpy(b->dob, tempStr);

    strcpy(tempStr, a->phn);
    strcpy(a->phn, b->phn);
    strcpy(b->phn, tempStr);
}


void sortStudents(stud *head, int mode)
{
    if (head == NULL || head->next == NULL)
    {
        printf("Not enough students to sort.\n");
        return;
    }

    for (stud *i = head; i != NULL; i = i->next)
    {
        for (stud *j = i->next; j != NULL; j = j->next)
        {
            int cmp = 0;
            switch (mode)
            {
                case 1:
                    cmp = strcmp(i->name, j->name) > 0;
                    break;
                case 2:
                    cmp = i->roll > j->roll;
                    break;
                case 3:
                    cmp = i->standard > j->standard;
                    break;
                default:
                    printf("Invalid sort mode.\n");
                    return;
            }

            if (cmp)
                swapData(i, j);
        }
    }

    printf("Students sorted successfully.\n");
}
