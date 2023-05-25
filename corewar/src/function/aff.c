/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** xor.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "fonction.h"
#include "vm.h"

static const int ASCII_SIZE = 256;

int process_aff(process_t *process, vm_t *vm, char *cb_tab)
{
    int param1 = 0;

    param1 = get_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST]);
    param1 = param1 % ASCII_SIZE;
    write(1, &param1, 1);
    return (0);
}

int exec_aff(process_t *process, vm_t *vm)
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
    process_aff(process, vm, cb_tab);
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}
