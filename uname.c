#include <stdio.h>

/*
    Simulates the behavior of the 'uname' command in Linux
    uname => Get basic information about the OS
*/
int main()
{
    #ifdef _WIN32
        printf("Windows\n");
    #elif __linux__
        printf("Linux\n");
    #elif __APPLE__
        printf("MacOS\n");
    #elif __unix__ 
        printf("Unix\n");
    #else
        printf("Unknown OS\n");
    #endif
    return 0;
}
