/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/


#include "my.h"

void descriptor(void)
{
    pstr("\n");
    pstr("************************\n");
    pstr("*****MY-HUNTER-GAME*****\n");
    pstr("************************\n");
    pstr("Shot more possible ducks\n");
    pstr("thanks to your cursor!\n");
    pstr("Have a good game!\n");
    pstr("\n");
}

int probleme(parametre_t *paramètres)
{
    if (!paramètres->window || !paramètres->liste)
        return 84;
    return 0;
}

void liberation_memoire(parametre_t *paramètres)
{
    write(1, "Bravo ! Tu as fait ", 19);
    pnbr(paramètres->nmort + (paramètres->niveau * 10));
    write(1, "\n", 1);
    free(paramètres->liste);
    free(paramètres->vchiffre);
    sfRenderWindow_destroy(paramètres->window);
    sfMusic_destroy(paramètres->music);
    sfTexture_destroy(paramètres->texture);
    free(paramètres);
}

int intl(int i)
{
    int a;

    if (i == 0)
        return 0;
    for (a = 0 ; i != 0 ; a++)
        i = i / 10;
    return (a);
}

int main(int ac, char **argv)
{
    parametre_t *paramètres = initialisation_windows();

    if (ac == 2 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
        descriptor();
        return 0;
    }
    if (probleme(paramètres) == 84)
        return 84;
    letsbeguinthegame(paramètres);
    liberation_memoire(paramètres);
    return 0;
}
