#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// function takes as parameters the mem locations of x and y 

void swap(int *a, int *b)
{
    // initializes a temporal variable with the value stored in the address that pointer a
    //is pointing to
    int tmp = *a;
    // dereferences a and assigns it the value that the pointer b is pointing to
    *a = *b;
    // dereferences b and assigns it the value thats on tmp
    *b = tmp;
}