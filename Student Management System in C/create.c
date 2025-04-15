#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include<string.h>

stud *create(stud *head)
{
    head=(stud *)malloc(sizeof(stud));
    head->next=NULL;
    printf("Enter the student data below: \n");
    getchar();
    printf("Name: ");
    scanf("%[^\n]",head->name);
    printf("Enter your standard: ");
    scanf("%d",&head->standard);
    getchar();
    printf("Section: ");
    scanf(" %c",&head->section);
    printf("Roll no: ");
    scanf("%d",&head->roll);
    getchar();
    printf("Date of Birth (DD/MM/YYYY): ");
    scanf("%[^\n]",head->dob);
    getchar();
    printf("Phone number: ");
    scanf("%s",head->phn);
    getchar();
    char *id = studentId(head->name);
    strncpy(head->id, id, 20);
    getchar();
    return head;
}

stud *multipleEntries(stud *head)
{
    int i,n;
    stud *head1=head,*node;
    printf("Enter the no. of entries you want to enter: ");
    scanf("%i",&n);
    if(head==NULL)
        {
            head=create(head);
            head1=head;
            n-=1;
        }
    else{
        while(head1->next!=NULL)
        {
            head1=head1->next;
        }
    }
    for(i=0;i<n;i++)
    {
        node=create(node);
        head1->next=node;
        head1=node;
    }
    return head;
}