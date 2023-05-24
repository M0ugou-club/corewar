/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** xor.c
*/

#include <stdlib.h>
#include "fonction.h"
#include "vm.h"

static const int ASCII_SIZE = 256;

int process_aff(process_t *process, vm_t *vm, char **cb_tab)
{
    int param1 = 0;

    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
    cb_tab[INDEX_1ST]);
    param1 = param1 % ASCII_SIZE;
    write(1, param1, 1);
}

int exec_aff(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    process_aff(process, vm, cb_tab);
    index = increase_index(cb_tab);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + index + SKIP_COMM_CB);
}
