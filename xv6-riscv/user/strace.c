#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(2, "Usage: strace command [args...]\n");
        exit(1);
    }

    // Prepare arguments for the command
    char *args[33];
    if (argc > 33)
        argc = 33; // Limit the number of arguments
    for (int i = 1; i < argc; i++)
        args[i - 1] = argv[i];
    args[argc - 1] = 0;
    // Execute the command
    if (fork() == 0)
    {
        // Turn on tracing for this process
        strace(1);
        exec(argv[1], args);
        fprintf(2, "strace: exec &s failed\n", argv[1]);
        exit(1);
    }
    else
    {
        wait(0);
    }
    exit(0);
}