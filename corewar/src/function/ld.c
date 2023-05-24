/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** load
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "vm.h"

int load_value(process_t *process, vm_t *vm, char coding_byte, int val2)
{
    int val1 = 0;

    val1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
    coding_byte);
    if (coding_byte == T_IND) {
        val1 = get_value(vm->memory, process->index + (val1 % IDX_MOD), T_DIR);
    }
    process->registers[val2 - 1] = val1;
    if (val1 == 0) {
        process->carry = 1;
    } else {
        process->carry = 0;
    }
    return 0;
}

int process_load_value(process_t *process, vm_t *vm, char *cb_tab)
{
    int reg2 = 0;
    int index = 0;

    index = get_index_arg(cb_tab[INDEX_2ND], false);
    reg2 = get_value(vm->memory, process->index + SKIP_COMM_CB + index,
    cb_tab[INDEX_2ND]);
    if (get_reg_error(reg2) == -1) {
        return (-1);
    }
    if (load_value(process, vm, cb_tab[INDEX_1ST], reg2) == -1)
        return -1;
    return (0);
}

int exec_ld(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int ret_val = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    if (process_load_value(process, vm, cb_tab) == -1) {
        free(cb_tab);
        return -1;
    }
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}