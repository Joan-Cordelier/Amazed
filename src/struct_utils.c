/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** struct_utils.c
*/

#include "my.h"

parsing_t *init_parsing(void)
{
    parsing_t *lab = malloc(sizeof(parsing_t));
    char *buffer = NULL;
    size_t buffsize = 0;
    int size = 0;

    for (int i = 0; size != -1; i++) {
        size = getline(&buffer, &buffsize, stdin);
        buffer = my_strsub(buffer, '\n');
        add(&lab, buffer);
    }
    del(&lab);
    return lab;
}
