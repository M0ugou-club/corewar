/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write_final_state
*/

#include "vm.h"
#include "op.h"

static int write_hexa_line(int line)
{
    char to_print = 0;

    to_print = line % 16;
    if (to_print > 9) {
        to_print += '0';
    } else {
        to_print += 'A';
    }
    if (line > 16) {
        write_hexa_line(line / 16);
    }
    write(1, &to_print, 1);
    return (0);
}

static int write_hexa_mem(int nb, int index)
{
    char to_print = 0;

    to_print = nb % 16;
    if (to_print > 9) {
        to_print += '0';
    } else {
        to_print += 'A';
    }
    if (index == 0) {
        return (0);
    } else {
        write_hexa_mem(nb / 16, index - 1);
    }
    write(1, &to_print, 1);
    return (0);
}

static int write_mem(char *memory, int line)
{
    int index_line = 32;
    int i = line;

    while (i < MEM_SIZE && index_line != 0) {
        write(1, " ", 1);
        write_hexa_mem(memory[i], 2);
        i++;
        index_line--;
    }
    write(1, "\n", 1);
    return (0);
}

int print_final_state(vm_t *vm)
{
    int line = 0;

    if (vm->f_dump == 0) {
        while (line < MEM_SIZE) {
            write_hexa_line(line);
            write(1, "\t:", my_strlen("\t:"));
            write_mem(vm->memory, line);
            line += 32;
        }
    }
    return (0);
}
