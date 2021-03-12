#ifndef REGMAN_H
#define REGMAN_H

// constants
#define REGISTER    "/usr/share/zpm/zpm-reg"
#define REG_DIR     "/usr/share/zpm"
#define MIN_ARG     2
#define MAX_ARG     5

// errors
#define PROG_ERR    '!'
#define FUN_ERR     '#'
#define SUCCESS     '+'

// commands
#define FPKG        "fpkg"
#define FPKG_LEN    5
#define FVER        "fver"
#define FVER_LEN    5
#define PRINT       "print"
#define PRINT_LEN   6
#define RMPKG       "rmpkg"
#define RMPKG_LEN   6
#define WRITE       "write"
#define WRITE_LEN   6

// status
#define RD          0
#define WR          1

// errors
#define ER_ARG      -1
#define ER_CMD      -2
#define ER_FUN      -3
#define ER_SYS      -4

#include "regrw.h"

int arg_err();  // wrong number of arguments
int cmd_err();  // wrong command
int fun_err();  // error in function
int sys_err(char* msg);     // error in preparation tasks
int chk_dir(char* dir);     // check if dir exists
int arg_chk(int argc, char* argv[]);    // check correct number of arguments

#endif