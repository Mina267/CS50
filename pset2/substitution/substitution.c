#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char ciphertext(char TEXT, string cipher);
bool valid_key(int I, string cipher);


//array to compare input text with it.
char W[] = {'A',  'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


int main(int argc, string argv[])
{
    
    
    char X[] = {"JTREKYAVOGDXPSNCUIZLFBMWHQ"};
    for (int i = 0, n = strlen(argv[1]); i < (n-1); i++)
    {
        if(X[i] != argv[1][i] || argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    

    //store code in string

    string S = argv[1];
    char C;

    //get plaintext from user
    string TEXT = get_string("plaintext: ");

    printf("ciphertext: ");

    //make ciphertext
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (isalpha(TEXT[i]))
        {
            if (isupper(TEXT[i]))
            {
                C = ciphertext(TEXT[i], S);
                printf("%c", C);

            }
            else if (islower(TEXT[i]))
            {
                C = ciphertext(TEXT[i], S);
                C = tolower(C);
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



char ciphertext(char TEXT, string cipher)
{
    // Compute and return char for ciphertext
    // Change lowercase to uppercase

    TEXT = toupper(TEXT);

    for(int i = 0, n = strlen(cipher); i < n; i++)
    {
        cipher[i] = toupper(cipher[i]);
    }

    for (int i = 0, n = strlen(W); i < n; i++)
    {
        if (TEXT == W[i])
        {
            TEXT = cipher[i];
            break;
        }
    }

    return TEXT;
}

/*bool valid_key(int I, string cipher)
{
    if (I != 2)
    {
        return true;
    }
    else if (isalpha(cipher) == 0)
    {
        return true;
    }
    else if (strlen(cipher) != 26)
    {
        return true;
    }
    return true;
}*/