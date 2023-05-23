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

int load_value_long(process_t *process, vm_t *vm, char coding_byte, int val1)
{
    int val2 = 0;

    val2 = get_value(vm->memory, process->index + SKIP_COMM_CB + 1,
        coding_byte);
    if (coding_byte == T_REG) {
        if (get_reg_error(val2) == -1) {
            return -1;
        }
        process->registers[val2 - 1] = process->registers[val1 - 1];
    }
    if (coding_byte == T_IND) {
        process->registers[val2 - 1] = get_value(vm->memory, process->index + val1, coding_byte);
    }
    return 0;
}

int process_load_value(process_t *process, vm_t *vm, char *cb_tab)
{
    int val1 = 0;
    int reg2 = 0;

    reg2 = get_value(vm->memory, process->index + SKIP_COMM_CB,
    cb_tab[INDEX_2ST]);
    if (get_reg_error(reg2) == -1) {
        return (-1);
    }
    if (load_value(process, vm, cb_tab[INDEX_1ND], reg2) == -1)
        return -1;
    return (0);
}

int exec_st(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    if (process_store_value(process, vm, cb_tab) == -1) {
        free(cb_tab);
        return -1;
    }
    index = increase_index(cb_tab) + 2;
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + index + SKIP_COMM_CB);
}
