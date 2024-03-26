/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

void null_init(link_t *link)
{
    for (int i = 0; i < 3; i++) {
        link->next[i] = NULL;
    }
}

int main(void)
{
    parsing_t *lab = NULL;

    lab = init_parsing();
    disp_r(&lab);
    free_lst(&lab);
    return 0;
}
