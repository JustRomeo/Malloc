/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "prototype.h"
#include "structures.h"

void *realloc(void *p, size_t size)
{
    mem_t *b;
    mem_t *new;
    void *newp;
    size_t s = 0;

    if (!p)
        return (malloc(size));
    if (valid_ptr(p)) {
        s = align2(size);
        b = get_block(p);
        if (b->size > s) {
            if (b->size - s > (getBlockSize() + 4))
                split_block(b, s);
        } else {
            if (b->size > s && b->size - s > getBlockSize())
                split_block (b, s);
            else {
                newp = malloc(s);
                if (!newp)
                    return NULL;
                new = get_block(newp);
                memcpy(b->data, new->data, new->size);
                free(p);
                return (newp);
            }
        }
        return (p);
    }
    return NULL;
}