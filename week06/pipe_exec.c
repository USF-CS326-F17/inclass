/* pipe-exec.c - use a pipe to send "input" to another program */

/* Redirect stdin of a process to the read end of a pipe */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    pid_t id;
    int count;
    int fildes[2];

    /* Create a pipe. */
    /* This will create two file descriptors in the file descriptor table. */
    pipe(fildes);

    id = fork();
    
    if (id == 0) {
        /* We are in the child */

        /* Close stdin. */
        close(0);

        /* Put the read end of the pipe into stdin (0) file descriptor slot. */
        dup(fildes[0]);

        /* Close write end of pipe. */
        close(fildes[0]);        

        /* Close write end of pipe. */
        close(fildes[1]);

        if (execlp("sort", "sort", NULL) < 0) {
            write(2, "execlp failed\n", 14);
            exit(1);
        }

    } else {
        /* We are in the parent. */

        /* Close read end of pipe. */
        close(fildes[0]);

        /* Send some data to sort. */
        write(fildes[1], "bbb\n", 4);
        write(fildes[1], "ttt\n", 4);
        write(fildes[1], "aaa\n", 4);

        /* Close write end to tell sort we are done */
        close(fildes[1]);

        /* Wait for child to exit. */
        id = wait(NULL); 
    }

    return(0);
}
