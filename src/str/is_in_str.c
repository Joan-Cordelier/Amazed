/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** is_in_str.c
*/

#include "my.h"

int is_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
