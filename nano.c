#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
    Simulates the behavior of the 'nano' command in Linux
    nano file.txt
    If the file does not exist, it creates a new empty file mode append
    if found read and append it for write
*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    char buffer[1024];
    const char *file = argv[1];

    FILE *fptr = fopen(file, "a+");

    printf("Welcome to nano \n");
    printf("if you want exit print exit\n\n");

    // Read and print existing content
    rewind(fptr);
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }
    // write a new content
    while (true)
    {
        fgets(buffer, sizeof(buffer), stdin);

        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) ;
        }

       
        if (buffer[0] == '\0')
            continue;

        
        if (strcmp(buffer, "exit") == 0)
            break;

        fputs(buffer, fptr);
        fputs("\n",fptr);
    }

    fclose(fptr);
    return 0;
}
