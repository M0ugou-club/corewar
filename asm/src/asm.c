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
#include "my.h"

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

static int make_header(prog_list_t *prog_list, header_t *header)
{
    int size = 0;

    my_memset(header->prog_name, '\0', PROG_NAME_LENGTH + 1);
    my_memset(header->comment, '\0', COMMENT_LENGTH + 1);
    header->magic = 0;
    header->prog_size = 0;
    size = get_prog_size(prog_list);
    if (compil_header(prog_list, header, size) == 84) {
        return (-1);
    }
    if ((my_strlen(header->prog_name) > PROG_NAME_LENGTH
        || my_strlen(header->comment) > COMMENT_LENGTH)) {
        write(2, "Command or name too long\n", 25);
        return (-1);
    }
    header->prog_size = SWAP_ENDIAN(header->prog_size);
    header->magic = SWAP_ENDIAN(header->magic);
    return (0);
}

static int write_cor_file(prog_list_t *prog_list, char const *file_name)
{
    int fd = 0;
    header_t header = {0};

    if (make_header(prog_list, &header) != 0) {
        return (-1);
    }
    fd = open_new_file(file_name);
    if (fd == -1) {
        return (-1);
    }
    write(fd, &header, sizeof(header));
    if (write_file(prog_list, fd) != 0) {
        close(fd);
        return (-1);
    }
    close(fd);
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
    int error = 0;

    fd = open_file(file_name);
    if (fd == NULL) {
        return (-1);
    }
    prog_list = get_prog_list(fd);
    if (prog_list == NULL) {
        fclose(fd);
        return (-1);
    }
    error = get_line_array(prog_list);
    if (error == 0) {
        error = make_compil(prog_list, file_name);
    }
    fclose(fd);
    free_prog_list(prog_list);
    return (error);
}
