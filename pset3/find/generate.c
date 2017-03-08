/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Проверка входных данных. Может быть либо два, либо три аргумента, включая название программы. 
    // В противном случае ругается и выбрасывает из программы. Почему бы не сделать do while?
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // atoi возвращает целое число первого (не нулевого) аргумента, которое записывается в int-переменную.
    // В последствии переменная "n" используется для просчета кол-ва генерируемых чисел, а точнее циклов.
    int n = atoi(argv[1]);

    // Для генерации псевдослучайных чисел тут использованы пара drand48() и srand48().
    // С помощью srand48() происходит начальная инициализация генератора drand48(). 
    // В качестве аргумента для srand может приниматься два значения: 
    // то, которое вводит пользователь или время в секундах прошедшее с 1.1.1970 (т.н. UNIX время)
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Цикл, который выводит одно или больше случайных чисел (кол-во циклов зависит от переменной n).
    // drand48 возвращает число типа float в диапазоне от 0 до 1. 
    // Для корректного преобразования в int, число умножается на константу LIMIT.
    // Окончательный этап - вывод в консоль полученного значения.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Ура, у нас все получилось! Можно взять пирожок с полки.
    return 0;
}