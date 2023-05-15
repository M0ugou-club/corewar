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
    int i = 0;

    line->command_int->value[i] = fnct_nbr;
    line->command_int->value_size[i] = 1;
    i++;
    line->command_int->value[i] = get_format_value(line_array);
    line->command_int->value_size[i] = 1;
    i++;
    while (line_array[i] != NULL) {
        get_nbr_value(line->command_int->value, line->command_int->value_size, line_array[i], i);
        i++;
    }
    return (0);
}

command_int_t *compile_operator(prog_list_t *line, char **line_array, int fnct_nbr)
{
    line->command_int = malloc(sizeof(command_int_t));
    if (line->command_int == NULL) {
        return NULL;
    }
    line->command_int->value = malloc(sizeof(int) * MAX_LENGTH);
    line->command_int->value_size = malloc(sizeof(int) * MAX_LENGTH);
    if (line->command_int->value == NULL
        || line->command_int->value_size == NULL) {
        free(line->command_int);
        return (NULL);
    }
    my_int_memset(line->command_int->value, -1, MAX_LENGTH);
    my_int_memset(line->command_int->value_size, -1, MAX_LENGTH);
}
