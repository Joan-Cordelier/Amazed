/*
** EPITECH PROJECT, 2023
** del
** File description:
** del
*/

#include "my.h"

int del(void *data)
{
    parsing_t **list = (parsing_t **) data;
    parsing_t *to_rm = NULL;

    if ((*list)->str[0] == '#' && (*list)->str[1] != '#'){
        to_rm = (*list)->next;
        free((*list)->str);
        free((*list));
        (*list) = to_rm;
        return 0;
    }
    for (parsing_t *tmp = *list; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->str[0] == '#' && tmp->next->str[1] != '#') {
            to_rm = tmp->next->next;
            free(tmp->next->str);
            free(tmp->next);
            tmp->next = to_rm;
        }
    }
    return 0;
}
