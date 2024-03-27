/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

static void null_init(link_t *link)
{
    for (int i = 0; i < 3; i++) {
        link->next[i] = NULL;
    }
}

static char **get_pipe(void *data)
{
    parsing_t **lab = (parsing_t **) data;
    int i = 0;
    char **tab = NULL;

    reverse(lab);
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp)->str[1] == '-')
            i++;
    }
    tab = malloc(sizeof(char *) * (i + 1));
    i = 0;
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp)->str[1] == '-') {
            tab[i] = my_strdup(temp->str);
            i++;
        }
    }
    reverse(lab);
    tab[i] = NULL;
    return tab;
}

static void print_output(void *data)
{
    parsing_t **lab = (parsing_t **) data;

    reverse(lab);
    for (parsing_t *temp = *lab; temp != NULL; temp = temp) {
        (temp) = (temp)->next;
        mini_printf("#number_of_robots\n%s\n", (temp)->str);
        (temp) = (temp)->next;
        mini_printf("#rooms\n");
        while ((temp)->str[1] != '-') {
            mini_printf("%s\n", (temp)->str);
            (temp) = (temp)->next;
        }
        mini_printf("#tunnels\n");
        while ((temp) != NULL) {
            mini_printf("%s\n", (temp)->str);
            (temp) = (temp)->next;
        }
        mini_printf("#moves\n");
    }
    reverse(lab);
}

int make_nbr(char c)
{
    return (c - 48);
}

int fill_matrice(int **matrice, int i, int j)
{
    if (matrice[i][j] == 1)
        return 1;
    return 0;
}

int my_get_biggest_nb(char **tab)
{
    int biggest = 0;

    for (int i = 0; i < tab_len(tab); i++) {
        if (make_nbr(tab[i][0]) > biggest)
            biggest = make_nbr(tab[i][0]);
        if (make_nbr(tab[i][2]) > biggest)
            biggest = make_nbr(tab[i][2]);
    }
    return biggest + 1;
}

char **init_matrice(char **tab)
{
    int **matrice = NULL;
    int biggest_nb = my_get_biggest_nb(tab);

    matrice = malloc(sizeof(int *) * biggest_nb);
    for (int i = 0; i < biggest_nb; i++)
        matrice[i] = malloc(sizeof(int) * biggest_nb);
    for (int i = 0; i < biggest_nb; i++) {
        for (int j = 0; j < biggest_nb; j++)
            matrice[i][j] = 0;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        matrice[make_nbr(tab[i][0])][make_nbr(tab[i][2])] = 1;
    }
    for (int i = 0; i < biggest_nb; i++) {
        for (int j = 0; j < biggest_nb; j++)
            matrice[i][j] = fill_matrice(matrice, i, j);
    }
    return matrice;
}

int main(void)
{
    parsing_t *lab = NULL;
    char **tab = NULL;
    char **matrice = NULL;

    lab = malloc(sizeof(parsing_t));
    init_parsing(&lab);
    print_output(&lab);
    tab = get_pipe(&lab);
    matrice = init_matrice(tab);
    free_lst(&lab);
    free_tab(tab);
    return 0;
}
