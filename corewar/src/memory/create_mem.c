/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_memory
*/

#include <stdlib.h>
#include "op.h"

char modif_mem(char *mem, int index, const char value)
{
    if (index < 0) {
        index = MEM_SIZE - index;
    }
    index = index % MEM_SIZE;
    mem[index] = value;
}

char *create_memory(unsigned const int mem_size)
{
    char *mem = NULL;

    mem = malloc(sizeof(char) * MEM_SIZE);
    if (mem == NULL) {
        return NULL;
    }
    for (int i = 0; i != MEM_SIZE; i++) {
        mem[i] = 0;
    }
    return mem;
}
