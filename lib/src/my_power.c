/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_power
*/

int my_power(int nb, int power)
{
    if (power == 0) {
        return (1);
    }
    if (power > 1) {
        nb *= my_power(nb, power - 1);
    }
    return (nb);
}
