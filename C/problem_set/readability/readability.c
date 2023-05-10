#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// prototype declarations

int grade(string text);
int word_count(string text);

int main(void)
{

    string text;

    text = get_string("Text: ");

    // call function and assign it to index

    int index = grade(text);

    // different prints for different cases

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// function to calculate averages and return index

int grade(string text)
{
    double words = 1;
    double sentences = 0;
    double letters = 0;

    // checks for the conditions whether to increase words, sentences or letters, depending on what text[i] is

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }

    // math to calculate index given the formula

    double L = (letters / words) * 100.0;
    double S = (sentences / words) * 100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
