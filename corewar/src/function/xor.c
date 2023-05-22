/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** xor.c
*/

#include <stdlib.h>
#include "fonction.h"
#include "vm.h"

int process_xor(process_t *process, vm_t *vm, char **cb_tab)
{
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int result = 0;
    int index = 0;

    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB, cb_tab[INDEX_1ST]);
    index += get_index(cb_tab[INDEX_1ST]);
    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB +
                                   index, cb_tab[INDEX_2ND]);
    index += get_index(cb_tab[INDEX_2ND]);
    param3 = get_value(vm->memory, process->index + SKIP_COMM_CB + index,
                       cb_tab[INDEX_3RD]);
    result = param1 ^ param2;
    process->register[param3] = result;
}

int exec_xor(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_and(process, vm, cb_tab);
    index = increase_index(cb_tab);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + index + SKIP_COMM_CB);
}
