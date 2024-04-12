/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** struct_utils.c
*/

#include "my.h"

void init_parsing(parsing_t **lab)
{
    int size = 0;

    (*lab)->str = NULL;
    (*lab)->next = NULL;
    for (int i = 0; size != -1; i++)
        size = add(lab);
    del(lab);
}
