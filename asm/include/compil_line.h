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

    command_int_t *compile_operator(char **line_array, int fnct_nbr);
    command_int_t *compile_calculation(char **line_array, int fnct_nbr);
    command_int_t *compile_store(char **line_array, int fnct_nbr);
    command_int_t *compile_store_index(char **line_array, int fnct_nbr);
    command_int_t *compile_load(char **line_array, int fnct_nbr);
    command_int_t *compile_load_index(char **line_array, int fnct_nbr);
    command_int_t *compil_aff(char **line_array, int nb_ft);
    command_int_t *compil_one_format_index(char **line_array, int nb_ft);
    command_int_t *compil_one_format(char **line_array, int nb_ft);

#endif /* !COMPIL_LINE_H_ */
