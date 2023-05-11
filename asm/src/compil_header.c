/*
** EPITECH PROJECT, 2023
** asm
** File description:
** compil_header.c
*/

#include <stdlib.h>

int get_name(file_t *file)
{
    return 0;
}

int get_comment(file_t *file)
{
    return 0;
}

int error_handling(int status)
{
    return 0;
}

int compil_header(file_t *file)
{
    file_t *temp = NULL;
    int status = 0;

    if (file) {
        temp = file;
        status = get_name(temp);
        status = error_handling(status);
        if (status == 84) {
            return 84;
        }
        temp = temp->next;
        status = get_command(temp);
        status = error_handling(status);
    }
    return status;
}
