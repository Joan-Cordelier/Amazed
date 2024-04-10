/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** struct_utils.c
*/

#include "my.h"

int nb_solutions(int **matrice, int start, int len)
{
    int size = 0;

    for (int i = 0; i < len; i ++) {
        if (matrice[start][i] == 1)
            size++;
    }
    return size;
}

int *init_shortest_path(int **matrice, int start, int end, int len)
{
    int *path = NULL;

    return path;
}

solutions_t *add_solution(int **matrice, int start, int end, int len)
{
    solutions_t *new = NULL;
    int size = nb_solutions(matrice, start, len);

    new = malloc(sizeof(solutions_t));
    new->path = NULL;
    new->len = -1;
    new->next = NULL;
    return new;
}

solutions_t *init_solutions(int **matrice, int start, int end, int len)
{
    solutions_t *sol = NULL;
    int size = nb_solutions(matrice, start, len);

    sol = malloc(sizeof(solutions_t));
    sol->path = NULL;
    sol->len = -1;
    sol->next = NULL;
    for (int i = 0; i < size; i++) {
        sol->next = add_solution(matrice, start, end, len);
        sol = sol->next;
    }
    return sol;
}

void init_parsing(parsing_t **lab)
{
    int size = 0;

    (*lab)->str = NULL;
    (*lab)->next = NULL;
    for (int i = 0; size != -1; i++)
        size = add(lab);
    del(lab);
}
