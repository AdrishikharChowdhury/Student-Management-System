#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void print(stud *head,int idx)
{
    printf("=========================\n");
    printf("Student No: %d\n",idx);
    printf("=========================\n");
    printf("Unique ID: %s\n",head->id);
    printf("Name: %s\n",head->name);
    printf("Standard: %dth\n",head->standard);
    printf("Section: %c\n",head->section);
    printf("Roll no. %d\n",head->roll);
    printf("Date of Birth: %s\n",head->dob);
    printf("Phone number: %s\n",head->phn);
    printf("\n");
}

void printMultiple(stud *head)
{
    int idx=1;
    stud *head1=head;
    if(head1==NULL)
    {
        printf("There is no data in the system\n");
        return;
    }
    while(head1!=NULL)
    {
        print(head1,idx++);
        head1=head1->next;
    }
}

void printSingle(stud *head)
{
    printf("=========================\n");
    printf("Student");
    printf("=========================\n");
    printf("Unique ID: %s\n",head->id);
    printf("Name: %s\n",head->name);
    printf("Standard: %dth\n",head->standard);
    printf("Section: %c\n",head->section);
    printf("Roll no. %d\n",head->roll);
    printf("Date of Birth: %s\n",head->dob);
    printf("Phone number: %s\n",head->phn);
    printf("\n");
}