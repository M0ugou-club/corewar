/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "op.h"

static int get_prog_size(prog_list_t *prog_list)
{
    prog_list_t *tmp = prog_list;
    int size = 0;

    while (tmp != NULL) {
        size += increase_index(tmp->command_int);
        tmp = tmp->next;
    }
    return (size);
}

static int make_header(prog_list_t *prog_list, int fd)
{
    header_t *header = NULL;
    int size = 0;

    header = malloc(sizeof(header_t));
    MALLOC_RETURN(header, -1);
    header->magic = 0;
    header->prog_size = 0;
    size = get_prog_size(prog_list);
    if (compil_header(prog_list, header, size) == 84) {
        return (-1);
    }
    header->prog_size = SWAP_ENDIAN(header->prog_size);
    header->magic = SWAP_ENDIAN(header->magic);
    write(fd, header, sizeof(header_t));
    return (0);
}

static int write_cor_file(prog_list_t *prog_list, char const *file_name)
{
    int fd = 0;

    fd = open_new_file(file_name);
    if (fd == -1) {
        return (-1);
    }
    if (make_header(prog_list, fd) != 0) {
        return (-1);
    }
    if (write_file(prog_list, fd) != 0) {
        return (-1);
    }
    return (0);
}

static int make_compil(prog_list_t *prog_list, char const *file_name)
{
    if (compile_line(prog_list) != 0) {
        return (-1);
    }
    if (get_all_label(prog_list) != 0) {
        return (-1);
    }
    if (change_label_value(prog_list) != 0) {
        return (-1);
    }
    if (write_cor_file(prog_list, file_name) != 0) {
        return (-1);
    }
    return (0);
}

int process_asm(char const *file_name)
{
    FILE *fd = NULL;
    prog_list_t *prog_list = NULL;

    fd = open_file(file_name);
    if (fd == NULL) {
        return (-1);
    }
    prog_list = get_prog_list(fd);
    if (prog_list == NULL) {
        return (-1);
    }
    if (get_line_array(prog_list) == -1) {
        return (-1);
    }
    if (make_compil(prog_list, file_name) == -1) {
        return (-1);
    }
    return (0);
}
