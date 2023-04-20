#include <stdio.h>
#include <cs50.h>

void twice(int size);

int main(void) 
{
    // create a user input asking for a variable that gets used for defining
    // the length of the array
    int sizeofarray;
    do
    {
        sizeofarray = get_int("What's the size of the array?\n");
    } while (sizeofarray < 1);

    twice(sizeofarray);

    // create the array, each element besides the first is 2 times the previous one
    // print the array int by int, possible a loop
}

void twice(int size)
{
    int array[size]; 
    const int firstValue = 1;
    array[0] = firstValue;
    printf("Array is %i\n", array[0]);
    for (int i = 1; i < size; i++)
    {
        array[i] = array[i - 1] * 2; 
        printf("Array is %i\n", array[i]); 
    }
}