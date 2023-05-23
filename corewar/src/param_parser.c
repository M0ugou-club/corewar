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

static const char ERROR[] = "ERROR: invalid argument\n";

int is_opt(char *arg, process_t *process)
{
    if (my_strcmp(arg, "-a") && arg != NULL) {
        if (my_str_is_num(arg) == -1) {
            write(2, ERROR, sizeof(ERROR));
            return (-1);
        }
        process->index = my_atoi(arg);
        return (0);
    }
    if (my_strcmp(arg, "-n") && arg != NULL) {
        if (my_str_is_num(arg) == -1) {
            write(2, ERROR, sizeof(ERROR));
            return (-1);
        }
        process->nb_champ = my_atoi(arg);
        return (0);
    }
    return 1;
}

process_t *create_process(char *name, process_t *process, vm_t *vm, int fd)
{
    header_t header = {0};
    char *prog_champ = NULL;

    if (get_header(fd, &header) == -1) {
        close(fd);
        return (NULL);
    }
    prog_champ = get_prog(fd, &header);
    if (prog_champ == NULL) {
        close(fd);
        return (NULL);
    }
    process = create_basic_process(header.prog_name, process);
    if (process == NULL) {
        close(fd);
        return (NULL);
    }
    close(fd);
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
    process = create_process(champ_name, process, vm, fd);
    close(fd);
    MALLOC_RETURN(process, NULL);
    head = add_process(process, head);
    process = malloc(sizeof(process_t));
    MALLOC_RETURN(process, NULL);
    process->nb_champ = 0;
    return process;
}

int test_parser(process_t *process, process_t *head, char arg, vm_t *vm)
{
    static int nb_champ = 1;
    int val_ret = 0;

    if (process->nb_champ == 0) {
        process->nb_champ = nb_champ;
    }
    val_ret = is_opt(arg, process);
    if (val_ret == -1) {
        return (-1);
    }
    if (val_ret == 1) {
        nb_champ += 1;
        process = init_next_champ(arg, process, head, nb_champ);
        MALLOC_RETURN(process, -1);
    } else {
        return (1);
    }
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
        val_ret = test_parser(process, head, av[i], vm);
        if (val_ret == -1) {
            return (NULL);
        } else {
            i += val_ret;
        }
    }
    return (head);
}
