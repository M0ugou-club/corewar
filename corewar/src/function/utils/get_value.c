/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_value
*/

#include "mem.h"
#include "fonction.h"
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
    unsigned char mem_value = 0;

    for (int i = 0; type[i].value != -1; i++) {
        if (type[i].type == coding_byte) {
            value_size = type[i].value;
        }
    }
    for (int i = value_size - 1; i >= 0; i--) {
        mem_value = get_mem_value(memory, index + i);
        nb += mem_value * (my_power(BYTE_VALUE, index_value));
        index_value++;
    }
    if (coding_byte == T_IND) {
        nb = (short int) (nb);
    }
    return (nb);
}

int get_indexes_value(char *memory, int index, char coding_byte)
{
    int value_size = 0;
    short int nb = 0;
    int index_value = 0;
    unsigned char mem_value = 0;

    for (int i = 0; type[i].value != -1; i++) {
        if (type[i].type == coding_byte) {
            value_size = type[i].value;
        }
    }
    if (coding_byte == T_DIR) {
        value_size = IND_SIZE;
    }
    for (int i = value_size - 1; i >= 0; i--) {
        mem_value = get_mem_value(memory, index + i);
        nb += mem_value * (my_power(BYTE_VALUE, index_value));
        index_value++;
    }
    return (nb);
}

int get_special_indexes_value(char *memory, int index, char coding_byte,
    process_t *process)
{
    short int new_val = 0;
    int value = 0;

    value = get_value(memory, index, coding_byte);
    if (coding_byte == T_REG) {
        if (get_reg_error(value) != 0) {
            process->index = -1;
            return (0);
        }
        return (process->registers[value - 1]);
    }
    if (coding_byte == T_IND) {
        new_val = value;
    }
    if (coding_byte == T_DIR) {
        new_val = get_value(memory, index, T_IND);
    }
    return (new_val);
}

int get_special_value(char *memory, int index, char coding_byte,
    process_t *process)
{
    int value = 0;
    int new_val = 0;

    value = get_value(memory, index, coding_byte);
    if (coding_byte == T_REG) {
        if (get_reg_error(value) != 0) {
            process->index = -1;
            return (0);
        }
        new_val = process->registers[value - 1];
    }
    if (coding_byte == T_IND) {
        new_val = (short int) (value);
    }
    if (coding_byte == T_DIR) {
        new_val = value;
    }
    return (new_val);
}
