/*
** EPITECH PROJECT, 2023
** asm
** File description:
** compil_header.c
*/

#include <stdlib.h>
#include "error.h"
#include "my.h"

static int count_text(file_t *file, char *text)
{
    file_t *temp = file;
    int compt = 0;

    while (temp) {
        if (my_strncmp(temp->line, text, my_strlen(text) == 0)) {
            compt++;
        }
        temp = temp->next;
    }
    if (compt != 1) {
        return -1;
    }
    return 0;
}

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

int get_name(file_t *file, header_s *header)
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
        if (count_text(file, ".name ") != 0) {
            return NAME_REP_ERROR_STATUS;
        }
        header->prog_name = file->line;
    }
    return 0;
}

int get_comment(file_t *file, header_s *header)
{
    if (file && file->line) {
        if (my_strncmp(file->line, ".comment ", 9) != 0) {
            return COMMENT_ERROR_STATUS;
        }
        if (my_strncmp(file->line, ".comment \"", 10) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
        if (count_quote(file->line) != 0) {
            return SYNTAX_ERROR_STATUS;
        }
        if (count_text(file, ".comment ") != 0) {
            return COMMENT_REP_ERROR_STATUS;
        }
        header->prog_comment = file->line;
    }
    return 0;
}

int compil_header(file_t *file, header_s *header, int size)
{
    file_t *temp = NULL;
    int status = 0;

    if (file && header) {
        temp = file;
        status = get_name(temp, header);
        status = error_handling(status);
        if (status == 84) {
            return 84;
        }
        temp = temp->next;
        status = get_comment(temp, header);
        status = error_handling(status);
        if (status == 84) {
            return 84;
        }
        header->magic = COREWAR_EXEC_MAGIC;
        header->prog_size;
    }
    return status;
}
