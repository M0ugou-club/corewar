/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_new_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

static int get_last_index(char const *file_name, int index_start)
{
    int i = index_start;

    while (file_name[i] != '\0' && file_name[i] != '.'){
        i++;
    }
    return (i);
}

static int get_first_index(char const *file_name)
{
    int i = 0;

    i = my_strlen(file_name);
    while (i >= 0) {
        if (file_name[i] == '/') {
            return (i + 1);
        }
        i--;
    }
    if (i < 0) {
        i = 0;
    }
    return (i);
}

static char *create_new_file_name(char const *file_name, int index_last,
    int index_start)
{
    static const char suffix[5] = ".cor";
    char *new_file_name = NULL;
    int len = 0;

    len = index_last - index_start + my_strlen(suffix);
    new_file_name = malloc(sizeof(char) * (len + 1));
    if (new_file_name == NULL) {
        return (NULL);
    }
    my_memset(new_file_name, '\0', len + 1);
    my_strncpy(new_file_name, &file_name[index_start],
        (index_last - index_start));
    my_strcat(new_file_name, suffix);
    return (new_file_name);
}

int open_new_file(char const *file_name)
{
    char *new_file = NULL;
    int index_first = 0;
    int index_last = 0;
    int fd = 0;

    index_first = get_first_index(file_name);
    index_last = get_last_index(file_name, index_first);
    new_file = create_new_file_name(file_name, index_last, index_first);
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
