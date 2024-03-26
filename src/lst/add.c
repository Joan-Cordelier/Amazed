/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "my.h"

int add(void *data, char *str)
{
    parsing_t **list = (parsing_t **) data;
    parsing_t *new = NULL;

    new = malloc(sizeof(parsing_t));
    new->str = my_strdup(str);
    new->next = *list;
    *list = new;
    return 0;
}
