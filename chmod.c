#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
    Simulates the behavior of the 'chmod' command in Linux
    Changes the permissions of a file or directory to the specified mode.

    chmod filename 777

    The first digit represents the owner's permissions.
    The second digit represents the group's permissions.
    The third digit represents others' (world) permissions.

    Each digit can be a combination of the following values:
    4 (read permission)
    2 (write permission)
    1 (execute permission)
    0 (no permission)

*/

int main(int argc, char *argv[])

{

    if (argc < 3)
    {
        printf("error\n");
        return -1;
    }


    unsigned int mod = atoi(argv[2]);
    if (chmod(argv[1], mod) != 0)
    {
        perror("Error");
        return -1;
    }

    return 0;
}

