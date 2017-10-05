#include <stdio.h>

int foo_history(void);

int history = 0;

int main(int argc, char **argv)
{
    int x = 0;

    x = foo_history();
    
    printf("history = %d\n", history);

    return 0;
}
