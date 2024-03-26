/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** create.c
*/

#include "my.h"

int create(void *data, int value)
{
    link_t **list = (link_t **) data;
    link_t *new = NULL;

    new = malloc(sizeof(link_t));
    new->data = value;
    for (int i = 0; i < 3; i++)
        new->next[i] = NULL;
    *list = new;
    return 0;
}
