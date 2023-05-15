/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"

static const line_compil_t compil_tab[] = {{"live", NULL, 1},
{"ld", NULL, 2},
{"st", NULL, 3},
{"add", NULL, 4},
{"sub", NULL, 5},
{"and", &compile_operator, 6},
{"or", &compile_operator, 7},
{"xor", &compile_operator, 8},
{"zjmp", NULL, 9},
{"ldi", NULL, 10},
{"sti", NULL, 11},
{"fork", NULL, 12},
{"lld", NULL, 13},
{"lldi", NULL, 14},
{"lfork", NULL, 15},
{"aff", NULL, 16},
{NULL, NULL, -1}};

int get_command(prog_list_t *line, line_compil_t comp_line)
{
    for (int i = 0; line->line_array[i] != NULL; i++) {
        if (my_strncmp(line->line_array[i], comp_line.command,
            my_strlen(comp_line.command)) && comp_line.compil != NULL) {
        line->command_int = comp_line.compil(line, &line->line_array[i],
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
