#include <cs50.h>
#include <stdio.h>

int main (void)
{    
int t, b;
    
    do {
        printf ("minutes: ");
        t = GetInt();
    } while (t <= 0);
    
        b = 12 * t;
        printf ("bottles: %d\n", b);
        return 0;
}   
