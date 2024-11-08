/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** task06
*/

//#include "day04.h"

void my_swap2(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int verify_sort(int *array, int size)
{
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i])
            return 0;
    }
    return 1;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 1; !verify_sort(array, size); i++) {
        if (i >= size)
            i = 1;
        if (array[i - 1] > array[i])
            my_swap2(&array[i - 1], &array[i]);
    }
}
