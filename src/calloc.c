/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#include <stdio.h>
#include <unistd.h>
#include "prototype.h"
#include "structures.h"

void *calloc(size_t number, size_t size)
{
    char *new;
    size_t i = 0;
    size_t s4 = align2(number * size) + 2;

    new = malloc(number * size);
    if (new)
        for (i = 0; i <= s4; i ++, new[i] = 0);
    return new;
}