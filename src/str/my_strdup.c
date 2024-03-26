/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char *src)
{
    char *dest = NULL;
    char *i = NULL;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    i = my_strcpy(dest, src);
    return (i);
}
