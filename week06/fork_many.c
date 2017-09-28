/* fork1.c - example of using the fork system call */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t id;
    int x = 3;

    id = fork();

    printf("A\n");
        
    if (id == 0) {
        printf("B\n");
        id = fork();
        printf("C\n");
    }
    printf("D\n");

    return 0;
}
