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

int sti_values(process_t *process, vm_t *vm, char *cb_tab)
{
    int reg = 0;
    int val1 = 0;
    int val2 = 0;
    int addr = 0;

    reg = get_value(vm->memory, process->index + SKIP_COMM_CB,
    cb_tab[INDEX_1ST]);
    if (get_reg_error(reg) == -1)
        return (-1);
    val1 = get_value(vm->memory, process->index + SKIP_COMM_CB + 1,
    cb_tab[INDEX_2ND]);
    val2 = get_value(vm->memory, process->index + SKIP_COMM_CB + 2,
    cb_tab[INDEX_3RD]);
    addr = process->index + ((val1 + val2) % IDX_MOD);
    modif_mem(vm->memory, addr, process->registers[reg - 1]);
    return 0;
}

int exec_sti(process_t *process, vm_t *vm)
{
    char *cb_tab = NULL;
    int index = 0;

    cb_tab = get_coding_byte(vm->memory[process->index + 1]);
    MALLOC_RETURN(cb_tab, -1);
    if (get_type_error(cb_tab, vm->memory[process->index]) == -1) {
        free(cb_tab);
        return (-1);
    }
    if (sti_values(process, vm, cb_tab) == -1) {
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
