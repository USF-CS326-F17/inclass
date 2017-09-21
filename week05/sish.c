/* sish.c - simple shell */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_CMD_LEN 512

void read_line(char *line)
{
    char buf[1];
    int i = 0;
    
    while(read(0, buf, 1) > 0) {
        line[i] = buf[0];
        i = i + 1;

        if (line[i-1] == '\n') {
            break;
        }

        if (i > (MAX_CMD_LEN - 1)) {
            break;
        }
    }
    line[i] = '\0';

    return;
}

void print_prompt(void)
{
    write(1, "$ ", 2);
}

bool process_one_command(void)
{
    bool done = false;
    
    char buf[MAX_CMD_LEN];

    print_prompt();
    read_line(buf);
    printf("cmd: %s\n", buf);
    if (buf[0] == '*') {
        done = true;
    }

    return done;
}

int main(int argc, char **argv)
{
    bool done = false;

    while (!done) {
        done = process_one_command();
    }
    
    return 0;
}

