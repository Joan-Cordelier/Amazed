/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** free.c
*/

#include "my.h"

int free_all(parsing_t *lab, char **tab)
{
    free_lst(&lab);
    free_tab(tab);
    return 0;
}

void free_tab(char **tab)
{
    for (int i = 0; i < tab_len(tab); i++)
        free(tab[i]);
    if (tab != NULL)
        free(tab);
}
