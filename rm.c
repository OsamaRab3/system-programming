#include<stdio.h>
/*
    Simulates the behavior of the 'rm' command in Linux
    rm file.txt
    If the file does not exist show  error 
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
        perror("rm");
        return 1;
    }
    remove(argv[1]);

    return 0;
}