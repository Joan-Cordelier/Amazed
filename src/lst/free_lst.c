/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** free_lst.c
*/

#include "my.h"

void free_lst(void *data)
{
    link_t **list = (link_t **) data;

    if (*list == NULL)
        return;
    free_lst(&(*list)->next);
    free((*list));
}
