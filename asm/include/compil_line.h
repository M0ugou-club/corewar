/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#ifndef COMPIL_LINE_H_
    #define COMPIL_LINE_H_

    #include "asm.h"

    typedef struct line_compil_s {
        char *command;
        command_int_t *(* compil) (char **line_array, int fnct_nbr);
        int fnct_nbr;
    } line_compil_t;

    command_int_t *compil_basic(char **line_array, int fnct_nbr);
    command_int_t *compil_index(char **line_array, int fnct_nbr);
    command_int_t *compil_one_format_index(char **line_array, int nb_ft);
    command_int_t *compil_one_format(char **line_array, int nb_ft);
    int get_nbr_value(char **value , int *value_size, char const *arg, int index);
    int get_format_value(char **args);
    int fill_multiple_args_line(command_int_t *command_int, char **line_array,
        int fnct_nbr);
    int change_size_index(command_int_t *command_int);

#endif /* !COMPIL_LINE_H_ */
