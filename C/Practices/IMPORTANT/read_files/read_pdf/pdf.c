#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // open file

    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // check if file exists   
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }
    
    // stands for unsigned integer of 8 bits, _t means it is its own data type
    // creates an array called buffer of size 4
    uint8_t buffer[4];
    // creates another array of size 4 with those values
    uint8_t signature[] = {37, 80, 68, 70};
    // reads the file, with each block being of size of 1 byte, reads up to 4 blocks, and stores them on buffer
    fread(buffer, 1, 4, file);
    fclose(file);

    // compares if buffer and signature is equal to know if its a pdf file or not
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF\n");
            return 0;
        }
    }

    printf("Likely a pdf\n");
    return 0;
}