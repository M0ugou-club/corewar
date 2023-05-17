/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** print_error.c
*/

#include "my.h"
#include "error.h"

static int other_error(const int status)
{
    if (status == COMMENT_ERROR_STATUS) {
        my_putstr(COMMENT_ERROR);
        return 84;
    }
    if (status == NAME_FIRST_LINE_ERROR_STATUS) {
        my_putstr(NAME_FIRST_LINE_ERROR);
        return 84;
    }
    if (status == NO_NAME_ERROR_STATUS) {
        my_putstr(NO_NAME_ERROR);
        return 84;
    }
    if (status == NO_COMMENT_ERROR_STATUS) {
        my_putstr(NO_COMMENT_ERROR);
        return 84;
    }
    if (status == INVALID_ARGUMENT_STATUS) {
        my_putstr(INVALID_ARGUMENT);
    }
    return 0;
}

int error_handling(const int status)
{
    if (status == SYNTAX_ERROR_STATUS) {
        my_putstr(SYNTAX_ERROR);
        return 84;
    }
    if (status == INSTRUCTION_ERROR_STATUS) {
        my_putstr(INSTRUCTION_ERROR);
        return 84;
    }
    if (status == NAME_REP_ERROR_STATUS) {
        my_putstr(NAME_REP_ERROR);
        return 84;
    }
    if (status == COMMENT_REP_ERROR_STATUS) {
        my_putstr(COMMENT_REP_ERROR);
        return 84;
    }
    if (other_error(status) == 84) {
        return 84;
    }
    return 0;
}
