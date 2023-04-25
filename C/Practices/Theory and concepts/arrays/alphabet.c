#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Exercise made on April 20, 2023.

bool check(string word, int length);

int main(void)
{
    int length;
    string word;
    bool valid_input;
    do
    {
        valid_input = true;
        word = get_string("Word: ");
        length = strlen(word);
        if (length < 3) 
        {
            printf("Word must be at least 3 characters long.\n");
            valid_input = false;
            continue;
        }
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(word[i]))
            {
                printf("Word can only contain letters.\n");
                valid_input = false;
                break;
            }
        }
    } while (!valid_input);

    for (int i = 0; i < length; i++)
    {
        word[i] = tolower(word[i]);
    }

    // check if alphabet order or not, true print yes, else print no
    if (check(word, length))
    {
        printf("Yes!\n");
    }
    else
    printf("No!\n");
}

bool check(string word, int length)
{
    for (int i = 1; i < length - 1; i++)
    {
        if (word[i] - 1 == word[i - 1] && word[i] + 1 == word[i + 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}