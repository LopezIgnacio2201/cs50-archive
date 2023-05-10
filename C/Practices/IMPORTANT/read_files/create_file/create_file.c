#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

int main(int argc, char *argv[])
{
    // check for improper usage
    if (argc != 2)
    {
        printf("Only 1 file can be open.\n");
        return 1;
    }

    // assign the strlen + 1 for nul char to a variable filename_length

 // int filename_length = strlen(argv[1] + 1);       this code is unnecesary 

    // create a new block of memory to store filename

 // char *filename = malloc(sizeof(char) * filename_length); unnecesary malloc, below is correct implementation 

    char *filename = argv[1];
    
    // copy argv[1] into block of memory for filename

 // sprintf (filename, "%s", argv[1]);        unnecesary to do

    // open new file under the name stored at filename
    FILE *new_file = fopen(filename, "w");
    if (new_file == NULL)
    {
        printf("Could not create file\n");
        fclose(new_file);
        return 1;
    }
    
    free(filename);
    fclose(new_file);
}