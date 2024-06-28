#include <stdio.h>
/*
    Simulates the behavior of the 'touch' command in Linux
    touch file.txt
    If the file does not exist, it creates a new empty file
    if found exit
*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    const char *file = argv[1];

    FILE *fptr = fopen(file, "a");  
    if (fptr == NULL)   
    {

        fptr = fopen(file, "a");
        if (fptr == NULL)
        {
            perror("fopen");
            return 1;
        }
        fclose(fptr);
    }
    else
    {

        fclose(fptr);
    }

    return 0;
}
