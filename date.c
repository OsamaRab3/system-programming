#include <stdio.h>
#include <time.h>

/*
    Simulates the behavior of the 'date' command in Linux
    date
    display the current date and time

*/
int main()
{

    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    printf("current time is:  %d-%02d-%02d  %02d:%02d:%02d time zone is %s \n", 
    date.tm_year + 1900, 
    date.tm_mon + 1, date.tm_mday, date.tm_hour, 
    date.tm_min, date.tm_sec,date.tm_zone);

    return 0;
}