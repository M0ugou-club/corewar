/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_loop.c
*/

#include <stdlib.h>
#include "fonction.h"

static const function_t function[] = { {1, NULL},
{2, NULL},
{3, NULL},
{4, NULL},
{5, NULL},
{6, NULL},
{7, NULL},
{8, NULL},
{9, NULL},
{10, NULL},
{11, NULL},
{12, NULL},
{13, NULL},
{14, NULL},
{15, NULL},
{16, NULL},
{-1, NULL}};

static int parse_champ(process_t *process, char *memory)
{
    if (process->index == -1) {
        return 0;
    }
    for (int i = 0; function[i].id != -1; i++) {
        if (function[i].action && memory[process->index] == function[i].id) {
            process->index = function[i].action;
        }
    }
    process->index = -1;
    return 0;
}

int loop_process(process_t *process, char *memory)
{
    process_t *tmp = process;

    while (tmp) {
        parse_champ(tmp, memory);
        tmp = tmp->next;
    }
    return 0;
}