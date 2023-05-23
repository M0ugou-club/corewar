/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param_parser
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "process.h"
#include "my.h"
#include "vm.h"

static process_t *create_process(process_t *process, vm_t *vm, int fd)
{
    header_t header = {0};
    char *prog_champ = NULL;

    if (get_header(fd, &header) == -1)
        return (NULL);
    prog_champ = get_prog(fd, &header);
    if (prog_champ == NULL)
        return (NULL);
    process = create_basic_process(header.prog_name, process);
    if (process == NULL) {
        free(prog_champ);
        return (NULL);
    }
    if (put_champ(process, vm, prog_champ) == -1) {
        free_champ(process);
        free(prog_champ);
        return (NULL);
    }
    free(prog_champ);
    return (process);
}

process_t *init_next_champ(char *champ_name, process_t *process,
    process_t *head, vm_t *vm)
{
    int fd = 0;

    fd = open(champ_name, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    process = create_process(process, vm, fd);
    close(fd);
    MALLOC_RETURN(process, NULL);
    head = add_process(process, head);
    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    process->nb_champ = 0;
    return process;
}

int test_parser(process_t *process, process_t *head, char *arg, vm_t *vm)
{
    static int nb_champ = 1;

    if (process->nb_champ == 0) {
        process->nb_champ = nb_champ;
        nb_champ += 1;
    }
    process = init_next_champ(arg, process, head, vm);
    MALLOC_RETURN(process, -1);
    return (0);
}

process_t *param_parser(char **av, vm_t *vm)
{
    process_t *process = NULL;
    process_t *head = NULL;
    int val_ret = 0;

    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    process->nb_champ = 0;
    for (int i = 1; av[i] != NULL; i++) {
        val_ret = is_opt(av, i, process, vm) == 1;
        if (val_ret == 1) {
            val_ret = test_parser(process, head, av[i], vm);
        } else {
            i++;
        }
        if (val_ret == -1) {
            free_champ(head);
            return (NULL);
        }
    }
    return (head);
}
