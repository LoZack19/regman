# Richieste

## Lettura
```c
int fpkg(char* name); // out: "$name:$ver" err: "0"
int fver(char* name); // out: "$ver $subver" err: "0"
int print();          // out: $file err: "0"
```

## Cancellazione
```c
int rmpkg(char* name); // out: "$return"
```

## Scrittura
```c
int write(char* name, int ver, int subver); // out: "$return"
```

# File
The file contains a number of packages and versions in the format:
```
name:ver.sub
name:ver.sub
name:ver.sub

```
The file **must end in a newline**!