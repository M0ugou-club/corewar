/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fill_line
*/

#include "stddef.h"
#include "asm.h"

int fill_multiple_args_line(command_int_t *command_int, char **line_array,
    int fnct_nbr)
{
    int index_char = 1;
    int index_int = 0;
    int error = 0;

    command_int->value[index_int] = fnct_nbr;
    command_int->value_size[index_int] = 1;
    index_int++;
    command_int->value[index_int] =
        get_format_value(&line_array[index_char]);
    command_int->value_size[index_int] = 1;
    index_int++;
    while (line_array[index_char] != NULL && index_int < 6) {
        error += get_nbr_value(command_int->value,
            command_int->value_size, line_array[index_char], index_int);
        index_char++;
        index_int++;
    }
    return (error);
}
