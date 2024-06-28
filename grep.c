#include <stdio.h>
#include <string.h>
/*
    Simulates the behavior of the 'grep' command in Linux
    grep "pattern" file.txt
    print lines matching a pattern.
   
*/

int main(int argc,  char *argv[])
{
    char buffer[1024];
    int line=0;
    if (argc < 3)
    {
        printf("Usage: %s file \n", argv[0]);
        return 1;
    }
    FILE *fptr = fopen(argv[2], "r");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), fptr))
    {   line++;
        if (strstr(buffer, argv[1]) != NULL)
        {
            printf("Line %d: %s", line,buffer);
        }
    }
    fclose(fptr);

    return 0;
}