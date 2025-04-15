#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include<string.h>

void saveAll(stud *head)
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(head!=NULL)
    {
        saveToFile(head);
        head=head->next;
    }
}

void saveSelector(stud *head) {
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    char id[20];
    printf("Enter the student id you want to save: ");
    scanf("%s", id);
    stud *head1 = head;
    while (head1 != NULL) {
        if (strcmp(id, head1->id) == 0) {
            saveToFile(head1);
            printf("Student with ID %s saved successfully.\n", id);
            return;
        }
        head1 = head1->next;
    }
    printf("Student with ID %s not found.\n", id);
}


void saveToFile(stud *head) {
    char filename[100];
    FILE *fp;
    sprintf(filename, "student_%s.txt", head->id);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }
    fprintf(fp, "=========================\n");
    fprintf(fp, "Student: %s\n", head->id);
    fprintf(fp, "=========================\n");
    fprintf(fp, "Name: %s\n", head->name);
    fprintf(fp, "Standard: %dth\n", head->standard);
    fprintf(fp, "Section: %c\n", head->section);
    fprintf(fp, "Roll no. %d\n", head->roll);
    fprintf(fp, "Date of Birth: %s\n", head->dob);
    fprintf(fp, "Phone number: %s\n", head->phn);
    fprintf(fp, "\n");
    fclose(fp);
    printf("Student record saved/updated to file: %s\n", filename);
}