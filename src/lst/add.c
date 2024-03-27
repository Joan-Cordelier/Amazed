/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "my.h"

int add(void *data)
{
    parsing_t **list = (parsing_t **) data;
    parsing_t *new = NULL;
    size_t buffsize = 0;
    int size = 0;

    new = malloc(sizeof(parsing_t));
    new->str = NULL;
    size = getline(&new->str, &buffsize, stdin);
    if (size != -1) {
        new->str = my_strsub(new->str, '\n');
        new->next = *list;
        *list = new;
    }
    return size;
}
