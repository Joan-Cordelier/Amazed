/*
** EPITECH PROJECT, 2023
** disp
** File description:
** disp
*/

#include "my.h"

void reverse(parsing_t **list)
{
    parsing_t *previous = NULL;
    parsing_t *current = (*list);
    parsing_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *list = previous->next;
}

int disp_r(void *data)
{
    parsing_t **list = (parsing_t **) data;

    reverse(list);
    for (parsing_t *temp = *list; temp->next != NULL; temp = temp->next) {
        my_putstr(temp->str);
        my_putstr("\n");
    }
    return 0;
}

int disp(void *data)
{
    parsing_t **list = (parsing_t **) data;

    for (parsing_t *temp = *list; temp->next != NULL; temp = temp->next) {
        my_putstr(temp->str);
        my_putstr("\n");
    }
    return 0;
}
