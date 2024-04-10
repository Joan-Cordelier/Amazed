/*
** EPITECH PROJECT, 2023
** A-maze-d
** File description:
** struct.h
*/

#ifndef MY_STRUCT
    #define MY_STRUCT

typedef struct labyrinthe_s {
    char *str;
    struct lab_s *next;
} labyrinthe_t;

typedef struct link_s {
    int data;
    struct link_s *next[3];
} link_t;

typedef struct parsing_s {
    char *str;
    struct parsing_s *next;
} parsing_t;

typedef struct solutions_s {
    int *path;
    int len;
    struct solutions_s *next;
} solutions_t;

#endif /* MY_STRUCT */
