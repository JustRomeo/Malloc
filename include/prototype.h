/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** C project
*/

#ifndef _MALLOC_
#define _MALLOC_

#include "structures.h"

//Lib
int my_put_nbr(int nbr);
int my_putstr(char const *str);

//Global Var(s)
void *getbase(void);
void setbase(void *ptr);
size_t getBlockSize(void);

//Epitech
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

//Memory
void memory_node(mem_t *mem, size_t size);
void split_block(mem_t *b, size_t s);
mem_t *fusion(mem_t *b);
mem_t *get_block(void *p);
int valid_ptr(void *p);
mem_t *fusion(mem_t *b);
size_t align2(size_t size);
mem_t *find_block(mem_t *last, size_t size);
mem_t *extend_heap (mem_t *last, size_t s);
void memocpy(mem_t *dest, mem_t *src);
mem_t *best(mem_t **last, size_t size);
void copy_block(mem_t *src, mem_t *dst);

//My
void memory_node(mem_t *mem, size_t size);

#endif