/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_type_error
*/

#include "op.h"

int get_type_error(char const *cb_tab, int fct_nb)
{
    int error = 0;
    int i = 0;

    while (i < MAX_ARGS_NUMBER && op_tab[fct_nb - 1].type[i] != '\0') {
        error = -1;
        if ((cb_tab[i] & op_tab[fct_nb - 1].type[i])) {
            error = 0;
        }
        if (error != 0) {
            return (-1);
        }
        i++;
    }
    return (error);
}
