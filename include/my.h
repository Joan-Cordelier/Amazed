/*
** EPITECH PROJECT, 2024
** header
** File description:
** mysh
*/

#ifndef MYH
    #define MYH
    #include "lib.h"
    #include "struct.h"

//Chained list
int add(void *data);
int del(void *data);
int disp(void *data);
int disp_r(void *data);
void free_lst(void *data);
void reverse(parsing_t **list);

//Graph
int add_graph(void *data, int value);
int create(void *data, int value);
int disp_graph(void *data);
void connect_links(link_t *link1, link_t *link2);
void free_graph(void *data);

//init
void init_parsing(parsing_t **lab);
void init_solution(int **matrice, int param[4], void *data);

//Put
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_putchar(char l);
int my_putstr(char const *str);
int my_show_word_array(char *const *tab);

//Str
char **my_str_to_word_array(char *str, char *end);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int i);
char *my_strdup(char *src);
char *my_strsub(char *str, char c);
char *rm_tag_str(char *str);
int is_in_str(char *str, char c);
int my_strcmp(char *str1, char *str2);
int my_strlen(char *str);
int tab_len(char **tab);

//Get
int get_end(void *data);
int get_nb_robot(void *data);
int get_start(void *data);
int my_getnbr(char const *str);

//Free
int free_all(parsing_t *lab, char **tab);
void free_tab(char **tab);

int moove(int **matrice, int param[4]);

#endif /* MYH */
