/*
** EPITECH PROJECT, 2024
** strsub
** File description:
** strsub
*/

#include "my.h"

char *my_strsub(char *str, char c)
{
    char *cpy = NULL;

    if (str[my_strlen(str) - 1] == c) {
        cpy = malloc(sizeof(char) * my_strlen(str));
        for (int i = 0; i < my_strlen(str) - 1; i++)
            cpy[i] = str[i];
        cpy[my_strlen(str) - 1] = '\0';
        free(str);
        return cpy;
    } else
        return str;
}
