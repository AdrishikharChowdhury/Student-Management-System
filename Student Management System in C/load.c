#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "student.h"

int startsWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

int endsWith(const char *str, const char *suffix) {
    int len_str = strlen(str);
    int len_suffix = strlen(suffix);
    if (len_suffix > len_str) return 0;
    return strcmp(str + len_str - len_suffix, suffix) == 0;
}

stud *loadFromFiles() {
    struct dirent *entry;
    DIR *folder = opendir(".");
    if (folder == NULL) {
        printf("Could not open current directory.\n");
        return NULL;
    }

    stud *head = NULL, *tail = NULL;
    char line[100];

    while ((entry = readdir(folder)) != NULL) {
        if (startsWith(entry->d_name, "student_") && endsWith(entry->d_name, ".txt")) {
            FILE *fp = fopen(entry->d_name, "r");
            if (fp == NULL) {
                printf("Could not open file %s\n", entry->d_name);
                continue;
            }

            stud *node = (stud *)malloc(sizeof(stud));
            node->next = NULL;

            // Parse the file
            fgets(line, sizeof(line), fp); // ====
            fgets(line, sizeof(line), fp); // Student: <ID>
            sscanf(line, "Student: %s", node->id);

            fgets(line, sizeof(line), fp); // ====
            fgets(line, sizeof(line), fp); // Name
            sscanf(line, "Name: %[^\n]", node->name);

            fgets(line, sizeof(line), fp); // Standard
            sscanf(line, "Standard: %dth", &node->standard);

            fgets(line, sizeof(line), fp); // Section
            sscanf(line, "Section: %c", &node->section);

            fgets(line, sizeof(line), fp); // Roll
            sscanf(line, "Roll no. %d", &node->roll);

            fgets(line, sizeof(line), fp); // DOB
            sscanf(line, "Date of Birth: %[^\n]", node->dob);

            fgets(line, sizeof(line), fp); // Phone
            sscanf(line, "Phone number: %[^\n]", node->phn);

            fclose(fp);

            // Append to list
            if (head == NULL)
                head = tail = node;
            else {
                tail->next = node;
                tail = node;
            }
        }
    }

    closedir(folder);
    printf("Student data loaded from all matching text files.\n");
    return head;
}
