/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_number_value
*/

#include "op.h"
#include "asm.h"
#include "my.h"

static const type_t type[] = {{"r", REG_SIZE},
{"%", DIR_SIZE},
{"", IND_SIZE},
{NULL, -1}};

int get_nbr_value(int *value , int *value_size, char *arg, int index)
{
    int error = 0;
    int i = 0;
    int index_nb = 1;

    while (type[i].c != NULL) {
        if (i == 2) {
            index_nb--;
        }
        if (my_strncmp(arg, type[i].c, my_strlen(type[i].c)) == 0) {
            error = my_str_is_num(&arg[index_nb]);
            value[index] = my_atoi(&arg[index_nb]);
            value_size[index] = type[i].lenght;
        }
        i++;
    }
    return (error);
}
