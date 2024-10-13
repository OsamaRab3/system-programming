#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>

#define PATH 1024

/*
    Simulates the behavior of the 'cd' command in Linux
    cd ..
    cd Dir
    cd ~
*/
int cd(char *arg)
{
    char current_dir[PATH];

    // Case 1: Change to the home directory (cd ~)
    if (strcmp(arg, "~") == 0 || strcmp(arg, "~/") == 0)
    {
        struct passwd *pw = getpwuid(getuid());
        const char *home_dir = pw->pw_dir;
        if (chdir(home_dir) != 0)
        {
            perror("chdir to home directory failed");
            return 1;
        }
    }
    // Case 2: Change to the parent directory (cd ..)
    else if (strcmp(arg, "..") == 0)
    {
        if (chdir("..") != 0)
        {
            perror("chdir to parent directory failed");
            return 1;
        }
    }
    // Case 3: Change to a specified directory (cd Dir)
    else
    {
        if (chdir(arg) != 0)
        {
            perror("chdir to specified directory failed");
            return 1;
        }
    }

  
    if (getcwd(current_dir, sizeof(current_dir)) != NULL)
    {
        printf("Current directory: %s\n", current_dir);
    }
    else
    {
        perror("getcwd error");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    return cd(argv[1]);

    return 0; 
}
