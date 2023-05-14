/*
** EPITECH PROJECT, 2023
** asm
** File description:
** compil_header.c
*/

#include <stdlib.h>
#include "error.h"
#include "my.h"

static int count_quote(const char *line)
{
    int compt = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"') {
            compt++;
        }
    }
    if (compt != 2) {
        return SYNTAX_ERROR_STATUS;
    }
}

int get_name(file_t *file)
{
    if (file->line) {
        if (my_strncmp(file->line, ".name ", 6) != 0
            && my_strncmp(file->line, ".comment ", 9) == 0) {
            return COMMENT_ERROR_STATUS;
        }
        if (my_strncmp(file->line, ".name ", 6) != 0) {
            return NAME_FIRST_LINE_ERROR_STATUS;
        }
        if (my_strncmp(file->line, ".name \"", 7) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
        if (count_quote(file->line) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
    }
    return 0;
}

int get_comment(file_t *file)
{
    if (file && file->line) {
        if (my_strncmp(file->line, ".comment \"", 10) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
        if (count_quote(file->line) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
    }
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
        status = get_comment(temp);
        status = error_handling(status);
    }
    return status;
}
