#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string letters = "";
    
    // Loop through all the command line arguments
    for (int i = 1; i < argc && argv[i]; i++)
    {
        // Append the first character of the argument to the string
        letters = letters + argv[i][0];
    }

    printf("%s\n", letters);
}

// Code SHOULD be functional, though, for some weird reason it throws me a very weird 
// seg fault error, probably some library is corrupted. Will try to update the system,
// software, or libraries.