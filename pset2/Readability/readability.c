#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_words(string TEXT); 
int compute_sentences(string TEXT);
int compute_letter(string TEXT);

int main(void)
{   
    int index; 
  
    // User input text.
    string TEXT = get_string("TEXT:");
    
    // compute parameter from fubctions
    float L = compute_letter(TEXT);
    float S = compute_sentences(TEXT);
    float W = compute_words(TEXT);
    
    L = (L / W) * 100.0;
    S = (S / W) * 100.0;

    // Coleman-Liau index.
    index = round(0.0588 * L - 0.296 * S - 15.8);

    //determine grade
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
  
  
//functions    
}

int compute_words(string TEXT)
{
    int W = 0 ;
    
    //word count
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (isspace(TEXT[i]))
        
        {
            W++;
        }
    }
    W++;
    return W;
}   

int compute_sentences(string TEXT)
{
    int S = 0;
    
    // sentences count
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (TEXT[i] == '.' || TEXT[i] == '!' || TEXT[i] == '?') 
        {
            S++;
        }
    }
    return S;
}
    
int compute_letter(string TEXT)
{   
    int L = 0;
    //count letter
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (isalpha(TEXT[i]))
        
        {
            L++;
        }
    }
    return L;
}    