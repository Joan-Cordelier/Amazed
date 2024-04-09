/*
** EPITECH PROJECT, 2023
** cmopare str
** File description:
** str
*/

#include "my.h"

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < n) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    i--;
    return (str1[i] - str2[i]);
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}
