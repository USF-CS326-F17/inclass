#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "prompt.h"

void print_prompt(void)
{
    int rv;
    
    /* Output prompt */
    rv = write(1, "$ ", 2);
    if (rv < 0) {
        printf("write() failed.\n");
        exit(-1);
    }
}

void read_command_line(char *buf)
{
    int rv;
    
    rv = read(0, buf, (MAX_BUF_LEN-1));
    if (rv < 0) {
        printf("read() failed.\n");
        exit(-1);
    }
    buf[rv] = '\0';
}
