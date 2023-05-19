/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"

static const line_compil_t compil_tab[] = {{"live", &compil_one_format, 1},
{"ld", &compil_basic, 2},
{"st", &compil_basic, 3},
{"add", &compil_basic, 4},
{"sub", &compil_basic, 5},
{"and", &compil_basic, 6},
{"or", &compil_basic, 7},
{"xor", &compil_basic, 8},
{"zjmp", &compil_one_format_index, 9},
{"ldi", &compil_index, 10},
{"sti", &compil_index, 11},
{"fork", &compil_one_format_index, 12},
{"lld", &compil_basic, 13},
{"lldi", &compil_index, 14},
{"lfork", &compil_one_format_index, 15},
{"aff", &compil_basic, 16},
{NULL, NULL, -1}};

static int get_command(prog_list_t *line, line_compil_t comp_line)
{
    if (line->line_array == NULL) {
        return (0);
    }
    for (int i = 0; line->line_array[i] != NULL; i++) {
        if ((my_strcmp(line->line_array[i], comp_line.command) == 0)
            && (comp_line.compil != NULL)) {
            line->command_int = comp_line.compil(&line->line_array[i],
                comp_line.fnct_nbr);
            RETURN_ERROR(line->command_int, NULL, -1);
        }
    }
    return (0);
}

int compile_line(prog_list_t *line)
{
    prog_list_t *tmp = line;
    int i = 0;
    int return_value = 0;

    while (tmp != NULL) {
        while (compil_tab[i].command != NULL) {
            return_value += get_command(tmp, compil_tab[i]);
            i++;
        }
        if ((return_value != 0 || tmp->command_int == NULL)
            && my_strncmp(tmp->line, ".name", my_strlen(".name") != 0)
            && my_strncmp(tmp->line, ".comment", my_strlen(".comment") != 0)) {
            return (-1);
        }
        i = 0;
        tmp = tmp->next;
    }
    return (0);
}
