/*
** EPITECH PROJECT, 2023
** disp
** File description:
** disp
*/

#include "my.h"

int disp_graph(void *data)
{
    link_t **list = (link_t **) data;
    int first = 0;

    if ((*list)->next[0] == NULL) {
        my_put_nbr((*list)->data);
        my_putstr("\n");
    }
    for (link_t **temp = (*list)->next; temp[0] != NULL; temp = temp[0]->next){
        if (first == 0) {
            my_put_nbr((*list)->data);
            my_putstr("\n");
            first = 1;
        }
        for (int i = 0; temp[i] != NULL; i++) {
            disp(&temp[i]);
        }
        break;
    }
    return 0;
}
