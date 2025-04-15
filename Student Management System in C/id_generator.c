#include <stdio.h>
#include <stdlib.h>
#include "student.h"

char *studentId(char *s)
{
    char *str;
    str=(char *)malloc(20*sizeof(char));
    unsigned long id=djb2(s);
    sprintf(str, "%lu", id);
    return str;
}

unsigned long djb2(const char *str) 
{
    unsigned long hash = 5381;
    int c;
    while ((c=*str++)) {
        hash=((hash<<5)+hash)+c;
    }
    return hash % 10000000000;
}