#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include<string.h>

void updateEntry(stud *node)
{
    int choice;
    char id[20];
    printf("Enter the Unique ID you want to update: ");
    scanf("%s",id);
    node=findNode(id,node);
    if(node==NULL)
    {
        printf("ID not found returning to main menu...\n");
        getchar();
        return ;
    }
    printf("Enter the attribute you want to update:\n");
    printf("1. Name\n");
    printf("2. Standard\n");
    printf("3. Section\n");
    printf("4. Roll No.\n");
    printf("5. Date of Birth\n");
    printf("6. Phone Number\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the updated name: ");
            getchar();
            scanf("%[^\n]",node->name);
            break;
        case 2:
            printf("Enter your updated standard: ");
            scanf("%d",&node->standard);
            break;
        case 3:
            printf("Enter your updated section: ");
            scanf(" %c",&node->section);
            break;
        case 4:
            printf("Enter your updated roll no: ");
            scanf("%d",&node->roll);
            break;
        case 5:
            printf("Enter your updated date of Birth (DD/MM/YYYY): ");
            scanf("%[^\n]",node->dob);
            break;
        case 6:
            printf("Enter your updated phone number: ");
            scanf("%s",node->phn);
            break;
        default:
            printf("Couldn't find the attribute you are looking for....");
    }
    printf("The attribute has been updated\n");
    return;
}

stud *findNode(char id[],stud *head)
{
    while(strcmp(id,head->id)!=0 && head!=NULL)
    {
        head=head->next;
    }
    return head;
}

void searchNode(stud *head) {
    int ch, standard, roll;
    stud *node;
    char id[20], name[50], section, dob[20], phn[15];

    while (1) {
        printf("\nWhat is the key to find the required data:\n");
        printf("1. By ID\n");
        printf("2. By Name\n");
        printf("3. By Standard\n");
        printf("4. By Section\n");
        printf("5. By Roll No.\n");
        printf("6. By Date of Birth\n");
        printf("7. By Phone Number\n");
        printf("Your choice: ");
        scanf("%d", &ch);
        getchar(); // Flush newline

        node = head; // Reset pointer for each search

        switch (ch) {
            case 1:
                printf("Enter the ID you want to find: ");
                scanf("%s", id);
                while (node != NULL && strcmp(id, node->id) != 0)
                    node = node->next;
                break;

            case 2:
                printf("Enter the name you want to find: ");
                getchar(); // Flush leftover newline
                scanf("%[^\n]", name);
                while (node != NULL && strcmp(name, node->name) != 0)
                    node = node->next;
                break;

            case 3:
                printf("Enter the standard you want to find: ");
                scanf("%d", &standard);
                while (node != NULL && standard != node->standard)
                    node = node->next;
                break;

            case 4:
                printf("Enter the section you want to find: ");
                scanf(" %c", &section);
                while (node != NULL && section != node->section)
                    node = node->next;
                break;

            case 5:
                printf("Enter the roll number you want to find: ");
                scanf("%d", &roll);
                while (node != NULL && roll != node->roll)
                    node = node->next;
                break;

            case 6:
                printf("Enter the Date of Birth (DD/MM/YYYY): ");
                scanf("%s", dob);
                while (node != NULL && strcmp(dob, node->dob) != 0)
                    node = node->next;
                break;

            case 7:
                printf("Enter the phone number you want to find: ");
                scanf("%s", phn);
                while (node != NULL && strcmp(phn, node->phn) != 0)
                    node = node->next;
                break;

            default:
                printf("Invalid choice. Try again.\n");
                continue;
        }

        if (node == NULL) {
            printf("No matching student found.\n");
        } else {
            print(node, 1);
        }

        break; // exit loop after one search
    }
}