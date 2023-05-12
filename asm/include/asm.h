/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <stdio.h>
    #include "prog_list.h"

    typedef struct format_s {
        char *type;
        int bit1;
        int bit2;
    } format_t;

    prog_list_t *get_prog_list(FILE *fd);

#endif /* !ASM_H_ */
