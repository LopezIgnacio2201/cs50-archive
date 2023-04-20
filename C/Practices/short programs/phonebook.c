#include <cs50.h>
#include <stdio.h>

bool confirmation(char confirm);
void ask_data(string* name, int* age, long* phone_number);

int main(void)
{
    string name;
    int age;
    long phone_number;
    bool confirmed = false;

    do {
        ask_data(&name, &age, &phone_number);

        printf("Please confirm if the following information is correct (Y or N):\n");
        char confirm = get_char("%s, %i, %li\n", name, age, phone_number);

        if (confirmation(confirm))
        {
            printf("Confirmation successful.\n");
            confirmed = true;
        }
        else
        {
            printf("Confirmation unsuccessful. Please try again.\n");
        }
    } while (!confirmed); // Repeat until confirmation is 'Y'

    return 0;
}


bool confirmation(char confirm)
{
    return (confirm == 'Y');
}

void ask_data(string* name, int* age, long* phone_number)
{
    *name = get_string("What's your name?\n");
    *age = get_int("What's your age?\n");
    *phone_number = get_long("Introduce a phone number please:\n");
}









#include <cs50.h>
#include <stdio.h>

bool confirmation(char confirm);
void ask_data(string* name, int* age, long* phone_number);

int main(void)
{
    string name;
    int age;
    long phone_number;
    bool confirmed = false;

    do {
        // Pass the addresses of variables 'name', 'age', and 'phone_number'
        // to the function 'ask_data' using the '&' operator.
        ask_data(&name, &age, &phone_number);

        printf("Please confirm if the following information is correct (Y or N):\n");

        // Declare a variable 'confirm' and assign it the value returned by
        // the function 'get_char', passing it the values of 'name', 'age',
        // and 'phone_number'. The '&' operator is used to pass the address of
        // the 'confirm' variable to 'get_char'.
        char confirm = get_char("%s, %i, %li\n", name, age, phone_number, &confirm);

        // Pass the value of 'confirm' to the function 'confirmation'
        // as an argument.
        if (confirmation(confirm))
        {
            printf("Confirmation successful.\n");
            confirmed = true;
        }
        else
        {
            printf("Confirmation unsuccessful. Please try again.\n");
        }
    } while (!confirmed); // Repeat until confirmation is 'Y'

    return 0;
}

// Define a function that takes a character as an argument and returns a boolean.
bool confirmation(char confirm)
{
    // Compare the value of 'confirm' with the character 'Y'
    // and return true if they are equal, false otherwise.
    return (confirm == 'Y');
}

// Define a function that takes the addresses of three variables
// as arguments and stores user input in them.
void ask_data(string* name, int* age, long* phone_number)
{
    // Use the '*' operator to dereference the pointer 'name' and
    // store user input in the variable it points to.
    *name = get_string("What's your name?\n");

    // Use the '*' operator to dereference the pointer 'age' and
    // store user input in the variable it points to.
    *age = get_int("What's your age?\n");

    // Use the '*' operator to dereference the pointer 'phone_number' and
    // store user input in the variable it points to.
    *phone_number = get_long("Introduce a phone number please:\n");
}
