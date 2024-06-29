#include <stdio.h>

/*
    Simulates the behavior of the 'cp' command in Linux
    cp
    copy files and directories.
*/
#define size 1024

int main(int argc,char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s file \n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL)
    {
        // If destination file doesn't exist, create a new file
        destination = fopen(argv[2], "wb");
        if (destination == NULL) {
            perror("Error creating destination file");
            fclose(source);
            return 1;
        }
        
    }

    char buffer[size];
    size_t by_read;
    while((by_read=fread(buffer,1,sizeof(buffer),source))>0)
    {
        fwrite(buffer,1,by_read,destination);
    }

    fclose(source);
    fclose(destination);


    return 0;
}