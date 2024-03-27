/*
** EPITECH PROJECT, 2023
** show_array
** File description:
** word
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        i++;
        write(1, "\n", 1);
    }
    return 0;
}
