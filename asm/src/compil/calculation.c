/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** calculation
*/

#include "asm.h"

int error_calculation(char **line_array)
{
    return (0);
}

command_int_t *compile_calculation(char **line_array, int fnct_nbr)
{
    command_int_t *command_int = NULL;

    command_int = load_int_tab();
    if (command_int == NULL) {
        return (NULL);
    }
    if (error_calculation(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_multiple_args_line(command_int, line_array, fnct_nbr) != 0) {
        return (NULL);
    }
    return (command_int);
}
