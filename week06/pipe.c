/* pipe.c - example of using a pipe */

/* Parent writes to child via pipe. */

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
    char buf[100];
    int fildes[2];

    pipe(fildes);

    id = fork();

    if (id == 0) {
        /* We are in the child. */
        
        /* Close write end of pipe. */
        close(fildes[1]);

        /* Read data from pipe. */
        if ((count = read(fildes[0], buf, 100)) < 0) {
            /* Write error message to stderr. */
            write(2, "Cannot read from pipe\n", 22);
            exit(1);
        }
        printf("buf[] = %s\n", buf);
        
        /* Close read end of pipe. */
        close(fildes[0]);
        
        exit(0);
    } else {
        /* We are in the parent. */

        /* Close read end of pipe. */
        close(fildes[0]);

        /* Write data to pipe. */
        if (write(fildes[1], "Hello child!", 13) < 0) {
            write(2, "Cannot write to pipe\n", 21);
        }
        /* Close write end of pipe. */
        close(fildes[1]);

        id = wait(NULL);
    }

    return 0;
}




