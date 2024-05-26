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

static void print_output2(parsing_t *temp)
{
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

static int print_output(void *data)
{
    parsing_t **lab = (parsing_t **) data;

    reverse(lab);
    if (my_getnbr((*lab)->next->str) <= 0)
        return 84;
    for (parsing_t *temp = *lab; temp != NULL; temp = temp) {
        (temp) = (temp)->next;
        mini_printf("#number_of_robots\n%s\n", (temp)->str);
        (temp) = (temp)->next;
        print_output2(temp);
        while (temp != NULL)
            temp = temp->next;
    }
    reverse(lab);
    return 0;
}

int fill_matrice(int **matrice, int i, int j)
{
    if (matrice[i][j] == 1)
        return 1;
    return 0;
}

int my_getnbr2(char *str)
{
    char *cpy = NULL;
    int i = 0;
    int nb = 0;

    cpy = malloc(sizeof(char) * my_strlen(str));
    while (str[i] != '-' && str[i] != '\0')
        i++;
    i++;
    for (int j = 0; str[i] != '\0'; j++) {
        cpy[j] = str[i];
        i++;
    }
    nb = my_getnbr(cpy);
    free(cpy);
    return nb;
}

int my_get_biggest_nb(char **tab)
{
    int biggest = 0;

    for (int i = 0; i < tab_len(tab); i++) {
        if (my_getnbr(tab[i]) > biggest)
            biggest = my_getnbr(tab[i]);
        if (my_getnbr2(tab[i]) > biggest)
            biggest = my_getnbr2(tab[i]);
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
        matrice[my_getnbr(tab[i])][my_getnbr2(tab[i])] = 1;
        matrice[my_getnbr2(tab[i])][my_getnbr(tab[i])] = 1;
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
    int **matrice = NULL;
    int param[4] = {0, 0, 0, 0};

    lab = malloc(sizeof(parsing_t));
    init_parsing(&lab);
    if (print_output(&lab) == 84)
        return 84;
    tab = get_pipe(&lab);
    matrice = init_matrice(tab);
    param[START] = get_start(&lab);
    param[END] = get_end(&lab);
    param[ROBOT] = get_nb_robot(&lab);
    param[LEN] = my_get_biggest_nb(tab);
    for (int i = 0; i < 3; i++)
        if (param[i] == -1)
            return 84;
    moove(matrice, param);
    return free_all(lab, tab);
}
