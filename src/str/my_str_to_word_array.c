/*
** EPITECH PROJECT, 2017
** word
** File description:
** array
*/

#include "my.h"

int my_delim(char c, char *end)
{
    int i = 0;

    while (end[i]) {
        if (c == end[i])
            return (-1);
        i++;
    }
    return (0);
}

int while_delim(char const *str, int i, char *end, int *result)
{
    if (my_delim(str[i], end) == -1) {
        while (my_delim(str[i], end) == -1) {
            i++;
            *result += 1;
        }
        i --;
    }
    return (i);
}

int count_word(char const *str, char *end)
{
    int i = 0;
    int result = 1;

    while (str[i] != '\0') {
        i = while_delim(str, i, end, &result);
        i++;
    }
    return (result);
}

int word_len(char *str, int i, char *end)
{
    int len = 0;

    while (my_delim(str[i], end) == 0 && str[i] != '\0') {
        len++;
        i++;
    }
    return (len);
}

char **my_str_to_word_array(char *str, char *end)
{
    int nb_word = count_word(str, end) + 2;
    char **tab;
    int y = 0;
    int x = 0;

    tab = malloc(sizeof(char *) * nb_word + 1);
    for (int i = 0; str[i] != '\0';) {
        x = 0;
        for (i = i; my_delim(str[i], end) == -1 && str[i] != '\0'; i++);
        tab[y] = malloc(sizeof(char) * (word_len(str, i, end) + 1));
        for (i = i; my_delim(str[i], end) == 0 && str[i] != '\0'; i++) {
            tab[y][x] = str[i];
            x++;
        }
        tab[y][x] = '\0';
        y++;
        for (i = i; my_delim(str[i], end) == -1 && str[i] != '\0'; i++);
    }
    tab[y] = NULL;
    return (tab);
}
