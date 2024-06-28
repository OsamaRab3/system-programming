#include <stdio.h>
#include <string.h>
/*
    Simulates the behavior of the 'wc' command in Linux
    Count words, lines, and characters in files  
*/

int main(int argc,  char *argv[])
{
    char buffer[1024];
    int countword=0,countchar=0,countline=0,in_word=0;
    char c;
    if (argc < 2)
    {
        printf("Usage: %s <file> \n", argv[0]);
        return 1;
    }
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }
   while ((c = fgetc(fptr)) != EOF)
    {
        countchar++;
        if (c == '\n')
            countline++;
        if (c==' '||c=='\t'||c=='\n')
            in_word=0;
        else if (!in_word)
        {
            in_word = 1;
            countword++;
        }
    }

    printf("%d %d %d %s\n ",countline,countword,countchar,argv[1]);
    fclose(fptr);

    return 0;
}