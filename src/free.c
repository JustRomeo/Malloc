/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#include "prototype.h"
#include "structures.h"

void free(void *p)
{
    mem_t *b;

    if (!valid_ptr(p))
        return;
    b = get_block(p);
    if (b == NULL)
        return;
    b->empty = true;
}