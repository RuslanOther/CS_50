/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 * 
 * https://sandbox.cs50.net/checks/d41e9beec41f4e3daa101ee1817ae267
 */

#include <stdint.h>
#include <stdio.h>

// Объявляю функцию типа void, потому, что использовать аргументы тут не имеет смысла
int main(void)
{   
    // открываю файл
    FILE* infile = fopen("card.raw", "r");
    
    // проверяю действительно ли открыт файл
    if (infile == NULL)
    {
        fclose(infile); 
        printf("file opening error\n");
        return 1;
    }
    
    // Создание буфера размером в 512 байт
    unsigned char buffer[512];
   
    // Обявляю переменную для полного имени файла ххх.jpg
    char outFile[8];
    
    // Объявляю переменную-счетчик названия файла (000)
    int jpgCount = 0; 
 
    // Создаю указатель на выходной файл
    FILE* tempFile; 
    
    // Цикл читает входной файл и работает пока не достигнут конец файла.
    while (!feof(infile))
    {
        fread(buffer, 512, 1, infile);
        
        // Проверка "магического числа" jpg файла
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // Создание названия файла
            sprintf(outFile, "%03d.jpg", jpgCount);
            
            // Открываю временный файл
            tempFile = fopen(outFile, "w");
            
            // Записываю в него данные блоком 512 байт
            fwrite(buffer, 512, 1, tempFile);
            
            // Инкремент для названия следующего файла
            jpgCount++;
        }
        // Если уже был найдено хоть одно начало jpg-файла 
        // и сейчас в буфере не оно, то продолжаю писать в файл 
        else if (jpgCount > 0)
        {
            fwrite(buffer, 512, 1, tempFile);            
        }
        
    }
    
    fclose(infile);
    fclose(tempFile);
    
    return 0;
}