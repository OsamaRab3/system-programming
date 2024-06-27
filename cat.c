#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file \n", argv[0]);
        return 1;
    }
    char buffer[1000];
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    if (fptr != NULL)
    {
        while (fgets(buffer, sizeof(buffer), fptr) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(fptr);
    }
    else 
    {
        printf("Failed to open the file: %s\n", argv[1]);
    }

    return 0;
}

