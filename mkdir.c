#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/*
    Simulates the behavior of the 'mkdir' command in Linux
    mkdir <dir_name>
    Creates a new directory with the specified name and sets permissions to 0777.

*/

int main(int argc,char*argv[])
{


    if (argc<2)
    {
        printf("Usage: %s <dir> \n",argv[0]);
        return 1;
    }
    int result =mkdir(argv[1],0777);
    if(result !=0)
    {
        perror("cannot creating directory");
    }

    return 0;
}