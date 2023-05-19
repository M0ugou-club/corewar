/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_value
*/

#include "vm.h"
#include "op.h"
#include "my.h"

static const type_value_t type[] = {{1, T_REG},
{DIR_SIZE, T_DIR},
{IND_SIZE, T_IND},
{-1, -1}};

int get_value(char *memory, int index, char coding_byte)
{
    int value_size = 0;
    int nb = 0;
    int index_value = 0;
    char mem_value = 0;

    for (int i = 0; type[i].value != -1; i++) {
        if (type[i].type == coding_byte) {
            value_size = type[i].value;
        }
    }
    for (int i = 0; i < value_size; i++) {
        mem_value = get_mem_value(memory, index + 1);
        nb += mem_value * (my_power(BYTE_VALUE, index_value));
        index++;
    }
    nb = SWAP_ENDIAN(nb);
    return (nb);
}
