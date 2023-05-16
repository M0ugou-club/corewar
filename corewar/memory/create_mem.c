/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_memory
*/

#include <stdlib.h>
#include "mem.h"

static mem_t * create_node(const char data)
{
    mem_t *new_node = NULL;

    new_node = malloc(sizeof(mem_t));
    if (new_node == NULL) {
        return (NULL);
    }
    new_node->oct = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}

mem_t *create_memory(unsigned const int mem_size) {
    mem_t *mem = NULL;

    if (mem_size < 1) {
        return (NULL);
    }
    mem = malloc(sizeof(mem_t));
    if (mem ==  NULL) {
        return (NULL);
    }
    for (int i = 0; i < mem_size; i++) {
        
    }
    return (mem);
}
