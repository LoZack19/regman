#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#include "reglib.h"

// Wrong number of arguments
int arg_err() { return ER_ARG; }

// Wrong command
int cmd_err() { return ER_CMD; }

// Error in function
int fun_err() { return ER_FUN; }

// Error in preparation task
int sys_err(char* msg) { return ER_SYS; }

int chk_dir(char* dir_path)
{
    DIR* dir = opendir(dir_path);
    if (dir) {
        closedir(dir);
        return 1;
    } else if (ENOENT == errno) {
        return 0;
    } else {
        return -1;
    }
}

int arg_chk(int argc, char* argv[])
{
    if(argc < MIN_ARG || argc > MAX_ARG)
        return arg_err();

    if(_streq(argv[1], WRITE, WRITE_LEN))
    {
        if(argc != 5)
            return arg_err();
    }
    else if(_streq(argv[1], FPKG, FPKG_LEN)     || 
            _streq(argv[1], FVER, FVER_LEN)     ||
            _streq(argv[1], RMPKG, RMPKG_LEN)   )
    {
        if(argc != 3)
            return arg_err();
    }
    else if(_streq(argv[1], PRINT, PRINT_LEN))
    {
        if(argc != 2)
            return arg_err();
    }
    else
        return cmd_err();
    
    return 0;
}