/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** xor.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "fonction.h"
#include "vm.h"

int process_xor(process_t *process, vm_t *vm, char *cb_tab)
{
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int result = 0;
    int index = 0;

    param1 = get_special_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST], process);
    index += get_index_arg(cb_tab[INDEX_1ST], false);
    param2 = get_special_value(vm->memory, process->index + SKIP_COMM_CB +
        index, cb_tab[INDEX_2ND], process);
    index += get_index_arg(cb_tab[INDEX_2ND], false);
    param3 = get_special_value(vm->memory, process->index + SKIP_COMM_CB + index,
        cb_tab[INDEX_3RD], process);
    if (process->index == -1)
        return (-1);
    result = param1 ^ param2;
    process->registers[param3 - 1] = result;
    process->carry = (result == 0) ? 1 : 0;
    return 0;
}

int exec_xor(process_t *process, vm_t *vm)
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
    process_xor(process, vm, cb_tab);
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}
