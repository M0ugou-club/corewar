/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** error_handling
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static const char type_error[14] = "Invalid type\n";
static const char nb_arg_error[20] = "Invalid arg number\n";
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

static int compare_type(char type_array[], int fct_nb)
{
    int error = 0;
    int i = 0;

    while (i < MAX_ARGS_NUMBER && op_tab[fct_nb - 1].type[i] != '\0') {
        error = -1;
        if ((type_array[i] & op_tab[fct_nb - 1].type[i])) {
            error = 0;
        }
        if (error != 0) {
            write(2, type_error, my_strlen(type_error));
            return (-1);
        }
        i++;
    }
    return (error);
}

static int get_nbr_arg_error(char **line_array, int fct_nb)
{
    int nb_arg = 0;

    nb_arg = my_tablen(line_array);
    if (nb_arg != op_tab[fct_nb - 1].nbr_args) {
        write(2, nb_arg_error, my_strlen(nb_arg_error));
        return (-1);
    }
    return (0);
}

int error_compil(char **line_array, int fct_nb)
{
    char *type_array = NULL;
    int tab_len = 0;

    if (get_nbr_arg_error(&line_array[SKIP_COMMAND], fct_nb) != 0)
        return (-1);
    tab_len = my_tablen(line_array);
    type_array = malloc(sizeof(char) * (tab_len));
    MALLOC_RETURN(type_array, -1);
    my_memset(type_array, '\0', tab_len);
    for (int i = 0; line_array[i] != NULL && i < MAX_ARGS_NUMBER; i++) {
        if (i > 0) {
            fill_type(type_array, i - 1, line_array[i]);
        }
    }
    if (compare_type(type_array, fct_nb) == -1) {
        free(type_array);
        return (-1);
    }
    free(type_array);
    return (0);
}
