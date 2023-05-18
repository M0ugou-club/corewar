/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_new_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

static int get_index(char const *file_name)
{
    int i = 0;

    while (file_name[i] != '\0' && file_name[i] != '.'){
        i++;
    }
    return (i);
}

static char *create_new_file_name(char const *file_name, int index)
{
    static const char suffix[5] = ".cor";
    char *new_file_name = NULL;
    int len = 0;

    len = index + my_strlen(suffix);
    new_file_name = malloc(sizeof(char) * (len + 1));
    if (new_file_name == NULL) {
        return (NULL);
    }
    my_memset(new_file_name, '\0', len + 1);
    my_strncpy(new_file_name, file_name, index);
    my_strcat(new_file_name, suffix);
    return (new_file_name);
}

int open_new_file(char const *file_name)
{
    char *new_file = NULL;
    int index = 0;
    int fd = 0;

    index = get_index(file_name);
    new_file = create_new_file_name(file_name, index);
    if (new_file == NULL) {
        return (-1);
    }
    fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        free(new_file);
        return (-1);
    }
    free(new_file);
    return (fd);
}
