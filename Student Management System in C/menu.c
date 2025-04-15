#include <stdio.h>
#include <stdlib.h>
#include "student.h"

stud *menu(stud *head)
{
    int choice;
    char id[20];
    stud *node,*head1;
    int loaded=0;
    while(1)
    {
        printf("\nOptions:\n");
        printf("1. Create Entries\n");
        printf("2. Update an Entry\n");
        printf("3. Delete an Entry\n");
        printf("4. Sort the entries\n");
        printf("5. Show a specific Entry\n");
        printf("6. Show the Entries\n");
        printf("7. Save the Entries in files\n");        
        printf("8. Save all the Entries in files\n");
        printf("9. Exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head=multipleEntries(head);
                break;
            case 2:
                if(head==NULL)
                {
                    printf("No Entry to update\n");
                    continue;
                }
                updateEntry(head);
                break;
            case 3:
                if(head==NULL)
                {
                    printf("No Entry to update\n");
                    continue;
                }
                head=deleteEntry(head);
                break;
            case 4:
                head=sortAll(head);
                break;
            case 5:
                searchNode(head);
                break;
            case 6:
                if(head==NULL)
                {
                    printf("No Entry to show\n");
                    continue;
                }
                printMultiple(head);
                break;
            case 7:
                saveSelector(head);
                break;
            case 8:
                saveAll(head);
                break;           
            case 9:
                printf("Do you want to save before exiting? (y/n): ");
                char opt;
                scanf(" %c", &opt);
                if (opt == 'y' || opt == 'Y') {
                    saveAll(head);
                }
                printf("Thank you for using this program...\n");
                exit(0);            
            default:
                printf("Wrong option try again\n");
        }
    }
    return head;
}