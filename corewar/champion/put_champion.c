/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** place champion in the memory
*/

#include "../op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "my.h"

int put_champ(process_t *list_champ, char *arena)
{
    int nb_champ = 0;
    int section_size = MEM_SIZE;
    nb_champ = count_champ(list_champ);
    if (verify_size_champ(list_champ, section_size)) {
        write(2, "champ code size to big for the section\n", 34);
        return -1;
    }
    section_size = (section_size / nb_champ);
    process_t *current = list_champ;
    memcpy(arena, current->code, strlen(current->code));
    current = current->next;
    while (current) {
        memcpy(arena + (current->index * section_size),
        current->code, strlen(current->code));
        current = current->next;
    }
    printf("%s", arena);
    return 0;
}

process_t *add_champ(process_t *liste, char *id, char *code)
{
    process_t *new_champ = malloc(sizeof(process_t));
    if (new_champ == NULL) {
        write(2, "error memory allocation\n", 25);
        return NULL;
    }
    new_champ->id = id;
    new_champ->code = code;
    new_champ->index = 0;
    new_champ->next = NULL;
    if (liste == NULL) {
        return new_champ;
    } else {
        process_t *current = liste;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_champ;
        new_champ->index = current->index + 1;
    }
    return liste;
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

int main(void)
{
    process_t *list_champ = NULL;
    char *arena = malloc(sizeof(char) * (MEM_SIZE + 1));
    int longueur = MEM_SIZE;

    for (int i = 0; i < longueur; i++) {
        arena[i] = '-';
    }
    arena[longueur] = '\0';
    list_champ = add_champ(list_champ, "Champion 1", "Code du champion 1");
    list_champ = add_champ(list_champ, "Champion 2", "Code du champion 2");
    list_champ = add_champ(list_champ, "Champion 3", "Code du champion 3");
    list_champ = add_champ(list_champ, "Champion 4", "Code du champion 4");
    put_champ(list_champ, arena);
    free(arena);
    free_champ(list_champ);
    return 0;
}
