#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{    

float m;
int array[4] = {25, 10, 5, 1};
int count = 0;

    do {
        printf ("С какой суммы выдать сдачу?\n");
        m = GetFloat();
    } while (m < 0);
    
        int money = round (m * 100);
            
        for (int i = 0; i < 4; i++)
        {
            while (money >= array[i]) 
                {
                money -= array[i];
                count++;
                }
        }
        printf ("%d\n", count);
}