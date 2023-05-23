/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_coding_byte
*/

#include <stdlib.h>
#include "vm.h"
#include "op.h"
#include "my.h"

static const type_value_t type[] = {{0, 0},
{1, T_REG},
{2, T_DIR},
{3, T_IND},
{-1, -1}};

static int fill_cb_type(char *cb_tab, int i, int value)
{
    for (int j = 0; type[j].value != -1; j++) {
        if (value == type[j].value) {
            cb_tab[i] = type[j].type;
        }
    }
    return (0);
}

char *get_coding_byte(char coding_bytes)
{
    char *cb_tab = NULL;
    int tmp = 0;

    cb_tab = malloc(sizeof(char) * (CODYNG_BYTE_LEN + 1));
    MALLOC_RETURN(cb_tab, NULL);
    my_memset(cb_tab, '\0', CODYNG_BYTE_LEN + 1);
    for (int i = CODYNG_BYTE_LEN - 1; i >= 0; i--) {
        tmp = coding_bytes % (BIT_VALUE * 2);
        coding_bytes = coding_bytes / (BIT_VALUE * 2);
        fill_cb_type(cb_tab, i, tmp);
    }
    return (cb_tab);
}
