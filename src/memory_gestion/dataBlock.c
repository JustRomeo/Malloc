/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#include "prototype.h"
#include "structures.h"

mem_t *base = NULL;
size_t BLOCK_SIZE = sizeof(struct mem_s);

void *getbase(void)
{
    return base;
}

void setbase(void *ptr)
{
    base = ptr;
}

size_t getBlockSize(void)
{
    return BLOCK_SIZE;
}