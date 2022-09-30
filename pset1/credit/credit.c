#include <stdio.h>
#include <cs50.h>
#include<math.h>

int main()
{
    long credit;
//prompt from user    
    do
    {
        credit = get_long("Enter credit card number: ");
    }
    while (credit < 1);

    long X, Y, S1 = 0, S2 = 0, count = 0, V, C, Card;

// count credit card numbers
    C = credit;
    Card = credit;
    do
    {
        C /= 10;
        count ++ ;
    }
    while (C > 0);

// checksum Luhn’s Algorithm
    do
    {
        X = credit % 10;
        S1 += X;
        credit /= 10;
        Y = credit % 10;
        Y *= 2;
        S2 += (Y % 10) + (Y / 10);
        credit /= 10;
    }
    while (credit > 0);
// sum of checksum
    V = S1 + S2;
    
// get first and second numbers
    long S = Card / pow(10, (count - 2)) ;
    S = S % 10;
    long F = Card / pow(10, (count - 1));

// print kind of card
    if (V % 10 == 0)
    {
        if (count == 15 && F == 3 && (S == 4 || S == 7))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && F == 5 && (S <= 5 && S >= 1))
        {
            printf("MASTERCARD\n");
        }
        else if ((count <= 16 && count >= 13) && F == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
// if checksum not correct    
    else 
    {
        printf("INVALID\n");
    }


}




