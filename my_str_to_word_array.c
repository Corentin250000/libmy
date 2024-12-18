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
    int nbr = is_authorized(str[0], authorized);

    for (int i = 1; str[i] != '\0'; ++i) {
        if (!is_authorized(str[i - 1], authorized) &&
            is_authorized(str[i], authorized))
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
