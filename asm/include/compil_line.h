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
        command_int_t (* compil) (prog_list_t *line);
    } line_compil_t;

#endif /* !COMPIL_LINE_H_ */
