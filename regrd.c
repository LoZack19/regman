#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "regrw.h"

/*
    Find the row where a package is located.
    If it does not exist it returns -1.
*/
int _fpkg(char* buffer, char* name)
{
    unsigned int relpos;
    intptr_t counter = 0;

    relpos = (intptr_t) strstr(buffer, name);
    if(!relpos)
        return -1;
    
    relpos -= (intptr_t) buffer;

    for(intptr_t i = 0; i < relpos; i++)
        if(buffer[i] == '\n')
            ++counter;
    
    return counter;
}

int* _fver(char* buffer, char* name)
{
    char* pkg;
    int* ver = (int*) malloc(2*sizeof(int));

    pkg = strstr(buffer, name);
    if(!pkg)
        return NULL;
    
    pkg = strtok(pkg, ":");
    pkg = strtok(NULL, ":");
    sscanf(pkg, "%d%*c%d", &ver[0], &ver[1]);

    return ver;
}

int _streq(char* str1, char* str2, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        if(str1[i] != str2[i])
            return 0;
    return 1;
}