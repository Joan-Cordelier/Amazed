/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

static char **get_pipe(void *data)
{
    parsing_t **lab = (parsing_t **) data;
    int i = 0;
    char **tab = NULL;

    reverse(lab);
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp) != NULL && is_in_str((temp)->str, '-') != 0)
            i++;
    }
    tab = malloc(sizeof(char *) * (i + 1));
    i = 0;
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp) != NULL && is_in_str((temp)->str, '-') != 0) {
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
        while ((temp) != NULL && is_in_str((temp)->str, '-') == 0) {
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

static int make_nbr(char c)
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

int **init_matrice(char **tab)
{
    int **matrice = NULL;
    int biggest_nb = my_get_biggest_nb(tab);

    matrice = malloc(sizeof(int *) * (biggest_nb));
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

static int loop_mv(int *i, int param[4], int **matrice, int robot)
{
    for (int j = 0; j < param[LEN]; j++) {
        if (*i < param[LEN] && matrice[*i][j] == 1) {
            *i = j;
            break;
        }
    }
    mini_printf("P%d-%d\n", robot + 1, *i);
    if (*i == param[END])
        return 1;
    return 0;
}

static void moove(int **matrice, int param[4])
{
    int stop = 0;
    int i = param[START];

    for (int robot = 0; robot < param[ROBOT]; robot++) {
        while (stop == 0) {
            stop = loop_mv(&i, param, matrice, robot);
        }
        i = param[START];
        stop = 0;
    }
}

int main(void)
{
    parsing_t *lab = NULL;
    char **tab = NULL;
    int **matrice = NULL;
    int param[4] = {0, 0, 0, 0};

    lab = malloc(sizeof(parsing_t));
    init_parsing(&lab);
    print_output(&lab);
    tab = get_pipe(&lab);
    matrice = init_matrice(tab);
    param[START] = get_start(&lab);
    param[END] = get_end(&lab);
    param[ROBOT] = get_nb_robot(&lab);
    param[LEN] = my_get_biggest_nb(tab);
    for (int i = 0; i < 3; i++) {
        if (param[i] == -1)
            return 84;
    }
    moove(matrice, param);
    return free_all(lab, tab);
}

    /*for (int i = 0; i < 3; i++) {
        mini_printf("%d\n", param[i]);
        if (param[i] == -1)
            return 84;
    }*/
    /*for (int i = 0; i < my_get_biggest_nb(tab); i++) {
        for (int j = 0; j < my_get_biggest_nb(tab); j++)
            mini_printf("%d ", matrice[i][j]);
        mini_printf("\n");
    }*/
