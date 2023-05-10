#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char WORDS[]  = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // lowercase char for each word

    for (int i = 0; i < word1[i]; i++)
    {
        word1[i] = tolower(word1[i]);
    }
    for (int i = 0; i < word2[i]; i++)
    {
        word2[i] = tolower(word2[i]);
    }

    // check if words are alphabetical, if not, remove the non alpha chars

    for (int i = 0; i < word1[i]; i++)
    {
        if (!isalpha(word1[i]))
        {
            word1[i] = '\0';
        }
    }
    for (int i = 0; i < word2[i]; i++)
    {
        if (!isalpha(word2[i]))
        {
            word2[i] = '\0';
        }
    }


    // Score both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    // Compute and return score for string

    for (int i = 0; i < strlen(word); i++)
    {
        int count = 0;
        do
        {
            // go around the loop until a match, then add the value determined on the score array
            if (word[i] == WORDS[count])
            {
                score += POINTS[count];
                count++;
            }
            else
            {
                count++;
            }
        }
        while (count < 25);
    }
    return score;
}
