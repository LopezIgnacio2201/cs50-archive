#include <cs50.h>
#include <stdio.h>
#include <stdbool.h> // lets you use boolean values

int main(void)
{
    //useless code just to show different ways of increment a value

    int counter = 0;
    counter = counter + 1; //increments 1
    counter += 1; //increments 1 
    counter++; //increments 1
    counter--; //decrements 1

    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }

    for (int x = 0; x < 3; x++)
    {
        printf("meow\n");
    }

    // while (true) // this is an infinite loop  
    {
        // printf("meow\n");
    }
}