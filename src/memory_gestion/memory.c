/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#include "prototype.h"
#include "structures.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void split_block(mem_t *b, size_t s)
{
    mem_t *new;

    new = b->data + s;
    b->size = abs(b->size);
    new->size = (b->size - s - getBlockSize());
    new->size = abs(new->size);
    new->next = b->next;
    new->empty = true;
    b->size = s;
    b->next = new;
}

mem_t *get_block(void *p) {
    return p -= getBlockSize();
}

int valid_ptr(void *p)
{
    if (getbase() && (p > getbase() && p < sbrk(0)))
        return (p == (get_block(p))->ptr);
    return (0);
}

size_t align2(size_t size)
{
    size_t align = 2;

    for (; align < size; align *= 2);
    return align;
}

mem_t *extend_heap (mem_t *last, size_t s)
{
    mem_t *b;
    size_t pagesize = getpagesize() * 2;

    b = sbrk(0);
    pagesize = align2(s + getBlockSize());
    pagesize *= 2;
    if (sbrk(pagesize) == (void *) -1)
        return NULL;
    b->size = s;
    b->next = NULL;
    if (last)
        last->next = b;
    b->empty = true;
    return (b);
}

mem_t *find_block(mem_t *last, size_t size)
{
    mem_t *b = getbase();

    for (; b && !(b->empty && b->size > size);) {
        *last = *b;
        b = b->next;
    }
    return (b);
}

mem_t *best(mem_t **last, size_t size)
{
    int best_pos = -1;
    bool is_selected = 0;
    size_t best_size = 0;
    mem_t *temp = getbase();
    mem_t *block = getbase();

    for (int j = 0; block; j ++) {
        if (block->size > size && block->empty) {
            if (best_size == 0) {
                best_size = block->size;
                is_selected = true;
            } if (best_size != 0) {
                if (block->size < best_size || is_selected) {
                    best_size = block->size;
                    best_pos = j;
                    is_selected = false;
                }
            }
        }
        *last = block;
        block = block->next;
    }
    if (best_pos == -1)
        return (block);
    for (int i = 0; i < best_pos; i ++)
        temp = temp->next;
    return (temp);
}