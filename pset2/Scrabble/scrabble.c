#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char W[] = {'A',  'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_s.
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    
}

int compute_score(string word)
{
    // Compute and return score for string
    // Change lowercase to uppercase
    char X[strlen(word)];

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        X[i] = toupper(word[i]);
    }
    
    int SUM = 0;
    for (int j = 0, n = strlen(X); j < n; j++)
    {
        for (int k = 0, l = strlen(W); k < l; k++)
        {
            if (X[j] == W[k])
            {
                SUM += POINTS[k];
            }
        }
    }
    return SUM;
}