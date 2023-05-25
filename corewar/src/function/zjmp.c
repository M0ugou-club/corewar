/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** zjmp
*/

#include <stdlib.h>
#include "fonction.h"
#include "mem.h"
#include "process.h"
#include "vm.h"

int exec_zjmp(process_t *process, vm_t *vm)
{
    short int index = 0;

    index = get_value(vm->memory, process->index + 1, T_IND);
    if (process->carry == 1) {
        process->index = circular_mod(process->index + (index % IDX_MOD));
    } else {
        process->index = circular_mod(process->index + 3);
    }
    return (0);
}
