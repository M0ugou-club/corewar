/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param_parser
*/

#include <stdlib.h>
#include <fcntl.h>
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
    return -1;
}

process_t *create_process(char *name, process_t *process)
{
    header_t *header = NULL;
    int fd = 0;

    fd = open(name, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    header = get_header(fd);
    process->id = header->prog_name;
}

process_t *param_parser(char **av)
{
    int nb_champ = 1;
    char *name = NULL;
    process_t *process = NULL;
    process_t *head = NULL;

    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    for (int i = 1; av[i] != NULL; i++) {
        if (is_opt(av, i, process) == -1) {
            process = create_process(av[i], process);
            process->nb_champ = nb_champ;
            nb_champ += 1;
            head = add_process(process, head);
            process = malloc(sizeof(process_t));
            MALLOC_RETURN(process, NULL);
        }
        i += 1;
    }
    return (head);
}
