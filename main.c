#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/stat.h>

#include "Tokens/filelib.h"
#include "reglib.h"

int main(int argc, char* argv[])
{
    int status;
    char* buffer;
    FILE* reg;
        
    if((status = arg_chk(argc, argv)))
        return status;

    reg = fopen(REGISTER, "r"); // il file deve già esistere in /usr/share/zpm e dev'essre modificabile da tutti
    if(!reg)
    {
        return sys_err("Failed to read the file");
    }
    
    // load the file into the buffer
    buffer = loadfile(reg);
    fclose(reg);

    status = RD;

    if(_streq(argv[1], FPKG, FPKG_LEN))
    {
        char* out = selline(buffer, _fpkg(buffer, argv[2]), '\n');
        if(!out) {
            free(buffer);
            return fun_err();
        }   

        fputs(out, stdout);
        free(out);
    }
    else if(_streq(argv[1], FVER, FVER_LEN))
    {
        int* ver;

        ver = _fver(buffer, argv[2]);
        if(!ver){
            free(buffer);
            return fun_err();
        }
            
        
        printf("%d %d", ver[0], ver[1]);
    }
    else if(_streq(argv[1], PRINT, PRINT_LEN))
    {
        fputs(buffer, stdout);
    }    
    else if(_streq(argv[1], RMPKG, RMPKG_LEN))
    {
        buffer = _rmpkg(&buffer, argv[2]);
        
        if(!buffer) {
            free(buffer);
            return fun_err();
        }
            
        
        status = WR;
    }
    else if(_streq(argv[1], WRITE, WRITE_LEN))
    {
        _write(buffer, argv[2], atoi(argv[3]), atoi(argv[4]));
        status = WR;
    }

    // write changes if any
    if(status == WR)
    {
        reg = fopen(REGISTER, "w");
        savebuffer(reg, buffer);
        fclose(reg);
    }

    free(buffer);
    return 0;
}