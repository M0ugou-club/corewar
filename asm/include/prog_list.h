/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** prog_line_list
*/

#ifndef PROG_LINE_LIST_H_
    #define PROG_LINE_LIST_H_

    typedef struct prog_list_s prog_list_t;

    typedef struct prog_list_s {
        char *line;
        prog_list_t *next;
    };

#endif /* !PROG_LINE_LIST_H_ */
