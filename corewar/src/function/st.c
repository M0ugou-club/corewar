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

static int store_value(process_t *process, vm_t *vm, char coding_byte,
    int val1)
{
    int val2 = 0;

    val2 = get_value(vm->memory, process->index + SKIP_COMM_CB + 1,
        coding_byte);
    if (coding_byte == T_REG) {
        if (get_reg_error(val2) == -1) {
            process->index = -1;
            return -1;
        }
        process->registers[val2 - 1] = process->registers[val1 - 1];
    }
    if (coding_byte == T_IND) {
        write_memory(vm->memory, (process->index + (val2 % IDX_MOD)),
            process->registers[val1 - 1]);
    }
    return 0;
}

static int process_store_value(process_t *process, vm_t *vm, const char *cb_tab)
{
    int reg1 = 0;

    reg1 = get_special_value(vm->memory, process->index + SKIP_COMM_CB,
        cb_tab[INDEX_1ST], process);
    if (process->index == -1) {
        return (-1);
    }
    if (store_value(process, vm, cb_tab[INDEX_2ND], reg1) == -1)
        return -1;
    return (0);
}

int exec_st(process_t *process, vm_t *vm)
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
    if (process_store_value(process, vm, cb_tab) == -1) {
        process->index = -1;
        free(cb_tab);
        return 0;
    }
    ret_val = get_new_process_index(cb_tab, false, process);
    free(cb_tab);
    return (ret_val);
}
