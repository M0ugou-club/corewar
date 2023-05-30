/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write memomry
*/

#include "mem.h"
#include "op.h"
#include "vm.h"

int write_memory(vm_t *vm, int index, int val, int champid)
{
    char byte = 0;
    char *memory = vm->memory;

    for (int i = 3; i >= 0; i--) {
        byte = val % BYTE_VALUE;
        val = val / BYTE_VALUE;
        modif_mem(memory, index + i, byte);
    }
    for (int i = 0; i < 4; i++) {
        modif_mem(vm->ownership, index + i, champid);
    }
    return 0;
}
