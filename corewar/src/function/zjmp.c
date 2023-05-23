/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** zjmp
*/

#include <stdlib.h>
#include "fonction.h"
#include "process.h"
#include "vm.h"

int exec_zjmp(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    index = get_value(vm->memory, process->index + SKIP_COMM_CB,
    cb_tab[INDEX_1ST]);
    if (index == -1) {
        free(cb_tab);
        return (-1);
    }
    free(cb_tab);
    return (process->index + (index % IDX_MOD));
}
