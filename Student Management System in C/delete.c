#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include<string.h>

stud *deleteEntry(stud *head)
{
    if(head==NULL)
    {
        printf("No data to delete\n");
        return head;
    }
    char id[20];
    printf("Enter the Unique ID you want to update: ");
    scanf("%s",id);
    if(strcmp(head->id,id)==0)
    {
        head=head->next;
        printf("Entry no. %s has been deleted\n",id);
        return head;
    }
    stud *head1=head;
    while(strcmp(head1->next->id,id)!=0 && head1!=NULL)
    {
        head1=head1->next;
    }
    if(head1==NULL)
    {
        printf("Entry Not Found. Returning to main menu....\n");
        return head;
    }
    head1->next=head1->next->next;
    printf("Entry no. %s has been deleted\n",id);
    return head;
}