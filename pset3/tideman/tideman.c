#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
//if voter Alice Charlie Bob preferences[i][j] = preferences[0][1] = 3  means there is 3 voter prefere Alice [0] over Charlie [1]
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
//if voter Alice Charlie Bob locked[i][j] = preferences[0][1] = true  means  Alice [0] locked in over ---> Charlie [1]
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates names
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
bool Check_Cycle(int i);
//bool Check_Cycle(int winner,int loser);

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
    //take names from arg Ex. ./tideman Alice Bob Charlie to array candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs initialize all to false
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

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
// How many time candidate won over other candidates
// If we Have array of ranks of voter = [0 2 1] means 0 won over 2 and 1  ,preferences[0][2]++ and preferences[0][1]++ should be increase by 1
// Preferences increase by 1 for each voter till we count how many time candidate won over other in each vote we have
void record_preferences(int ranks[])
{
    // First loop iterate such that from first index of ranks[] array to n - 1 index, because last index not count, due to last index not won over any one.
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // Second loop iterate over opponent of first index in ranks[] array but should start number after i not from first index if i = 0,  j will be = 1.
        for (int j = i ; j < candidate_count - 1; j++)
        {
            // ranks array = [0 2 1], i = 0 and j = 1 then ranks[i = 0] = 0, ranks[j = 1] = 2 so ----> preferences[0][2]
            preferences[ranks[i]][ranks[j + 1]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other

void add_pairs(void)
{
    // if we have three candidate iteration [i][j] [j][i] will be first [0][1] [1][0]  second [0][2] [2][0] third [1][2] [2][1]
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1 ; j < candidate_count ; j++)
        {
            // if [i][j] > [j][i]   winner = i; losser = j;
            if( preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;

            }

            else if(preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }

        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int tmp_arr [pair_count];

    for(int i = 0; i < pair_count; i++)
    {
        tmp_arr[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }


    // Sort array
    int tmp = 0;
    for(int i = 0; i < pair_count - 1; i++)
    {
        for(int j = i + 1; j < pair_count; j++)
        {
            if(tmp_arr[i] < tmp_arr[j])
            {
                tmp = tmp_arr[i];
                tmp_arr[i] = tmp_arr[j];
                tmp_arr[j] = tmp;
                tmp = 0;
            }
        }
    }




    int tmp_winner = 0, temp_losser = 0;
    for(int i = 0; i < pair_count - 1; i++)
    {
        for(int j = 0; i < pair_count; i++)
        {
            if(tmp_arr[i] == preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner])
            {
                tmp_winner = pairs[i].winner;
                temp_losser = pairs[i].loser;

                pairs[i].winner = pairs[j].winner;
                pairs[i].loser = pairs[j].loser;

                pairs[j].winner = tmp_winner;
                pairs[j].loser = temp_losser;

            }
        }
    }

}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0; i < pair_count; i++)
    {
        //if(!Check_Cycle(pairs[i].winner, pairs[i].loser))
        if(Check_Cycle(i) == true)
            locked[pairs[i].winner][pairs[i].loser] = true;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    
     for(int i = 0; i < pair_count; i++)
    {
        bool flag = true;
        for(int j = 0; j < pair_count; j++)
        {
            if(locked[j][i] == true)
            {
                flag = false;
                break;
            }
            
        }
        
        if(flag)
        {
            printf("%s\n",candidates[i]);
            return;
        }
    }    
    return;
}


bool Check_Cycle(int i)
{
    int c = 0;
    int a, b;
    if(i == 0)
        return true;
    else if(i > 0)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            a = pairs[j].loser;
            b = pairs[i].loser;
            if( pairs[j].loser == pairs[i].loser)
                c++;
        }
    }
    
    if (c >= 1)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}







