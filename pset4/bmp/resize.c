/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 * 
 * https://sandbox.cs50.net/checks/4026229eb9524872b1aa9351512f9bef
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
       
int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }


    // Присваиваю строковый аргумент переменной
    int resize = atoi(argv[1]);
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // Проверка корректности ввода аргумента 
    if (resize < 1 || resize > 100)
    {
        printf("Size not within 0-100 range \n");
        return 2;
    }
    
    // Открытие входного файла 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open input file.\n");
        return 3;
    }

    // Создание и открытие выходного файла
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    
    // Создание новых структур для нового и старого заголовка
    // Чтение BITMAPFILEHEADER из входного файла
    BITMAPFILEHEADER bf, bf_New;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    // запись данных из оригинальной в новую структуру.
    bf_New = bf;
    
    // Аналогично поступаю с BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_New;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_New = bi;


    // Проверка оригинального файла на принадлежность к 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // Ширина и высота для нового файла
    bi_New.biWidth = bi_New.biWidth * resize; 
    bi_New.biHeight = bi_New.biHeight * resize; 
    
    // Вычисление количества нулевых байтов для выравнивания
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_New =  (4 - (bi_New.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    // Работа с заголовком. Вычисление размера изображения и обновление данных в BITMAPINFOHEADER
    bi_New.biSizeImage = ((bi_New.biWidth * sizeof(RGBTRIPLE) + padding_New) * abs(bi_New.biHeight));

    // Работа с заголовком. Вычисление размера файла и обновление в BITMAPFILEHEADER
    bf_New.bfSize = bi_New.biSizeImage + 54;
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_New, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_New, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // Вычисление установки курсора
    int jump = bi.biWidth * sizeof(RGBTRIPLE) + padding; 

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi_New.biHeight); i < biHeight; i++)
    { 
        if (i % resize != 0)
        {
            fseek(inptr, -jump, SEEK_CUR);
        } 
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
    
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
            // write RGB triple to outfile
            for (int l = 0; l < resize; l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
    
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    
        // then add it back (to demonstrate how)
        for (int k = 0; k < padding_New; k++)
        {
            fputc(0x00, outptr);
        } 

    }
    
    // close infile
    fclose(inptr);
    
    // close outfile
    fclose(outptr);
    
    // that's all folks
    return 0;
}