#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"


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
