#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Tokens/filelib.h"
#include "regrw.h"

char* _rmpkg(char** buffer, char* name)
{
    int line;
    char* tmp = *buffer;

    line = _fpkg(tmp, name);
    if(!~line)
        return NULL;
    
    tmp = delline(tmp, line, '\n');
    free(*buffer);
    *buffer = tmp;

    return tmp;
}

char* _write(char* buffer, char* name, int ver, int sub)
{
    char newpkg[PKG_LEN];

    sprintf(newpkg, "%s:%d.%d\n", name, ver, sub);
    strcat(buffer, newpkg);

    return buffer;
}