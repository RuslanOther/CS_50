#include <cs50.h>
#include <stdio.h>

int h, i, x; // Глобальные переменные
int  b = 1; // кол-во первичных блоков: 1 или 2

void sharp ();

int main (void)
{    
    do {
        printf ("Height: ");
            h = GetInt();
    } while ((h < 0) || (h > 23));
    
    if (h == 0) {printf ("");}
    
    else {
        while (h != 0) 
        { 
            
        i = h - 1;
        while (i != 0) {
        printf (" ");
        i--;
        }
        
    sharp ();
            
        printf ("  ");
            
    sharp ();
            
        printf ("\n");
        b++;    
        h--;
        }
      }
}

//Функция просчета шарпов
void sharp ()
    {
        x = b;
            while (x != 0) {
                printf ("#");
                x--;
            }
    }