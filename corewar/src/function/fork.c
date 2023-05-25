/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "mem.h"
#include "vm.h"
#include "op.h"
#include "my.h"

int process_fork(process_t *process, vm_t *vm)
{
    int param = 0;
    int new_index = 0;
    char *copy_name = NULL;
    process_t *new_process = NULL;

    param = get_value(vm->memory, process->index + 1, T_IND);
    if (get_mem_value(vm->memory, process->index) == 12) {
        new_index = circular_mod(process->index + param % IDX_MOD);
    } else {
        new_index = circular_mod(process->index + param);
    }
    copy_name = my_strdup(process->id);
    MALLOC_RETURN(copy_name, -1);
    new_process = copy_process(new_index, copy_name, process);
    if (new_process == NULL) {
        free(copy_name);
        return (-1);
    }
    process = add_process(new_process, process);
    return (0);
}

int exec_fork(process_t *process, vm_t *vm)
{
    int ret_val = 0;

    ret_val = process_fork(process, vm);
    if (ret_val == -1) {
        return (-1);
    }
    if (ret_val != 0) {
        process->index = -1;
        return (0);
    }
    process->index += 3;
    return 0;
}
