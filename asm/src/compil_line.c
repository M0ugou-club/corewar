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
{"ld", &compile_load, 2},
{"st", &compile_store, 3},
{"add", &compile_calculation, 4},
{"sub", &compile_calculation, 5},
{"and", &compile_operator, 6},
{"or", &compile_operator, 7},
{"xor", &compile_operator, 8},
{"zjmp", &compil_one_format_index, 9},
{"ldi", &compile_load_index, 10},
{"sti", &compile_store, 11},
{"fork", &compil_one_format_index, 12},
{"lld", &compile_load, 13},
{"lldi", &compile_load_index, 14},
{"lfork", &compil_one_format_index, 15},
{"aff", &compil_aff, 16},
{NULL, NULL, -1}};

int get_command(prog_list_t *line, line_compil_t comp_line)
{
    for (int i = 0; line->line_array[i] != NULL; i++) {
        if (my_strncmp(line->line_array[i], comp_line.command,
            my_strlen(comp_line.command)) && comp_line.compil != NULL) {
        line->command_int = comp_line.compil(&line->line_array[i],
            comp_line.fnct_nbr);
        }
    }
    return (0);
}

int compile_line(prog_list_t *line)
{
    prog_list_t *tmp = line;
    int i = 0;

    while (tmp != NULL) {
        while (compil_tab[i].command != NULL) {
            get_command(tmp, compil_tab[i]);
            i++;
        }
        if (line->command_int == NULL
            && my_strncmp(tmp->line, ".name", my_strlen(".name") == 0)
            && my_strncmp(tmp->line, ".comment", my_strlen(".comment") == 0)) {
            return (-1);
        }
        i = 0;
        tmp = tmp->next;
    }
    return (0);
}
