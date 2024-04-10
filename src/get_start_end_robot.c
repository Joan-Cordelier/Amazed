/*
** EPITECH PROJECT, 2023
** A-Maze-d
** File description:
** get_start_end_robot.c
*/

#include "my.h"

int get_end(void *data)
{
    int end = -1;
    parsing_t **lab = (parsing_t **) data;

    reverse(lab);
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp)->next != NULL && my_strcmp((temp)->str, "##end") == 0)
            end = my_getnbr(temp->next->str);
    }
    reverse(lab);
    return end;
}

int get_nb_robot(void *data)
{
    int end = -1;
    parsing_t **lab = (parsing_t **) data;

    reverse(lab);
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        end = my_getnbr(temp->str);
        if (end != -1)
            break;
    }
    reverse(lab);
    return end;
}

int get_start(void *data)
{
    int end = -1;
    parsing_t **lab = (parsing_t **) data;

    reverse(lab);
    for (parsing_t *temp = (*lab)->next; temp != NULL; temp = temp->next) {
        if ((temp)->next != NULL && my_strcmp((temp)->str, "##start") == 0) {
            end = my_getnbr(temp->next->str);
        }
    }
    reverse(lab);
    return end;
}
