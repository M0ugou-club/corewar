/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"

command_int_t *compil_one_format_index(char **line_array, int nb_ft)
{
    command_int_t *command_int = NULL;

    command_int = load_int_tab();
    if (command_int == NULL) {
        return (NULL);
    }
    command_int->value[0] = fill_char_tab(nb_ft, 1);
    command_int->value_size[0] = 1;
    if (get_nbr_value(command_int->value,
        command_int->value_size, line_array[1], 1) != 0 ) {
        return NULL;
    }
    change_size_index(command_int);
    return (command_int);
}

command_int_t *compil_one_format(char **line_array, int nb_ft)
{
    command_int_t *command_int = NULL;

    command_int = load_int_tab();
    if (command_int == NULL) {
        return (NULL);
    }
    command_int->value[0] = fill_char_tab(nb_ft, 1);
    command_int->value_size[0] = 1;
    if (get_nbr_value(command_int->value,
        command_int->value_size, line_array[1], 1) != 0 ) {
        return NULL;
    }
    return (command_int);
}
