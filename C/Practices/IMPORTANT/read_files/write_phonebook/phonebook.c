#include <cs50.h>
#include <stdio.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

int main(void)
{
    // creates a pointer to a file, pointer named file, fopen looks on directory
    //if the first parameter is found, and opens it, second parameter is the way
    //it interacts with the file, a for append

    FILE *file = fopen("phonebook.csv", "a");

    string name = get_string("Name: \n");
    string number = get_string("Number: \n");

    // writes to the file the strings stored in name and number

    fprintf(file, "%s,%s\n", name, number);

    // closes file to prevent memory leaks
    
    fclose(file);
}