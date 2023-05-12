/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_atoi
*/

#include <stddef.h>

static int check_sign(const char *str, int *index, int *sign)
{
    if (str[0] == '-') {
        *index += 1;
        *sign = -1;
    } else if (str[0] == '+') {
        *index += 1;
        *sign = 1;
    }
    return 0;
}

int my_atoi(const char *str)
{
    int res = 0;
    int index = 0;
    int sign = 0;

    if (str == NULL) {
        return -1;
    }
    check_sign(str, &index, &sign);
    while (str[index] != '\0') {
        if (str[index] <= '0' || str[index] >= '9') {
            return -1;
        } else {
            res = res * 10 + str[index] - '0';
            index++;
        }
    }
    if (sign == -1) {
        res = res * -1;
    }
    return res;
}
