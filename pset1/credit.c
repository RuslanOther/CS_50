#include <cs50.h>
#include <stdio.h>
#include <math.h>

long long card;
long long cardNum;
long long cardNum1;
int d = 0;
int cardBrand;

// Функция просчета валидности номера карты
int calculation (int lCard, int cardArrey[])
{
    int m;
    int r = 0;
    int s;
    for (int i = 0; i < lCard; i++)
    {
        m = i % 2;
          
        if (m == 1)
        {
            s = cardArrey[i] * 2;
            int hs;
            if (s > 9)
            {
                hs = s  % 10;
                s /= 10;
                s += hs;
            }
        } else 
        {
            s = cardArrey[i];
        }
        r = r + s; 
    }
    r = r % 10;    
    return r;  
}

int lCard;
int cardArrey[16];
int r;

int main (void)
{ 
    do {
        printf ("Введите номер карты: ");
        card = GetLongLong();
    } while (card <= 0);

// Получение количества символов    
    cardNum = card;
    while (cardNum > 1)
    {
        cardNum /= 10;
        lCard++;
    }

// Инициализация массива cardArrey[i] от 0
    cardNum1 = card;
    for(int i = lCard - 1; i >= 0; i--)
    {
        cardArrey[i] = cardNum1 % 10;
        cardNum1 /= 10;
        if (i == 2) { cardBrand = cardNum1; } // бренд карты (можно не делать, но так меньше длинных чисел в программе)
    }

// Проверка карты
    if (cardArrey[0] == 4 && (lCard == 13 || lCard == 16)) 
    { // Visa
        calculation (lCard, cardArrey);
        
        if (r == 0)
        {
          printf ("VISA\n");
        } else 
        {
          printf ("INVALID\n");
        }
    } else if ((cardBrand == 34 || cardBrand == 37) && lCard == 15)
    { // AmEx
        calculation (lCard, cardArrey);
    
        if (r == 0)
        {
          printf ("AMEX\n");
        } else 
        {
          printf ("INVALID\n");
        }
    } else if ((cardBrand >= 51 || cardBrand <= 55) && lCard == 16)
    { // MasterCard
        calculation (lCard, cardArrey);
    
        if (r == 0)
        {
            printf ("MASTERCARD\n");
        } else 
        {
            printf ("INVALID\n");
        }
  
    } else  { printf ("INVALID\n"); }
}