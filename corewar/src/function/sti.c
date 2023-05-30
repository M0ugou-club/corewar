/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** addition
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "vm.h"

static int sti_values(process_t *process, vm_t *vm, const char *cb_tab)
{
    int reg = 0;
    int val1 = 0;
    int val2 = 0;
    int addr = 0;
    int index = 0;

    reg = get_special_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST], process);
    index += 1;
    val1 = get_special_indexes_value(vm->memory,
        process->index + SKIP_COMM_CB + index, cb_tab[INDEX_2ND], process);
    index += get_index_arg(cb_tab[INDEX_2ND], true);
    val2 = get_special_indexes_value(vm->memory,
        process->index + SKIP_COMM_CB + index, cb_tab[INDEX_3RD], process);
    addr = process->index + ((val1 + val2) % IDX_MOD);
    if (process->index == -1) {
        return (-1);
    }
    write_memory(vm, addr, reg, process->nb_champ);
    return 0;
}

int exec_sti(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int ret_val = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        process->index = -1;
        free(cb_tab);
        return (0);
    }
    if (sti_values(process, vm, cb_tab) == -1) {
        process->index = -1;
        free(cb_tab);
        return 0;
    }
    ret_val = get_new_process_index(cb_tab, true, process);
    free(cb_tab);
    return (ret_val);
}
