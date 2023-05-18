/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** error_handling
*/

#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static const char type_error[14] = "Invalid type\n";
static const type_t type[] = {{"r", T_REG},
{"%", T_DIR},
{"", T_IND},
{NULL, -1}};

static int fill_type(char type_array[], int index, char const *line_array)
{
    for (int i = 0; type[i].info != -1; i++) {
        if (my_strncmp(line_array, type[i].c, my_strlen(type[i].c)) == 0) {
            type_array[index] = type[i].info;
            return (0);
        }
    }
    return (0);
}

static int compare_type(char type_array[], int fct_nb, int tab_len)
{
    int error = 0;
    int i = 0;

    if (tab_len - 1 != op_tab[fct_nb - 1].nbr_args) {
        return (-1);
    }
    while (i < MAX_ARGS_NUMBER && op_tab[fct_nb - 1].type[i] != '\0') {
        error = -1;
        if ((type_array[i] & op_tab[fct_nb - 1].type[i])) {
            error = 0;
        }
        if (error != 0) {
            return (-1);
        }
        i++;
    }
    return (error);
}

int error_compil(char **line_array, int fct_nb)
{
    char type_array[MAX_ARGS_NUMBER + 1];
    int tab_len = 0;

    my_memset(type_array, '\0', MAX_ARGS_NUMBER + 1);
    for (int i = 0; line_array[i] != NULL && i < MAX_ARGS_NUMBER; i++) {
        if (i > 0) {
            fill_type(type_array, i - 1, line_array[i]);
        }
    }
    tab_len = my_tablen(line_array);
    if (compare_type(type_array, fct_nb, tab_len) == -1) {
        write(2, type_error, my_strlen(type_error));
        return (-1);
    }
    return (0);
}
