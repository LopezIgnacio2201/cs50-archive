#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    int lenght1 = get_int("Input the lenght of the 1st side of the triangle\n");
    int lenght2 = get_int("Input the lenght of the 2nd side of the triangle\n");
    int lenght3 = get_int("Input the lenght of the 3rd side of the triangle\n");


    if (valid_triangle(lenght1, lenght2, lenght3))
    {
        printf("Its a valid triangle!\n");
    }
    else
    {
        printf("Not a valid triangle!\n");
    }
}

// check if valid triangle

bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    
    else if (a + b < c || a + c < b || b + c < a)
    {
        return false;
    }

    else 
    {
        return true;
    }   
}