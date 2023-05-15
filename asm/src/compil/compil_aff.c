/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"
#include "op.h"

int error_aff(char **line_array)
{
    return (0);
}

command_int_t *compil_aff(char **line_array, int nb_ft)
{
    command_int_t *command_int = NULL;

    if (load_int_tab() == -1) {
        return (NULL);
    }
    if (error_aff(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_multiple_args_line(command_int, line_array, nb_ft) != 0) {
        return (NULL);
    }
    return (command_int);
}
