/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_memory
*/

#include <stdlib.h>
#include "mem.h"

mem_t *create_memory(unsigned const int mem_size) {
    mem_t *mem = NULL;

    if (mem_size < 1) {
        return (NULL);
    }
    mem = malloc(sizeof(mem_t));
    for (int i = 0; i < mem_size; i++) {
        
    }
}
