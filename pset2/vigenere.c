#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // для atoi
#include <ctype.h> // для isalpha islower isupper


int main(int argc, string argv[]) // argc - содержит кол-во аргументов, argv[] - содержит ввод пользователя
{
    if (argc != 2) // Если не указаны аргументы или их больше одного, возвращается ошибка
    {   
        printf("Usage: ./vigenere k\n");
        
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++) // Возвращается ошибка, если во фразе есть цифры
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n"); 
            
            return 1;  
        }
    }

    string str = GetString();
    
    int lengthKey = strlen(argv[1]); // Ханилище количества символов ключа

    int ik, key, numChar = 0;

    for (int i = 0, length = strlen(str); i < length; i++) 
    {
        if (isalpha(str[i]))
        {
            ik = numChar % lengthKey; //индекс символа из ключевой фразы
            
            if (isupper(argv[1][ik])) // Тут привожу заглавные буквы к строчным
            {
                argv[1][ik] = argv[1][ik] + 32;
            }
            
            key = argv[1][ik] - 97; // Привожу символы ключей к диапазону 0 - 25
            

            if (islower(str[i]) && isalpha(str[i]))
            {
              str[i] = (str[i] - 97 + key) % 26 + 97;
              
            } else if(isupper(str[i]) && isalpha(str[i]))
            {
              str[i] = (str[i] - 65 + key) % 26 + 65;
            }
            
            printf("%c", str[i]);
            numChar++;    
        } else
        {
            printf("%c", str[i]);
            
        }
    }
  
  printf("\n");
  
  return 0;
}