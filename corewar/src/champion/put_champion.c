/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include <unistd.h>
#include "op.h"
#include "process.h"
#include "vm.h"
#include "mem.h"

static int put_champ_in_arena(char *arena, int index, const char *code,
    header_t *champ_info)
{
    for (int i = 0; i < champ_info->prog_size; i++) {
        if (get_mem_value(arena, index + i) != 0) {
            write(2, "champion overwrites another in memory\n", 38);
            return -1;
        }
        modif_mem(arena, index + i, code[i]);
    }
    return (0);
}

int put_champ(process_t *champ, vm_t *vm, const char *code,
    header_t *champ_info)
{
    static int index = 0;

    if (champ->registers != NULL) {
        champ->registers[0] = champ->nb_champ;
    }
    if (champ->index == -1) {
        if (put_champ_in_arena(vm->memory, index, code, champ_info) == -1) {
            return (-1);
        }
        champ->index = index;
    } else {
        if (put_champ_in_arena(vm->memory, champ->index, code, champ_info)
            == -1) {
            return (-1);
        }
    }
    index += MEM_SIZE / vm->nb_champ;
    return 0;
}
