/*
** EPITECH PROJECT, 2023
** A-maze-d
** File description:
** link.c
*/

#include "my.h"

void connect_links(link_t *link1, link_t *link2)
{
    int where = 0;

    for (int i = 0; i < 3; i++) {
        if (link1->next[i] == NULL)
            break;
        where++;
    }
    link1->next[where] = link2;
}
