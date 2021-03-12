# NAME
reglib - interface for the zpm packages registers

# SYNOPSIS
```bash
reglib [OPTION] [ARGUMENTS]
```

# DESCRIPTION
Write, read and manipulate the register which keeps track of the zpm packages installed on the system.  

## Reading options
fpkg [NAME] - find package  
fver [NAME] - find version  
print - print out the whole file

## Writing options
write [NAME] [VERSION] [SUBVERSION] - register a new progam  
rmpkg [NAME] - remove package by name

# Exit status
` 0` if there wasn't any error  
`-1` if we enter an implausible number of arguments  
`-2` if we enter a command which doesn't exist  
`-3` if a function failed to execute its task  
`-4` if some preparation task failed

# File
The file on which the program works is `/usr/share/zpm/zpm-reg`. The format resembles the following example:
```
name:ver.sub
name:ver.sub
name:ver.sub

```
*Note: the file must end in a newline.*

# Author
Written by Giovanni Zaccaria.