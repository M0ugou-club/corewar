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
        val1 = get_mem_value(process->index + (val1 % IDX_MOD));
    }
    process->registers[val2 - 1] = val1;
    return 0;
}

int process_load_value(process_t *process, vm_t *vm, char *cb_tab)
{
    int reg2 = 0;
    int index = 0;

    index = get_index_arg(cb_tab[INDEX_2ND], false);
    reg2 = get_value(vm->memory, process->index + SKIP_COMM_CB + index,
    cb_tab[INDEX_2ST]);
    if (get_reg_error(reg2) == -1) {
        return (-1);
    }
    if (load_value(process, vm, cb_tab[INDEX_1ND], reg2) == -1)
        return -1;
    return (0);
}

int exec_ld(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

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
    index = increase_index(cb_tab, false);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    process->index = circular_mod(process->index + index + SKIP_COMM_CB);
    free(cb_tab);
    return (0);
}
