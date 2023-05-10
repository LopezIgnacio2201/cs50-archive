#include <cs50.h>
#include <stdio.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

int factorial(int number);

int main(void)
{
    int n = get_int("Type a number: ");

    printf("%i\n", factorial(n));
}

int factorial(int number)
{
    
    int factorial = 1;

    if (number == factorial)
    {
        return 1;
    }
                            
    for (int i = 1; i <= number ; i++)
    {
        factorial = i * factorial;
    }
    return factorial;
}

/* Recursive function solution, same outcome as loop

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }
    return number * factorial(number - 1);
}
*/