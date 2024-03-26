/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** copy and paste a string
*/

#include "my.h"

char *my_strncpy(char *dest, char *src, int i)
{
    int j = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
