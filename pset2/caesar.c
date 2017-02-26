#include <cs50.h>
#include <stdio.h>
#include <string.h> // для strlen
#include <stdlib.h> // для atoi
#include <ctype.h>  // для isalpha islower isupper

int k; //Хранилище для цифры со строки
int main(int argc, string argv[]) // argv[] - содержит цифры со строки, argc - содержит ввод пользователя
{
  if (argc < 2 || atoi(argv[1]) < 0)
    {   
      printf("Key must be a non-negative integer.\n"); 
      return 1;
    }
    
  printf ("plaintext: ");
  string str = GetString(); //получение строки
  
  printf ("ciphertext: ");
  
  k = atoi(argv[1]); // Преобразование букв в их ASCII эквивалент
  
  for (int i = 0, length = strlen(str); i < length; i++) 
  {
    if (islower(str[i]) && isalpha(str[i]))
    {
      str[i] = (str[i] - 97 + k) % 26 + 97;
    }
    
    if(isupper(str[i]) && isalpha(str[i]))
    {
      str[i] = (str[i] - 65 + k) % 26 + 65;
    }
    
    printf("%c", str[i]);
  }
  
  printf("\n");
  
  return 0;
}