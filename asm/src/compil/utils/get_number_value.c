/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_number_value
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static const char error_str[23] = "Wrong register value.\n";
static const type_t type[] = {{"r", 1},
{"%", DIR_SIZE},
{"", IND_SIZE},
{NULL, -1}};

static int get_error_value(char const *arg, int index_nb)
{
    int error = 0;

    error = my_str_is_num(&arg[index_nb]);
    if (error != 0) {
        error = is_label(arg);
    }
    return (error);
}

char *fill_char_tab(int num, int size, int i)
{
    char *num_tab = NULL;

    if (i == REG_INDEX && (num > REG_NUMBER || num < 1)) {
        write(2, error_str, my_strlen(error_str));
        return (NULL);
    }
    num_tab = malloc(sizeof(char) * (size + 1));
    MALLOC_RETURN(num_tab, NULL);
    my_memset(num_tab, '\0', size + 1);
    if (size != sizeof(int)) {
        num = num % my_power(BYTE_VALUE, size);
    }
    if (num < 0) {
        my_memset(num_tab, -1, size);
    }
    for (int i = size - 1; i >= 0 && num != 0; i--) {
        num_tab[i] = num % BYTE_VALUE;
        num = num / BYTE_VALUE;
    }
    return (num_tab);
}

int get_nbr_value(char **value , int *value_size, char const *arg, int index)
{
    int error = 0;
    int i = 0;
    int index_nb = 1;
    int num = 0;

    while (type[i].c != NULL) {
        if (i == 2) {
            index_nb--;
        }
        if (my_strncmp(arg, type[i].c, my_strlen(type[i].c)) == 0) {
            error = get_error_value(arg, index_nb);
            value_size[index] = type[i].info;
            num = my_atoi(&arg[index_nb]);
            value[index] = fill_char_tab(num, value_size[index], i);
            MALLOC_RETURN(value[index], -1);
            return (error);
        }
        i++;
    }
    return (error);
}
