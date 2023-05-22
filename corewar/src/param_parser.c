/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param_parser
*/

#include <stdlib.h>
#include "my.h"
#include "vm.h"

int is_opt(char **av, int i, process_t *process)
{
    if (my_strcmp(av[i], "-a") && av[i + 1] != NULL) {
        process->index = my_atoi(av[i +1]);
        return (0);
    }
    if (my_strcmp(av[i], "-n") && av[i + 1] != NULL) {
        process->nb_champ = my_atoi(av[i +1]);
        return (0);
    }
    process->id = av[i];
    return -1;
}

process_t *parse_line(char **av)
{
    int nb_champ = 1;
    process_t *process = NULL;

    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    for (int i = 1; av[i] != NULL; i++) {
        if (is_opt(av, i, process) == -1) {
            process->next = malloc(sizeof(process_t));
            MALLOC_RETURN(process->next, NULL);
            process = process->next;
            nb_champ += 1;
        }
        i += 1;
    }
    return (process);
}
