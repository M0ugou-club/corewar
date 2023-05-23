/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "process.h"
#include "vm.h"

int put_champ_in_arena(char *arena, int index, char *code)
{
    for (int i = 0; code[i] != '\0' ;i++) {
        if (get_mem_value(arena, index + 1) == 0) {
            write(2, "champion overwrites another in memory\n", 38);
            return -1;
        }
        modif_mem(arena, index + i, code[i]);
    }
    return (0);
}

int put_champ(process_t *champ, vm_t *vm, char *code)
{
    static int index = 0;

    if (champ->index == -1) {
        put_champ_in_arena(vm->memory, index, code);
        champ->index = index;
    } else {
        put_champ_in_arena(vm->memory, champ->index, code);
    }
    index += MEM_SIZE / vm->nb_champ;
    return 0;
}
