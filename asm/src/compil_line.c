/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** compil_line
*/

#include "asm.h"
#include "my.h"
#include "compil_line.h"

static const line_compil_t compil_tab[] = {{"live", NULL},
{"ld", NULL},
{"st", NULL},
{"add", NULL},
{"sub", NULL},
{"and", NULL},
{"or", NULL},
{"xor", NULL},
{"zjmp", NULL},
{"ldi", NULL},
{"sti", NULL},
{"fork", NULL},
{"lld", NULL},
{"lldi", NULL},
{"lfork", NULL},
{"aff", NULL},
{NULL, NULL}};

int get_command(prog_list_t *line, line_compil_t comp_line)
{
    for (int i = 0; line->line_array[i] != NULL; i++) {
        if (my_strncmp(line->line_array[i], comp_line.command,
            my_strlen(comp_line.command)) && comp_line.compil != NULL) {
        line->command_int = comp_line.compil;
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
