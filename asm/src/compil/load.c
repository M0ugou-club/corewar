/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** load
*/

#include <stddef.h>
#include "asm.h"

int error_load(char **line_array)
{
    return (0);
}

command_int_t *compile_load(char **line_array, int fnct_nbr)
{
    command_int_t *command_int = NULL;

    if (load_int_tab() == -1) {
        return (NULL);
    }
    if (error_load(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_multiple_args_line(command_int, line_array, fnct_nbr) != 0) {
        return (NULL);
    }
    return (command_int);
}

int error_load_index(char **line_array)
{
    return (0);
}

command_int_t *compile_load_index(char **line_array, int fnct_nbr)
{
    command_int_t *command_int = NULL;

    if (load_int_tab() == -1) {
        return (NULL);
    }
    if (error_load_index(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_multiple_args_line(command_int, line_array, fnct_nbr) != 0) {
        return (NULL);
    }
    return (command_int);
}
