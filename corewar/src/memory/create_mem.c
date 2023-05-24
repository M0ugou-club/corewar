/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_memory
*/

#include <stdlib.h>
#include <stdbool.h>
#include "op.h"

static int circular_mod(int index)
{
    int res = 0;

    if (index >= 0) {
        return index % MEM_SIZE;
    } else {
        res = index % MEM_SIZE;
        return (res != 0) ? MEM_SIZE + res : 0;
    }
}

char get_mem_value(char *mem, int index)
{
    int new_index = 0;
    char get = 0;

    new_index = circular_mod(index);
    get = mem[new_index];
    return (get);
}

void modif_mem(char *mem, int index, const char value)
{
    int new_index = 0;

    new_index = circular_mod(index);
    mem[new_index] = value;
    return;
}

char *create_memory(void)
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
