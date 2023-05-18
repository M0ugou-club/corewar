/*
** EPITECH PROJECT, 2023
** asm
** File description:
** error.h
*/
#ifndef ERROR_H_
    #define ERROR_H_

    #define SYNTAX_ERROR "Syntax Error."
    #define SYNTAX_ERROR_STATUS -1

    #define INSTRUCTION_ERROR "Invalid instruction."
    #define INSTRUCTION_ERROR_STATUS -2

    #define NAME_REP_ERROR "The name can only be defined once."
    #define NAME_REP_ERROR_STATUS -3

    #define COMMENT_REP_ERROR "The comment can only be defined once."
    #define COMMENT_REP_ERROR_STATUS -4

    #define COMMENT_ERROR "The comment must be just after the name."
    #define COMMENT_ERROR_STATUS -5

    #define NAME_FIRST_LINE_ERROR "The name of your programe must be the fist line."
    #define NAME_FIRST_LINE_ERROR_STATUS -6

    #define NO_NAME_ERROR "No name specified."
    #define NO_NAME_ERROR_STATUS -7

    #define NO_COMMENT_ERROR "No comment specified."
    #define NO_COMMENT_ERROR_STATUS -8

    #define INVALID_ARGUMENT "The argument given to the instruction is invalid."
    #define INVALID_ARGUMENT_STATUS -9

    int error_handling(int status);
#endif /*ERROR_H_*/