/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** task04
*/

#include "my.h"

int is_authorized(char c, char const *authorized)
{
    int present = 0;

    for (int i = 0; authorized[i] != '\0'; i++) {
        if (c == authorized[i])
            present = 1;
    }
    return present;
}

int size_not_word(char const *str, int index, char const *authorized)
{
    for (; !is_authorized(str[index], authorized)
        && str[index] != '\0'; index++);
    return index;
}

int nb_word(char const *str, char const *authorized)
{
    int nbr = 0;
    int alphanum = 1;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (i != 0 && !is_authorized(str[i - 1], authorized))
            continue;
        alphanum += is_authorized(str[i], authorized) ? 1 : - alphanum;
        if (str[i + 1] == '\0')
            alphanum = 0;
        if (alphanum == 0)
            nbr++;
    }
    return nbr;
}

int size_word(char const *str, int index, char const *authorized)
{
    int size = 0;
    int i = index;

    for (; is_authorized(str[i], authorized); i++)
        size++;
    return size;
}

char **my_str_to_word_array(char const *str, char const *authorized)
{
    int word_number = nb_word(str, authorized);
    int index_str = 0;
    int word_size = 0;
    int index_word = 0;
    char **result = malloc(sizeof(char *) * (word_number + 1 + sizeof(NULL)));

    for (int i = 0; i < word_number; i++) {
        index_str = size_not_word(str, index_str, authorized);
        word_size = size_word(str, index_str, authorized);
        result[i] = malloc(sizeof(char) * (word_size + 1));
        for (index_word = 0; index_word < word_size; index_word++) {
            result[i][index_word] = str[index_str];
            index_str++;
        }
        result[i][index_word] = '\0';
    }
    result[word_number] = NULL;
    return result;
}
