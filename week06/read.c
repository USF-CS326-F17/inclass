#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    int i = 0;
    char c;
    
    while (1) {
        rv = read(0, &c , 1);
        if (rv <= 0 || c == '\n') {
            break;
        }
        buf[i] = c;
        i += 1;
    }
    buf[i] = '\0';

    return;
}

int main(int argc, char **argv)
{
    char buf[128];

    print_prompt();
    read_command_line(buf);
    printf("buf = %s\n", buf);
    
    return 0;
}
