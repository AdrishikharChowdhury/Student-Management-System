#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    int idx=1;
    stud *head=NULL;
    head = loadFromFiles();
    head=menu(head);
    return 0;
}