#include<stdio.h>
int main(int argc,char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    remove(argv[1]);

    return 0;
}