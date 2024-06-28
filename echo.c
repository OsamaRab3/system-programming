#include <stdio.h>
#include <string.h>
/*
    Simulates the behavior of the 'echo' command in Linux
    echo txt
    print txt with newline
*/
int main(int argc, char *argv[])   // osamam rabea 
{
    for(int i=1;i<argc;i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}