/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdio.h>
#include "asm.h"

int make_compil(prog_list_t *prog_list)
{
    if (compile_line(prog_list) != 0) {
        return (-1);
    }
    if (change_label_value(prog_list) != 0) {
        return (-1);
    }
   // if (compile_header() != 0) {
   //     return (-1);
   // }
    write_file(prog_list);
    return (0);
}

int process_asm(char const *file_name)
{
    FILE *fd = NULL;
    prog_list_t *prog_list = NULL;

    fd = open_file(file_name);
    if (fd == NULL) {
        return (-1);
    }
    prog_list = get_prog_list(fd);
    if (prog_list == NULL) {
        return (-1);
    }
    make_compil(prog_list);
    return (0);
}
