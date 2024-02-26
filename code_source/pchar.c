/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Permet d'afficher un caractère
*/
#include "my.h"

void pchar(char c)
{
    write(1, &c, 1);
}
