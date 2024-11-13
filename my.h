/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Header file libmy
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

char character_to_put(int res_mod);
int value_to_add(int base, char letter, int power_max);
int max_power(int nb, int base);
char *base10_to_base(int nb, int base);
int return_to_base10(char const *nb, int base);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
int my_compute_factorial_it(int nb);
int my_compute_power_it(int nb, int p);
int nbr_is_negative(char const *str);
int nb_plus_minus(char const *str);
int verify_overflow_base(long long nb, int is_neg);
int my_getnbr_base(char const *str, char const *base);
int is_negative(char const *str);
int nb_digits_str(char const *str);
int n_power_ten(int nb_digits);
int verify_overflow(long long nb_before_verification, int is_neg);
int my_getnbr(char const *str);
void special_case(void);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
int power(int nb, int p);
int my_putnbr_base(int nbr, char const *base);
void my_swap(int *a, int *b);
int verify_sort(int *array, int size);
void my_sort_int_array(int *array, int size);
void swap_str(char *a, char *b);
int verify_sort_char(char **tab);
int my_sort_word_array(char **tab);
int is_alphanum(char c);
int nb_words(char const *str);
int size_word(char const *str, int index);
int size_not_word(char const *str, int index);
char **my_str_to_word_array(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strupcase(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
#endif
