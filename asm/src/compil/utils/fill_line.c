/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fill_line
*/

#include <stdlib.h>
#include "asm.h"

int set_first_two_args(command_int_t *command_int, int fnct_nbr,
    char **line_array)
{
    int index_int = 0;
    int index_char = 1;
    int num = 0;

    command_int->value[index_int] = fill_char_tab(fnct_nbr, 1);
    MALLOC_RETURN(command_int->value[index_int], -1);
    command_int->value_size[index_int] = 1;
    index_int++;
    num = get_format_value(&line_array[index_char]);
    command_int->value[index_int] = fill_char_tab(num, 1);
    MALLOC_RETURN(command_int->value[index_int], -1);
    command_int->value_size[index_int] = 1;
    index_int++;
    return (index_int);
}

int fill_multiple_args_line(command_int_t *command_int, char **line_array,
    int fnct_nbr)
{
    int index_char = 1;
    int index_int = 0;
    int error = 0;

    index_int = set_first_two_args(command_int, fnct_nbr, line_array);
    if (index_int == -1) {
        return (-1);
    }
    while (line_array != NULL && line_array[index_char] != NULL
        && index_int < MAX_LENGTH) {
        error += get_nbr_value(command_int->value,
            command_int->value_size, line_array[index_char], index_int);
        index_char++;
        index_int++;
    }
    return (error);
}
