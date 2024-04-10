/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** remoove_tag_str.c
*/

#include "my.h"

char *rm_tag_str(char *str)
{
    char *cpy = NULL;
    int j = 0;

    if (my_strcmp(str, "##start") == 0 || my_strcmp(str, "##end") == 0)
        return str;
    cpy = malloc(sizeof(char) * my_strlen(str));
    for (int i = j; str[i] != '\0'; i++) {
        if (str[i] == '#' && str[i + 1] != '#' && i != 0) {
            j++;
            break;
        }
        cpy[i] = str[i];
        j++;
    }
    if (j <= 1)
        return str;
    j--;
    cpy[j] = '\0';
    return cpy;
}
