#include <cs50.h>
#include <stdio.h>
#include <string.h>
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

// Sort pairs in decreasing order by strength of victory
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


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Create an array to keep track of the locked candidates
    bool locked_candidates[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        locked_candidates[i] = false;
    }

    // Loop over the pairs and lock them if they don't create a cycle
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // Check if locking the pair would create a cycle
        if (check_cycle(winner, loser, locked_candidates))
        {
            continue;
        }

        // Lock the pair
        locked[winner][loser] = true;
        locked_candidates[loser] = true;
    }
}

// Check for cycles in the locked pairs graph using DFS
bool check_cycle(int start, int end, bool locked_candidates[])
{
    // Create an array to keep track of visited candidates
    bool visited[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        visited[i] = false;
    }

    // Perform DFS starting from the start candidate
    return dfs(start, end, visited, locked_candidates);
}

bool dfs(int start, int end, bool visited[], bool locked_candidates[])
{
    // Mark the current candidate as visited
    visited[start] = true;

    // Check if the start candidate beats the end candidate directly
    if (locked[start][end])
    {
        return true;
    }

    // Loop over the candidates that the start candidate beats
    for (int i = 0; i < candidate_count; i++)
    {
        if (!visited[i] && !locked_candidates[i] && preferences[start][i] > preferences[start][end])
        {
            // Check if a cycle is detected when continuing the DFS from the i-th candidate
            if (dfs(i, end, visited, locked_candidates))
            {
                return true;
            }
        }
    }

    // No cycle was detected
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