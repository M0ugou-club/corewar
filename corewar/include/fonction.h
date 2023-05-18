/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fonction.h
*/
#ifndef FONCTION_H_
	#define FONCTION_H_

typedef struct function_s {
    char id;
    int (*action) (int index, char *memmory, process_t *process);
} function_t;

#endif /*FONCTION_H_*/