#include <stdio.h>
#include <unistd.h>

/*
    Simulates the behavior of the 'pwd' command in Linux
    pwd
    print name of current/working directory.
*/
int main()
{
    char working_directory[1024];
    if (getcwd(working_directory, sizeof(working_directory)) != NULL)
        printf("%s\n", working_directory);
    else{
    perror("getcwd() erorr ");
    return 1;
    }

    return 0;
}