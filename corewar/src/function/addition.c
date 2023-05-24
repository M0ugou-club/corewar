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

int process_addidtion(process_t *process, vm_t *vm, char *cb_tab, int add_type)
{
    int val1 = 0;
    int val2 = 0;
    int result = 0;
    int reg_result = 0;

    val1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST]);
    val2 = get_value(vm->memory, process->index + SKIP_COMM_CB + 1,
        cb_tab[INDEX_2ND]);
    reg_result = get_value(vm->memory, process->index + SKIP_COMM_CB + 2,
        cb_tab[INDEX_3RD]);
    if (get_reg_error(val1) == -1 || get_reg_error(val2) == -1
        || get_reg_error(reg_result) == -1) {
        process->index = -1;
        return (-1);
    }
    result = process->registers[val1 - 1] +
        (process->registers[val2 - 1] * add_type);
    process->registers[reg_result - 1] = result;
    return (result);
}

int exec_add(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int ret_val = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    ret_val = process_addidtion(process, vm, cb_tab, 1);
    process->carry = (ret_val == 0) ? 1 : 0;
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}

int exec_sub(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int ret_val = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    ret_val = process_addidtion(process, vm, cb_tab, -1);
    process->carry = (ret_val == 0) ? 1 : 0;
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}
