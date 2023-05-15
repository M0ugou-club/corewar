/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** operator
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int error_operator(char **line_array)
{
    int i = 0;
    int index_error = 3;

    while (line_array[i] != NULL) {
        i++;
    }
    if (i != index_error) {
        return (-1);
    }
    if (line_array[index_error] == NULL) {
        return (-1);
    }
    if (my_strncmp(line_array[index_error], "r", my_strlen("r")) != 0) {
        return (-1);
    }
    return (0);
}

command_int_t *compile_operator(char **line_array, int fnct_nbr)
{
    command_int_t *command_int = NULL;

    if (load_int_tab() == -1) {
        return (NULL);
    }
    if (error_operator(line_array) != 0) {
        write(2, "error\n", 6);
        return (NULL);
    }
    if (fill_multiple_args_line(command_int, line_array, fnct_nbr) != 0) {
        return (NULL);
    }
    return (command_int);
}
