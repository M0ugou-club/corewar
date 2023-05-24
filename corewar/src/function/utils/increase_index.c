/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** increase_index
*/

#include <stdbool.h>
#include "op.h"
#include "vm.h"

static const type_value_t type[] = {{1, T_REG},
{DIR_SIZE, T_DIR},
{IND_SIZE, T_IND},
{-1, -1}};

int get_index_arg(char coding_byte, bool index_function)
{
    int index = -1;

    if (index_function == true && coding_byte == T_DIR) {
        return (IND_SIZE);
    }
    for (int i = 0; type[i].type != -1; i++) {
        if (type[i].type == coding_byte) {
            index = type[i].value;
        }
    }
    return (index);
}

int increase_index(char *cb_tab, bool index_function)
{
    int index = 0;
    int tmp = 0;

    for (int i = 0; cb_tab[i] != '\0'; i++) {
        if (cb_tab[i] == T_DIR && index_function == true) {
            tmp += get_index_arg(cb_tab[i], index_function);
        } else {
            tmp = get_index_arg(cb_tab[i], index_function);
        }
        if (tmp == -1) {
            return (-1);
        }
        index += tmp;
    }
    return (index);
}

int get_new_process_index(char cb_tab, bool index_function, process_t *process)
{
    int index = 0;

    if (process->index == -1) {
        return (0);
    }
    index = increase_index(cb_tab, false);
    if (index == -1) {
        return (-1);
    }
    process->index = circular_mod(process->index + index + SKIP_COMM_CB);
    return (0);
}
