#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// each text files contains 1000 words to random select from

#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)

#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters

#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// function prototypes

string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

// main function

int main(int argc, string argv[])
{
    int wordsize = 0;

    // check if input is right

    if (argc < 2 || argc >= 3)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    // store the pointer argv[1] to wordsize string variable

    else
    {
        wordsize = atoi(argv[1]);
    }

    if (wordsize < 5 || wordsize > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7 or 8\n");
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words

    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE

    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game

    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word

    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate

    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess

    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess

        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero

        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG

        for (int j = 0; j < wordsize; j++)
        {
            status[j] = WRONG;
        }

        // Calculate score for the guess

        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess

        print_word(guess, wordsize, status);

        // if guessed it exactly right, set terminate loop

        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }       
    }

    // Print the game's result

    if (won == true)
    {
        printf("You won!\n");
    }
    else
    {
        printf("You lost!\n");
        printf("Correct word was: " GREEN "%s" RESET "\n", choice);
    }
    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    // get guess word, set all chars to lowercase, and store it on guess variable, later to be checked if correct lenght, if not do while loop

    guess = get_string("Please enter the %i letter word to guess.\n", wordsize);
        for (int i = 0; i < guess[i]; i++)
        {
            guess[i] = tolower(guess[i]);
        }

    // ensure users actually provide a guess that is the correct length



    if (wordsize != strlen(guess))
    {
        do
        {
            guess = get_string("Input a 5-letter word:\n");
        } while (wordsize != strlen(guess));
    }
    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
  
    for (int i = 0; i < strlen(guess); i++)
    {
        if (guess[i] == choice[i])
        {
            status[i] = EXACT;
        }

        for (int j = 0; j < strlen(choice); j++)
        {
            if (guess[i] == choice[j] && guess[i] != choice[i])
            {
                status[i] = CLOSE;
            }
        }
    }

    // loop to save on score the total score of all status[i] scores

    for (int i = 0; i < strlen(guess); i++)
    {
        score = score + status[i];
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal

    for (int i = 0; i < strlen(guess); i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }
    printf("\n");
    return;
}


