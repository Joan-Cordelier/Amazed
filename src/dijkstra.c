/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** dijkstra.c
*/

#include "my.h"

#include <limits.h>

static int loop_mv(int *i, int param[4], int robot, int *dist)
{
    for (int j = 0; j < param[LEN]; j++) {
        if (dist[*i] - 1 == dist[j]) {
            (*i) = j;
            break;
        }
    }
    mini_printf("P%d-%d\n", robot + 1, *i);
    return 0;
}

static void print_mooves(int param[4], int *dist)
{
    int i = param[START];

    for (int robot = 0; robot < param[ROBOT]; robot++) {
        while (dist[i] != 0)
            loop_mv(&i, param, robot, dist);
        i = param[START];
    }
}

int get_min(int *dist, int end[], int param[4])
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < param[LEN]; i++) {
        if (end[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int *my_condition(int **matrice, int end[], int *dist, int param[4])
{
    int min = get_min(dist, end, param);

    end[min] = 1;
    for (int i = 0; i < param[LEN]; i++) {
        if (!end[i] && matrice[min][i] && dist[min] != INT_MAX &&
            dist[min] + matrice[min][i] < dist[i])
            dist[i] = dist[min] + matrice[min][i];
    }
    return dist;
}

int dijkstra(int **graph, int param[4])
{
    int *dist;
    int end[param[LEN]];

    dist = malloc(sizeof(int) * param[LEN]);
    for (int i = 0; i < param[LEN]; i++) {
        dist[i] = INT_MAX;
        end[i] = 0;
    }
    dist[param[END]] = 0;
    for (int i = 0; i < param[LEN] - 1; i++)
        dist = my_condition(graph, end, dist, param);
    if (dist[param[START]] == INT_MAX)
        return 84;
    print_mooves(param, dist);
    return 0;
}

int moove(int **matrice, int param[4])
{
    if (param[ROBOT] <= 0)
        return 84;
    dijkstra(matrice, param);
    return 0;
}
