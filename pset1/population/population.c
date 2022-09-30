#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n, m, i ;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        m = get_int("End size: ");
    }
    while (m < n);
    

    // TODO: Calculate number of years until we reach threshold
    for (i = 0 ; n < m ; i++)
    {
        n = n + (n / 3) - (n / 4);
    }
  
    
    // TODO: Print number of years
    printf("Years: %i\n", i);


}