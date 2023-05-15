/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** operator
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int fill_operator_line(prog_list_t *line, char **line_array, int fnct_nbr)
{
    int index_char = 1;
    int index_int = 0;
    int error = 0;

    line->command_int->value[index_int] = fnct_nbr;
    line->command_int->value_size[index_int] = 1;
    index_int++;
    line->command_int->value[index_int] = get_format_value(&line_array[index_char]);
    line->command_int->value_size[index_int] = 1;
    index_int++;
    while (line_array[index_char] != NULL && index_int < 6) {
        error += get_nbr_value(line->command_int->value,
            line->command_int->value_size, line_array[index_char], index_int);
        index_char++;
        index_int++;
    }
    return (error);
}

int error_operator(char **line_array)
{
    int index_error = 3;

    for (int i = 0; i < index_error; i++) {
        if (line_array[i] == NULL) {
            return (-1);
        }
    }
    if (line_array[index_error] == NULL) {
        return (-1);
    }
    if (my_strncmp(line_array[index_error], "r", my_strlen("r")) != 0) {
        return (-1);
    }
    return (0);
}

command_int_t *compile_operator(prog_list_t *line, char **line_array, int fnct_nbr)
{
    if (load_int_tab(line) == -1) {
        return (NULL);
    }
    if (error_operator(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_operator_line(line, line_array, fnct_nbr) != 0) {
        return (NULL);
    }
    return (line->command_int);
}
