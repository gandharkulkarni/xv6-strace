#include "kernel/types.h"
#include "user/user.h"
int main(void)
{
    int pid = fork();
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    if (pid == 0)
    {
        // Child process
        char *args[] = {"echo", "Hello, World!", 0};
        exec("echo", args);
        printf("exec failed\n"); // exec only returns if there is an err exit (1);
    }
    else
    {
        // Parent process
        wait(0); // wait for child to finish
    }
    exit(0);
}