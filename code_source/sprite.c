/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void move_rect_left(sfVector2f *rect, int *offset)
{
    int val;

    val = rect->x + offset[0];
    if (val < offset[1])
        rect->x = rect->x + offset[0];
    else
        rect->x = offset[2];
}

void move_rect_top(sfVector2f *rect, int *offset)
{
    int val;

    val = rect->y + offset[0];
    if (val < offset[1])
        rect->y = rect->y + offset[0];
    else
        rect->y = offset[2];
}
