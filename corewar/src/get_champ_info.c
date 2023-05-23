/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_champ
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "vm.h"
#include "op.h"
#include "my.h"

header_t *get_header(int fd)
{
    header_t *champ_header = NULL;

    champ_header = malloc(sizeof(header_t));
    MALLOC_RETURN(champ_header, NULL);
    if (read(fd, champ_header, sizeof(header_t)) != sizeof(header_t)) {
        return (NULL);
    }
    champ_header->magic = champ_header->magic;
    champ_header->prog_size = champ_header->prog_size;
    if (champ_header->magic != COREWAR_EXEC_MAGIC) {
        free(champ_header);
        return (NULL);
    }
    return (champ_header);
}

char *get_prog(int fd, header_t *champ_header)
{
    char *prog = NULL;
    int curr_pos = 0;
    int size_tot = 0;

    prog = malloc(sizeof(char) * (champ_header->prog_size + 1));
    MALLOC_RETURN(prog, NULL);
    my_memset(prog, '\0', champ_header->prog_size + 1);
    if (read(fd, prog, champ_header->prog_size) == champ_header->prog_size) {
        curr_pos = lseek(fd, 0, SEEK_CUR);
        size_tot = lseek(fd, 0, SEEK_END);
        if (curr_pos == size_tot) {
            return (prog);
        }
    }
    free(prog);
    return (NULL);
}

process_t *create_basic_process(int index, char *name, int nb_champ,
    process_t *process)
{
    process->cooldown = 0;
    process->index = index;
    process->last_lives = 0;
    process->next = NULL;
    process->nb_champ = nb_champ;
    process->registers = malloc(sizeof(int) * (REG_NUMBER + 1));
    MALLOC_RETURN(process->registers, NULL);
    my_int_memset(process->registers, -1, REG_NUMBER + 1);
    process->id = malloc(sizeof(char) * (my_strlen(name) + 1));
    if (process->id == NULL) {
        free(process->registers);
        free(process);
        return (NULL);
    }
    my_memset(process->id, '\0', (my_strlen(name) + 1));
    process->id = my_strcpy(process->id, name);
    return (process);
}
