// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, string argv[])
{     
    if (argc < 2 || argc > 2)
    {
        printf("Usage: %s [string]\n", argv[0]);
        return 1;
    }

    string word;
    word = argv[1];

    printf("%s \n",replace(word));
}

string replace(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
       switch (word[i])
       {
       case 'a':
        word[i] = '6';
        break;
       
       case 'e':
        word[i] = '3';
        break;

       case 'i':
       word[i] = '1';
       break;

       case 'o':
        word[i] = '0';
        break;

       default:
        break;
       }
    }
    return word;
}