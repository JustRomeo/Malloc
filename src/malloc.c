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

static void split_and_set(mem_t *b, size_t s) {
    split_block(b, s);
    b->empty = false;
    setbase(b);
}

static bool starter(mem_t *b, size_t s) {
    b = extend_heap(NULL, s);
    if (!b)
        return false;
    split_and_set(b, s);
    return true;
}

void *malloc(size_t size)
{
    size_t s = 0;
    mem_t *b = sbrk(0);
    mem_t *last = getbase();

    s = align2(size);
    if (getbase()) {
        b = best(&last, s);
        if (b) {
            if ((b->size - s) >= (getBlockSize() + 4))
                split_block (b, s);
            b->empty = false;
        } else {
            b = extend_heap(last, s);
            if (!b)
                return NULL;
            split_and_set(b, s);
        }
    } else
        if (!starter(b, s))
            return NULL;
    return (b->data);
}