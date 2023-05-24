/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_opt
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "vm.h"

static const char ERROR[] = "ERROR: invalid argument\n";

static int is_dump(char **av, int i, process_t *process)
{
    if (my_strcmp(av[i], "-dump") == 0 && av[i + 1] != NULL) {
        if (my_str_is_num(av[i + 1]) == -1) {
            write(2, ERROR, sizeof(ERROR));
            return (-1);
        }
        return (0);
    }
    return (1);
}

int is_opt(char **av, int i, process_t *process)
{
    if (my_strcmp(av[i], "-a") == 0 && av[i + 1] != NULL) {
        if (my_str_is_num(av[i + 1]) == -1) {
            write(2, ERROR, sizeof(ERROR));
            return (-1);
        }
        process->index = my_atoi(av[i + 1]);
        return (0);
    }
    if (my_strcmp(av[i], "-n") == 0 && av[i + 1] != NULL) {
        if (my_str_is_num(av[i + 1]) == -1) {
            write(2, ERROR, sizeof(ERROR));
            return (-1);
        }
        process->nb_champ = my_atoi(av[i + 1]);
        return (0);
    }
    if (is_dump(av, i, process) != 1)
        return (is_dump(av, i, process));
    return 1;
}