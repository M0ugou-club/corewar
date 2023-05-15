/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"

command_int_t *compil_live(prog_list_t *line, char **line_array, int nb_ft)
{
    line->command_int = malloc(sizeof(command_int_t));
    if (line->command_int == NULL) {
        return NULL;
    }
    if (line->command_int->value == NULL
        || line->command_int->value_size == NULL) {
        free(line->command_int);
        return (NULL);
    }
    my_int_memset(line->command_int->value, -1, MAX_LENGTH);
    my_int_memset(line->command_int->value_size, -1, MAX_LENGTH);
    line->command_int->value = malloc(sizeof(int) * MAX_LENGTH);
    line->command_int->value_size = malloc(sizeof(int) * MAX_LENGTH);
    line->command_int->value[0] = nb_ft;
    line->command_int->value_size[0] = 1;
    if (get_nbr_value(line->command_int->value,
        line->command_int->value_size, line_array[1], 1) != 0 ) {
        return NULL;
    }
}
