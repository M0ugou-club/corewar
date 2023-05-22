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
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;
    int value1 = 0;
    int value2 = 0;

    reg1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST]);
    reg2 = get_value(vm->memory, process->index + SKIP_COMM_CB + 1,
        cb_tab[INDEX_2ND]);
    reg3 = get_value(vm->memory, process->index + SKIP_COMM_CB + 2,
        cb_tab[INDEX_3RD]);
    if (get_reg_error(reg1) == -1 || get_reg_error(reg2) == -1
        || get_reg_error(reg3) == -1) {
        return (-1);
    }
    value1 = process->registers[reg1 - 1];
    value2 = process->registers[reg2 - 1] * add_type;
    process->registers[reg3 - 1] = value1 + value2;
    return (0);
}

int exec_add(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_addidtion(process, vm, cb_tab, -1);
    index = increase_index(cb_tab) + 2;
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + index + SKIP_COMM_CB);
}

int exec_sub(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_addidtion(process, vm, cb_tab, -1);
    index = increase_index(cb_tab) + 2;
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + index + SKIP_COMM_CB);
}