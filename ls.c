#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
/*
    Simulates the behavior of the 'ls' command in Linux
    ls 
    List directory contents.
*/
int main()
{

    char working_directory[1024];
    getcwd(working_directory, sizeof(working_directory));    

    DIR *dir =opendir(working_directory);
    struct dirent*d;

    while ((d=readdir(dir))!=NULL)
    {
        printf("%s\n",d->d_name);
    }

    
    closedir(dir);

    return 0;
}