#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
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

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
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

//This function checks to see if the name of a candidate is in the candidate array
int iscandidate(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i].name) == 0)
        {
            return i;
        }
    return -1;
}

//Updates the vote count for a candidate
bool vote(string name)
{

    int i = iscandidate(name);
    if (i != -1)
    {
        candidates[i].votes++;
        return true;
    }
    return false;
}

int winner(void)
{
    int votes = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > votes)
        {
            votes = candidates[i].votes;
        }
    }
    return votes;
}


void print_winner(void)
{
    int winner_election = winner();

    for (int i = 0; i < candidate_count; i++)
    {
        if (winner_election == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

