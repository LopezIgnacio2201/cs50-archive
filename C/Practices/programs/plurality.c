#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constant
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // check for max candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // assign each candidate inputted to the array and initialize 0 votes

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Convert name to lowercase
    string lowercase_name = "";
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        lowercase_name += tolower(name[i]);
    }

    // Check if name is valid
    for (int i = 0; i < candidate_count; i++)
    {
        // Convert candidate name to lowercase
        string lowercase_candidate_name = "";
        for (int j = 0, n = strlen(candidates[i].name); j < n; j++)
        {
            lowercase_candidate_name += tolower(candidates[i].name[j]);
        }

        // Compare the name with the candidate's name
        if (strcmp(lowercase_name, lowercase_candidate_name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    // Input name didn't match any candidate name
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    // Variables to use
    candidate winner;
    int max_votes = 0;
    bool draw = false;
    candidate drawers[candidate_count];
    int num_drawers = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        // loop each candidate and temporary assign winner to the most votes
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
            winner.name = candidates[i].name;
            winner.votes = candidates[i].votes;
            draw = false;
            num_drawers = 0;
        }

        // if winner and some other candidate are equal votes, its a draw
        else if (candidates[i].votes == max_votes)
        {
            draw = true;
            drawers[num_drawers].name = candidates[i].name;
            drawers[num_drawers].votes = candidates[i].votes;
            num_drawers++;
        }
    }

    //  Print in case of a draw
    if (draw == true)
    {
        drawers[num_drawers].name = winner.name;
        drawers[num_drawers].votes = winner.votes;
        num_drawers++;

        printf("There was a draw between: \n");
        for (int i = 0; i < num_drawers; i++)
        {
            // Convert the first letter of the name to uppercase
            drawers[i].name[0] = toupper(drawers[i].name[0]);

            printf("%s with %i votes\n", drawers[i].name, drawers[i].votes);
        }
    }

    // Print in case of only 1 winner
    else
    {
        // Convert the first letter of the name to uppercase
        winner.name[0] = toupper(winner.name[0]);

        printf("Winner is: %s\n", winner.name);
    }
}