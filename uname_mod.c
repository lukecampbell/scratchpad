#include <sys/utsname.h>
#include <string.h>
#include <stdio.h>

int sysname(char *str, size_t len) {
    struct utsname name;
    if ( uname(&name)) {
        return -1;
    }
    strncpy(str,name.sysname,len);
    return 0;
}

