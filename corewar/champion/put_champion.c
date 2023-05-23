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

int put_champ(process_t *list_champ, vm_t *vm)
{
    int nb_champ = 0;
    int section_size = MEM_SIZE;
    int index = 0;
    process_t *current = list_champ;

    nb_champ = count_champ(list_champ);
    section_size = (section_size / nb_champ);
    while (current) {
        if (current->index == -1) {
            put_champ_in_arena(vm->memory, index, current->code);
            current->index = index;
        } else {
            put_champ_in_arena(vm->memory, current->index, current->code);
        }
        index += MEM_SIZE / vm->nb_champ;
        current = current->next;
    }
    return 0;
}
