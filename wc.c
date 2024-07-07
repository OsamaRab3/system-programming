#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
    Simulates the behavior of the 'wc' command in Linux
    Count words, lines, and characters in files
*/

int main(int argc, char *argv[])
{
    char buffer[1024];
    int countword = 0, countchar = 0, countline = 0, in_word = 0;
    char c;
    if (argc < 2)
    {
        printf("Usage: %s [-l|-w|-m] <file>\n", argv[0]);
        return 1;
    }

    char option='\0';
    int file_index = 1;
    if (argc == 3)
    {
        file_index=2;
        if (strcmp(argv[1], "-l") == 0)
            option = 'l';
        else if (strcmp(argv[1], "-w") == 0)
            option = 'w';
        else if (strcmp(argv[1], "-m") == 0)
            option = 'm';
        else
        {
            printf("Invalid option: %s\n", argv[1]);
            return 1;
        }
    }


    FILE *fptr = fopen(argv[file_index], "r");
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
        if (isspace(c))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            countword++;
        }
    }
    // Increment line count if the last character is not a newline
    if (countchar > 0 && c != '\n')
    {
        countline++;
    }


    switch (option)
    {
    case 'l':
        printf("%d  %s\n", countline, argv[file_index]);
        break;
    case 'w':
        printf("%d %s\n", countword, argv[file_index]);
        break;
    case 'm':
        printf("%d %s\n", countchar, argv[file_index]);
        break;

    default:
        printf("%d %d %d %s\n", countline, countword, countchar, argv[file_index]);
        break;
    }

    fclose(fptr);

    return 0;
}