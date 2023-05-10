#include <cs50.h>
#include <stdio.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

int collatz(int number);

int main(void)
{
    int n = get_int("Number: \n");
    printf("Count: %i \n", collatz(n));
}

int collatz(int number)
{
    int count = 0;
    if (number == 1)
    {
        return 1;
    }
    else
    {
        do
        {
            if (number % 2 == 0)
        {
            number = number / 2;
            count++;
        }
        else 
        {
            number = 3 * number + 1;
            count++;
        }
        } while (number != 1);
    }       
    return count;
}

/* recursive solution
int collatz(int number)
{
    if (number == 1)
    {
        return 1;
    }

    else if ((number % 2) == 0)
    return 1 + collatz(number / 2);

    else
    return 1 + collatz(3*n + 1);

}
*/