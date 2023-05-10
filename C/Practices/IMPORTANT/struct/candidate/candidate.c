#include <stdio.h>
#include <cs50.h>

/*
Folder "important" contains exercises with clear comments of whats happening and why, 
in case i need a re-read of such concepts, separated of "Theory and concepts" since
that folder contains mostly very basic things i dont think i would need to re-read. 
*/

typedef struct 
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string promt);

int main(void)
{
    candidate candidates_array[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        candidates_array[i] = get_candidate("Enter a candidate.");
    }
    
    for (int i = 0; i < 3; i++)
    {
    printf("\n");
    printf("Name of the candidate: %s\n", candidates_array[i].name);
    printf("Number of votes: %i\n", candidates_array[i].votes);
    }
    
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Name: ");
    c.votes = get_int("Votes: ");

    return c;
}