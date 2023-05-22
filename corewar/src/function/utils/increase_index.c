/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** increase_index
*/

#include "op.h"
#include "vm.h"

static const type_value_t type[] = {{1, T_REG},
{DIR_SIZE, T_DIR},
{IND_SIZE, T_IND},
{-1, -1}};

static int get_index_arg(char coding_byte)
{
    int index = -1;

    for (int i = 0; type[i].type != -1; i++) {
        if (type[i].type == coding_byte) {
            index = type[i].value;
        }
    }
    return (index);
}

int increase_index(char *cb_tab)
{
    int index = 0;
    int tmp = 0;

    for (int i = 0; cb_tab[i] != '\0'; i++) {
        tmp = get_index_arg(cb_tab[i]);
        if (tmp == -1) {
            return (-1);
        }
        index += tmp;
    }
    return (index);
}
