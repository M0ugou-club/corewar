/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** open_fille
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

char const error[31] = "Couldn't finf the file given.\n";

FILE *open_file(char const *file_name)
{
    FILE *fd = 0;

    fd = fopen(file_name, "r");
    if (fd  == NULL) {
        write(2, error, my_strlen(error));
    }
    return (fd);
}
