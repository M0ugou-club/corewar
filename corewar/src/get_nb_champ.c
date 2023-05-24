/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_nb_champ
*/

#include <stddef.h>
#include <fcntl.h>

int get_nb_champ(char **argv)
{
    int nb_champ = 0;
    int fd = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd != -1) {
            nb_champ++;
            close(fd);
        }
    }
    return (nb_champ);
}
