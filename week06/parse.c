#include <string.h>

#include "parse.h"

void parse_command_line(char *buf, char **args)
{
    int i = 0;
    
    args[i] = strtok(buf, " ");
    i = i + 1;
    while ((args[i] = strtok(NULL, " ")) != NULL) {
        i = i + 1;
    }
}
