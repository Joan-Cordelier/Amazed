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

#endif /* MY_STRUCT */
