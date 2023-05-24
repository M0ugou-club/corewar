/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "memory.h"
#include "vm.h"
#include "op.h"
#include "my.h"

int process_fork(process_t *process, vm_t *vm)
{
    int param = 0;
    int new_index = 0;
    process_t *new_process = NULL;

    param = get_special_value(vm->memory, process->index + 1, T_IND, process);
    if (param == -1) {
        return (-1);
    }
    if (get_mem_value(vm->memory, process->index) == 12) {
        new_index = process->index + param % IDX_MOD;
    } else {
        new_index = process->index + param;
    }
    new_process = create_process(new_index, my_strdup(process->id),
    process->nb_champ);
    process = add_process(new_process, process);
    if (process == NULL) {
        return (-1);
    }
    return (0);
}

int exec_fork(process_t *process, vm_t *vm)
{
    if (process_fork(process, vm) == -1) {
        return (-1);
    }
    process->index += 2;
    return 0;
}
