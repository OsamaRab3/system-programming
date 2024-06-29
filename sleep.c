#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>


/*
    Simulates the behavior of the 'sleep' command in Linux
*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <duration>\n", argv[0]);
        printf("Example durations: 10s, 2m, 1h, 1d\n");
        return 1;
    }

    char *timetosleep = argv[1];
    int length = strlen(timetosleep);  
    char suffix = timetosleep[length - 1];

    // Remove the suffix for conversion
    timetosleep[length - 1] = '\0'; 
    unsigned int value = atoi(timetosleep);
    unsigned int  seconds = 0;

    switch (suffix)
    {
    case 's':
        seconds = value;
        break;
    case 'm':
        seconds = value * 60;
        break;
    case 'h':
        seconds = value * 3600;
        break;
    case 'd':
        seconds = value * 86400;
        break;
    default:
        printf("Unknown time suffix: %c\n", suffix);
        return 1;
    }

    sleep(seconds);
    
    return 0;
}
