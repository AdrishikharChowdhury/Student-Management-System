#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char id[20];
    char name[50];
    int standard;
    char section;
    int roll;
    char dob[20];
    char phn[15];
    struct Student *next;
} stud;

stud *create(stud *head);
void print(stud *head,int);
stud *multipleEntries(stud *);
void printMultiple(stud *);
char *studentId(char *);
unsigned long djb2(const char *);
void updateEntry(stud *);
stud *findNode(char id[],stud *);
stud *menu(stud *);
stud *deleteEntry(stud *);
void printSingle(stud *);
void saveToFile(stud *);
void saveSelector(stud *);
void saveAll(stud *);
void searchNode(stud *);
stud *loadFromFiles();
stud *sortAll(stud *);
void sortStudents(stud *, int );
void swapData(stud *, stud *);

#endif