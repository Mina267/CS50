#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//bool valid_key(string S);


int main(int argc, string argv[])
{
    // get valid input from user

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //get plaintext from user
    string TEXT = get_string("plaintext: ");

    //change Key from string to int
    // atoi: convert a string to an int
    string S = argv[1];
    int K = atoi(S);


    //printf("%i\n",K);

    printf("ciphertext: ");

    //
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (isalpha(TEXT[i]))
        {
            if (isupper(TEXT[i]))
            {
                TEXT[i] -= 'A';
                char C = (TEXT[i] + K) % 26;
                C += 'A';
                printf("%c", C);
            }
            else if (islower(TEXT[i]))
            {
                TEXT[i] -= 'a';
                char C = (TEXT[i] + K) % 26;
                C += 'a';
                printf("%c", C);
            }
        }
        else
        {
            printf("%c", TEXT[i]);
        }
    }
    printf("\n");
    return 0;
}


// removed part 
/*bool valid_key(string S)
{
    for (int j = 0, n = strlen(S); j < n; j++)
    {
        if(isdigit(S[j]))
        {
            return true;
        }
    }
    return false;
}*/