#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "prompt.h"
#include "parse.h"
#include "commands.h"


void my_ctrl_c_handler(int sig)
{
    printf("Caught CTRL-C\n");
    return;
}


int main(int argc, char **argv)
{
    int rv;
    char buf[MAX_BUF_LEN];
    char *args[MAX_ARGS];
    int i;

    signal(SIGINT, my_ctrl_c_handler);

    while (1) {
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
    }

    return 0;
}
