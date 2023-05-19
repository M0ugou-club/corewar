/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_memory
*/

#include <stdlib.h>
#include <stdbool.h>
#include "op.h"

void modif_mem(char *mem, int index, const char value)
{
    bool is_neg = false;

    if (index < 0) {
        index *= -1;
        is_neg = true;
    }
    index = index % MEM_SIZE;
    if (is_neg == true) {
        index *= -1;
    }
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
