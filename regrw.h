#ifndef REGRW_H
#define REGRW_H

// line count starts from zero
// all those functions work on memory buffers

//file must end with a newline

int _fpkg(char* buffer, char* name);
int* _fver(char* buffer, char* name);

char* _rmpkg(char** buffer, char* name);
char* _write(char* buffer, char* name, int ver, int sub);

int _streq(char* str1, char* str2, size_t size);

#define PKG_LEN 50

#endif