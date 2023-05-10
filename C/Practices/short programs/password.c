// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    bool symbol = false;
    bool space = false;

    for (int i = 0; i < strlen(password) ; i++)
    {
    	isupper(password[i]) ? uppercase = true : 0;
        islower(password[i]) ? lowercase = true : 0;
        isdigit(password[i]) ? number = true : 0;
        ispunct(password[i]) ? symbol = true : 0;
        isspace(password[i]) ? space = true : 0;
    }

    if (lowercase == true && uppercase == true && number == true && symbol == true && space == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
