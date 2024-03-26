/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** len str
*/

#include "my.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab != NULL && tab[i] != NULL; i++);
    return i;
}

int my_strlen(char *str)
{
    int cpt = 0;

    while (str != NULL && str[cpt] != '\0') {
        cpt++;
    }
    return (cpt);
}
