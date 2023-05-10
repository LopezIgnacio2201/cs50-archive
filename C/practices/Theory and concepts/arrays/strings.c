#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    string t = "BYE!";

    printf("%s\n", s);
    printf("%c%c%c\n", s[0], s[1], s[2]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]); 
    printf("%i %i %i %i %i %i %i %i %i \n", s[0], s[1], s[2], s[3], t[0], t[1], t[2], t[3], t[4]);
    /* Strings are stored as an array of chars, each char has an ascii value associated
    "H" = 72 on ascii, etc etc. The last one, "0" or "NULL" is there to tell when the array ends 
    (and thus the computer knows when a string ends and another strings starts, to avoid errors) 
    a string or array of chars will always use the amount of bytes we declare (amount of chars) 
    + 1 byte to store null. */
}