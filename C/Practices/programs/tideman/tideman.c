#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int start, int end, bool locked_candidates[]);
bool dfs(int start, int end, bool visited[], bool locked_candidates[]);
bool cycle(int start, int end, bool  visited[], bool locked_candidates[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}
// check if vote is valid and store in ranks[]
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// record the preferences of each iteration
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int preferred_candidate = ranks[i];
            int less_preferred_candidate = ranks[j];
            preferences[preferred_candidate][less_preferred_candidate]++;
        }
    }
}

// add pairs
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order 
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strength1 = preferences[pairs[j].winner][pairs[j].loser];
            int strength2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            if (strength1 < strength2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

// Lock pairs in graph in order
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        bool locked_candidates[candidate_count];
        memset(locked_candidates, false, candidate_count);

        if (!check_cycle(pairs[i].loser, pairs[i].winner, locked_candidates))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// function to check for cycles in the graph
bool cycle(int start, int end, bool visited[], bool locked_candidates[])
{
    if (start == end)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (preferences[start][i] > preferences[start][end])
        {
            if (visited[i])
            {
                return false;
            }
            visited[i] = true;
            if (!dfs(i, end, visited, locked_candidates))
            {
                return false;
            }
        }
    }
    return true;
}
// Check for cycles in the locked pairs graph using DFS
bool check_cycle(int start, int end, bool locked_pairs[])
{
    // Initialize array of visited candidates
    bool visited[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        visited[i] = false;
    }

    // Initialize array of locked candidates
    bool locked_candidates[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        locked_candidates[i] = false;
    }
    for (int i = 0; i < pair_count; i++)
    {
        if (locked_pairs[i])
        {
            locked_candidates[pairs[i].winner] = true;
            locked_candidates[pairs[i].loser] = true;
        }
    }
    return dfs(start, end, visited, locked_candidates);
}

bool dfs(int start, int end, bool visited[], bool locked_candidates[])
{
    // Mark the current candidate as visited
    visited[start] = true;

    if (start == end)
    {
        return true;
    }

    // Check all candidates that are not locked
    for (int i = 0; i < candidate_count; i++)
    {
        if (!locked_candidates[i] && !visited[i] && locked[start][i])
        {
            if (dfs(i, end, visited, locked_candidates))
            {
                return true;
            }
        }
    }
    return false;
}


void print_winner(void)
{
    // Iterate over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_winner = true;

        // Check if candidate has any incoming edges
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_winner = false;
                break;
            }
        }

        // Print winner
        if (is_winner)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}