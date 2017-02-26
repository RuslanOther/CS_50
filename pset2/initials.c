#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{ 
string s = GetString();
int length = strlen(s); 
int f = 0; //счетчик пробелов
int i = 0; //счетчик цикла

  while (i < length) 
  {
    if (s[i] == 32) // если есть пробел, то увеличиваю счетчик 
    {
      f++;
    }
    
    if (i == 0 && f != 1) // если первый символ не пробел
    {
      printf("%c", toupper(s[i]));
      
    } else if (s[i] != 32 && f > 0) // если символ не пробел, а счетчик показывает, что ранее были пробелы
    {
      printf("%c", toupper(s[i]));
      f = 0;
    } 
    
    i++;
  }

printf("\n");

}