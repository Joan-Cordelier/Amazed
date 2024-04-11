/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** struct_utils.c
*/

#include "my.h"

char *init_shortest_path(int **matrice, int param[4])
{
    char *path = NULL;

    return path;
}

int add_solution(int **matrice, int param[4], void *data)
{
    solutions_t **sol = (solutions_t **) data;
    solutions_t *new = NULL;
    int last = 0;

    new = malloc(sizeof(solutions_t));
    new->path = NULL;
    new->len = -1;
    new->next = NULL;
    return last;
}

void init_solution(int **matrice, int param[4], void *data)
{
    solutions_t **sol = (solutions_t **) data;
    int size = 0;

    (*sol)->path = NULL;
    (*sol)->len = -1;
    (*sol)->next = NULL;
    while (size == 0) {
        size = add_solution(matrice, param, sol);
    }
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
