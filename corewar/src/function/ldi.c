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

int process_ldi(process_t *process, vm_t *vm, char **cb_tab)
{
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int result = 0;
    int index = 0;

    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
                       cb_tab[INDEX_1ST]);
    index += get_index(cb_tab[INDEX_1ST]);
    param2 = get_value(vm->memory, process->index + SKIP_COMM_CB +
                                   index, cb_tab[INDEX_2ND]);
    index += get_index(cb_tab[INDEX_2ND]);
    param3 = get_value(vm->memory, process->index + SKIP_COMM_CB + index,
                       cb_tab[INDEX_3RD]);
    result = process->index + param1 % IDX_MOD;
    result = get_value(vm->memory, result, T_IND);
    result += param2;
    result = process->index + result % IDX_MOD;
    process->register[param3 - 1] = result;
    return 0;
}

int exec_ldi(process_t *process, vm_t *vm) {
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_ldi(process, vm, cb_tab);
    index = increase_index(cb_tab, false);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    process->index = circular_mod(process->index + index + SKIP_COMM_CB);
    return (0);
}

int process_lldi(process_t *process, vm_t *vm, char **cb_tab)
{
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int result = 0;
    int index = 0;

    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
                       cb_tab[INDEX_1ST]);
    index += get_index(cb_tab[INDEX_1ST]);
    param2 = get_value(vm->memory, process->index + SKIP_COMM_CB +
                                   index, cb_tab[INDEX_2ND]);
    index += get_index(cb_tab[INDEX_2ND]);
    param3 = get_value(vm->memory, process->index + SKIP_COMM_CB + index,
                       cb_tab[INDEX_3RD]);
    result = process->index + param1;
    result = get_value(vm->memory, result, T_IND);
    result += param2;
    result = process->index + result;
    process->register[param3 - 1] = result;
    return 0;
}

int exec_lldi(process_t *process, vm_t *vm) {
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_lldi(process, vm, cb_tab);
    index = increase_index(cb_tab, false);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    process->index = circular_mod(process->index + index + SKIP_COMM_CB);
    return (0);
}