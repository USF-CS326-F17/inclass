/* readdir-example.c - UNIX system calls to read directory contents. */

/* Look for name from argv[1] in current directory. */

#include<dirent.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    DIR *dirp;
    struct dirent *dp;
    int len;
    bool found = false;

    /* Open the current directory. */
    dirp = opendir(".");
    if (dirp == NULL) {
        printf("Cannot opendir()\n");
        exit(-1);
    }
            
    /* Read all directory entires lookinf for name */
    while ((dp = readdir(dirp)) != NULL) {
        printf("%s\n", dp->d_name);
    }
    closedir(dirp);

    return 0;
}

