/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** load long
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "vm.h"

int lld_value(process_t *process, vm_t *vm, char coding_byte, int val2)
{
    int val1 = 0;

    val1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
    coding_byte);
    if (coding_byte == T_IND) {
        val1 = get_value(vm->memory, process->index, T_DIR);
    }
    process->registers[val2 - 1] = val1;
    if (val1 == 0) {
        process->carry = 1;
    } else {
        process->carry = 0;
    }
    return 0;
}

int process_lld(process_t *process, vm_t *vm, char *cb_tab)
{
    int val1 = 0;
    int reg2 = 0;

    reg2 = get_value(vm->memory, process->index + SKIP_COMM_CB,
    cb_tab[INDEX_2ND]);
    if (get_reg_error(reg2) == -1) {
        return (-1);
    }
    lld_value(process, vm, cb_tab[INDEX_1ST], reg2);
    return (0);
}

int exec_lld(process_t *process, vm_t *vm)
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
    if (process_lld(process, vm, cb_tab) == -1) {
        process->index = -1;
        free(cb_tab);
        return 0;
    }
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}
