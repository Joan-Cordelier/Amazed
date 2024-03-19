/*
** EPITECH PROJECT, 2024
** header
** File description:
** mysh
*/

#ifndef MYH
    #define MYH
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "struct.h"


//Linked list
int add(void *data, int value);
int create(void *data, int value);
int disp(void *data);
void connect_links(link_t *link1, link_t *link2);
void free_lst(void *data);

//Put
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_putchar(char l);
int my_putstr(char const *str);

#endif /* MYH */
