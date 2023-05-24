/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write memomry
*/

#include "op.h"
#include "vm.h"

int write_memory(char *memory, int index, int val)
{
    char byte = 0;

    for (int i = 3; i >= 0; i--) {
        byte = val % BYTE_VALUE;
        val = val / BYTE_VALUE;
        modif_mem(memory, index + i, byte);
    }
    return 0;
}