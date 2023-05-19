/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "process.h"
#include "vm.h"

int count_champ(process_t *list_champ)
{
    int nb_champ = 0;
    process_t *current = list_champ;

    while (current) {
        nb_champ += 1;
        current = current->next;
    }
    return nb_champ;
}

int verify_size_champ(process_t *list_champ, int section_size)
{
    process_t *current = list_champ;
    int size_of_code = 0;
    while (current) {
        size_of_code = strlen(current->code);
        if (size_of_code > section_size) {
            return -1;
        }
        current = current->next;
    }
    return 0;
}

void print_champ(process_t *liste)
{
    process_t *current = liste;
    while (current != NULL) {
        printf("ID: %s\n", current->id);
        printf("Code: %s\n", current->code);
        printf("\n");
        current = current->next;
    }
}

void free_champ(process_t *list_champ)
{
    process_t *current = list_champ;
    process_t *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int put_champ_in_arena(char *arena, int index, char *code)
{
    for (int i = 0; code[i] != '\0' ;i++) {
        // if (get_mem_value(arena, index + 1) == 0) {
        //     printf("ca ecrase \n");
        //     return -1;
        // }
        modif_mem(arena, index + i, code[i]);
    }
}

char *put_champ(process_t *list_champ, vm_t *vm)
{
    int nb_champ = 0;
    int section_size = MEM_SIZE;
    int index = 0;
    nb_champ = count_champ(list_champ);
    section_size = (section_size / nb_champ);
    process_t *current = list_champ;
    while (current) {
        if (current->index == -1) {
            put_champ_in_arena(vm->memory, index, current->code);
            current->index = index;
        } else {
            put_champ_in_arena(vm->memory, current->index, current->code);
        }
        index += MEM_SIZE / vm->nb_champ;
        current = current->next;
    }
    write(1, vm->memory, MEM_SIZE);
    return NULL;
}

process_t *add_champ(process_t *liste, char *id, char *code, int index)
{
    process_t *new_champ = malloc(sizeof(process_t));
    if (new_champ == NULL) {
        write(2, "error memory allocation\n", 25);
        return NULL;
    }
    new_champ->id = id;
    new_champ->code = code;
    new_champ->index = index;
    new_champ->next = NULL;
    if (liste == NULL) {
        return new_champ;
    } else {
        process_t *current = liste;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_champ;
    }
    return liste;
}

int main(void)
{
    process_t *list_champ = NULL;
    vm_t vm = {0};
    char *arena = malloc(sizeof(char) * (MEM_SIZE + 1));
     int longueur = MEM_SIZE;
     for (int i = 0; i < longueur; i++) {
         arena[i] = '\0';
     }
    arena[longueur] = '\0';
    list_champ = add_champ(list_champ, "Champion 1", "Code du champion 1", -1);
    list_champ = add_champ(list_champ, "Champion 2", "Code du champion 2", -1);
    list_champ = add_champ(list_champ, "Champion 3", "Code du champion 3", -1);
    list_champ = add_champ(list_champ, "Champion 4", "Code du champion 4", -1);
    vm.memory = arena;
    vm.nb_champ = count_champ(list_champ);
    put_champ(list_champ, &vm);
    free(arena);
    free_champ(list_champ);
    return 0;
}
