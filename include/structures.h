/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#ifndef _STRUCTURE_
#define _STRUCTURE_

#include <unistd.h>
#include <stdbool.h>

typedef struct mem_s {
    size_t size;
    struct mem_s *next;
    struct mem_s *prev;
    bool empty;
    void *ptr;
    char data[1];
} mem_t;

#endif