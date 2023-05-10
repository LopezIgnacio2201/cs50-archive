#include <stdio.h>
#include <cs50.h>

    //Declaring functions at first solves issue of throwing an error, and allows to keep main
    //function at the top.

int get_size(void);         //both are declared later on the program
void print_grid(int size); //both are declared later on the program

int main(void)            //main function using only functions i created

{
    //get input for size of grid

    int n = get_size();  //the value that gets returned on the function gets assigned
                         //globally to "n"; the value of "n" is assigned through the return value of the function

    //prints the grid

    print_grid(n);       //takes the value of "n" which is returned on "get_size" and executes
                         //the code of "print_grid" using that value as a parameter
}

int get_size(void)       //void means its a function that returns a value (int here)
                         //but does not takes a parameter as input, thus "void"
{
    int n;
        do
        {
            n = get_int("Size: ");

        } while (n < 1);
        return n;         //this is the value that gets returned when the function is used
}

void print_grid(int size) //void because doesnt return a value, but does takes a parameter
                          // called "size" of int type. 

{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}