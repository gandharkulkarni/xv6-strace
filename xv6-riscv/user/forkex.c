#include "kernel/types.h"
#include "kernel/stat.h"
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
        printf("child: pid = %d\n", getpid());
    }
    else
    {
        printf("parent: pid = %d, child pid = sd\n", getpid(), pid);
    }
    exit(0);
}