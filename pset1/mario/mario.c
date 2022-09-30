#include <stdio.h>
#include <cs50.h>

int main()
{
    //input from user
    int n, i;
    do
    {
        n = get_int("Enter postive number: ");
    }
    while (n < 1 || n > 8);
    
    //The main loop 
    for (i = 1 ; i <= n ; i++)
    {
        //space in shape   
        for (int k = i ; k < n ; k++)
        {
            printf(" ");
        }
        for (int j = i ; j > 0 ; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}