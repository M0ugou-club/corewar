/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** ldi.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "fonction.h"
#include "vm.h"

int get_value_ldi(vm_t *vm, process_t *process, char coding_byte, int value)
{
    int new_value = value;

    if (coding_byte == T_REG) {
        if (get_reg_error(value) == -1) {
            process->index = -1;
            return (0);
        }
        new_value = process->registers[value - 1];
    }
    if (coding_byte == T_IND) {
        new_value = get_value(vm->memory, process->index + value,
            coding_byte);
        new_value = (short int) (new_value);
        new_value = new_value % IDX_MOD;
    }
    return (new_value);
}

int process_ldi(process_t *process, vm_t *vm, char *cb_tab, int index)
{
    int param = 0;
    int result = 0;

    param = get_indexes_value(vm->memory, index, cb_tab[INDEX_1ST]);
    result += get_value_ldi(vm, process, cb_tab[INDEX_1ST], param);
    index += get_index_arg(cb_tab[INDEX_1ST], true);
    param = get_indexes_value(vm->memory, index, cb_tab[INDEX_2ND]);
    result += get_value_ldi(vm, process, cb_tab[INDEX_2ND], param);
    index += get_index_arg(cb_tab[INDEX_2ND], true);
    param = get_indexes_value(vm->memory, index, cb_tab[INDEX_3RD]);
    if (get_reg_error(param) == -1) {
        process->index = -1;
        return (-1);
    }
    result = process->index + result % IDX_MOD;
    result = get_value(vm->memory, result, T_DIR);
    process->registers[param - 1] = result;
    return result;
}

int exec_ldi(process_t *process, vm_t *vm)
{
    int ret_val = 0;
    char *cb_tab = NULL;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        process->index = -1;
        free(cb_tab);
        return (0);
    }
    ret_val = process_ldi(process, vm, cb_tab, process->index + SKIP_COMM_CB);
    process->carry = (ret_val == 0) ? 1 : 0;
    ret_val = get_new_process_index(cb_tab, true, process);
    free(cb_tab);
    return (ret_val);
}
