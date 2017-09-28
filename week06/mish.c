#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUF_LEN 128
#define MAX_ARGS 128

/*
struct parsed_cmd {
    char *args[MAX_ARGS];
    int cmd_type;
    int redirect_pos;
}
*/

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

void parse_command_line(char *buf, char **args)
{
    int i = 0;
    
    args[i] = strtok(buf, " ");
    i = i + 1;
    while ((args[i] = strtok(NULL, " ")) != NULL) {
        i = i + 1;
    }
}

bool is_file_redirection(char **args)
{
    int i;
    bool rv = false;
    
    for (i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], ">") == 0) {
            rv = true;
        }
    }

    return rv;
}

void exec_simple_command(char **args)
{
    printf("exec simple command\n");
}

int main(int argc, char **argv)
{
    int rv;
    char buf[MAX_BUF_LEN];
    char *args[MAX_ARGS];
    int i;

    print_prompt();
    read_command_line(buf);
    parse_command_line(buf, args);

    if (is_file_redirection(args)) {
        printf("file redirection\n");
	
    /*
    } else if (is_pipe_redirection(args)) {
	     exec_pipe_redirection(args);
    */
    } else {
        /* is a simple command */
        exec_simple_command(args);
        printf("simple command\n");
    }

    for (i = 0; args[i] != NULL; i++) {
	    printf("args[%d] = %s\n", i, args[i]);
    }

    return 0;
}
