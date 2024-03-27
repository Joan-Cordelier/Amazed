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

void print_output(parsing_t **labs)
{
    parsing_t *lab = *labs;

    reverse(&lab);
    (lab) = (lab)->next;
    mini_printf("#number_of_robots\n%s\n", (lab)->str);
    (lab) = (lab)->next;
    mini_printf("#rooms\n");
    while ((lab)->str[1] != '-') {
        mini_printf("%s\n", (lab)->str);
        (lab) = (lab)->next;
    }
    mini_printf("#tunnels\n");
    while ((lab) != NULL) {
        mini_printf("%s\n", (lab)->str);
        (lab) = (lab)->next;
    }
    mini_printf("#moves\n");
    reverse(&lab);
}

int main(void)
{
    parsing_t *lab = NULL;

    lab = malloc(sizeof(parsing_t));
    init_parsing(&lab);
    print_output(&lab);
    free_lst(&lab);
    return 0;
}
