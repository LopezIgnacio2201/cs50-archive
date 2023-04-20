#include <cs50.h>
#include <stdio.h>

bool isprime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1); 

    int max;
    do
    {
        max = get_int("Maximum: ");   
    } 
    while (min >= max);
    
    for (int i = min; i <= max; i++) 
    {
        if (isprime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool isprime(int number) 
{
    if (number < 2) {
        return false;  
    }
    
    for (int i = 2; i <= number / 2; i++) { 
        if (number % i == 0) {
            return false; 
        }     
    }
    return true;  
}
