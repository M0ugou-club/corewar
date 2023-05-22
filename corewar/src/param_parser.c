/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param_parser
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "vm.h"

int is_opt(char **av, int i, process_t *process)
{
    if (my_strcmp(av[i], "-a") && av[i + 1] != NULL) {
        if (my_str_is_num(av[1]))
        process->index = my_atoi(av[i + 1]);
        return (0);
    }
    if (my_strcmp(av[i], "-n") && av[i + 1] != NULL) {
        process->nb_champ = my_atoi(av[i + 1]);
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
    free(header);
    close(fd);
    return (process);
}

process_t *init_next_champ(char *champ_name, process_t *process,
process_t *head)
{
    process = create_process(champ_name, process);
    head = add_process(process, head);
    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    process->nb_champ = 0;
    return process;
}

process_t *param_parser(char **av)
{
    int nb_champ = 1;
    process_t *process = NULL;
    process_t *head = NULL;

    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    process->nb_champ = 0;
    for (int i = 1; av[i] != NULL; i++) {
        if (process->nb_champ == 0) {
            process->nb_champ = nb_champ;
        }
        if (is_opt(av, i, process) == -1) {
            nb_champ += 1;
            process = init_next_champ(av[i], process, head);
        } else {
            i += 1;
        }
    }
    return (head);
}
