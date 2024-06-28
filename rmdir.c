#include<stdio.h>
/*
    Simulates the behavior of the 'rmdir' command in Linux
    rmdir <dir>   remove empty directories.
    If the <dir> does not exist show  error 
    if found delete it 
*/
int main(int argc,char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    if (remove(argv[1]) != 0)
    {
        perror("rmdir");
        return 1;
    }

    return 0;
}