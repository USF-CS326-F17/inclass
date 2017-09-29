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
    char *name = argv[1];
    int len;
    bool found = false;

    /* Open the current directory. */
    dirp = opendir(".");
    if (dirp == NULL) {
        printf("Cannot opendir()\n");
        exit(-1);
    }
            
    len = strlen(name);
    
    /* Read all directory entires lookinf for name */
    while ((dp = readdir(dirp)) != NULL) {
        if (strlen(dp->d_name) == len && strcmp(dp->d_name, name) == 0) {
            found = true;
       }
    }
    closedir(dirp);

    if (found) {
        printf("Found %s in current directory.\n", name);
    } else {
        printf("Cannot find %s in current directory.\n", name);
    }

    return 0;
}

