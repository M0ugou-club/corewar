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
        command_int_t *(* compil) (prog_list_t *line, char **line_array,
            int fnct_nbr);
        int fnct_nbr;
    } line_compil_t;

    command_int_t *compile_operator(prog_list_t *line, char **line_array,
        int fnct_nbr);

#endif /* !COMPIL_LINE_H_ */
