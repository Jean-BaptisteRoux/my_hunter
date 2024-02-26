/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void playmusic(char *chemin, int x)
{
    sfMusic *music = sfMusic_createFromFile(chemin);
    if (x == 1)
        sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfMusic_setVolume(music, 20);
}

void ajuste_fond(parametre_t *p, int j)
{
    sfVector2u windowSize = sfRenderWindow_getSize(p->window);
    sfVector2f scale = {
        (float)windowSize.x / 256,
        (float)windowSize.y / 240
    };

    for (int i = 0; i < j; i++){
        sfSprite_setTexture(p->liste[i].sprite, p->texture, NULL);
        sfSprite_setPosition(p->liste[i].sprite, p->liste[i].position);
        sfSprite_setScale(p->liste[i].sprite, scale);
    }
}

int *inttolist(int number)
{
    int *result = malloc(6 * sizeof(int));
    int len = intl(number);

    for (int i = 0; i < 6 - len; i++)
        result[i] = 0;
    for (int i = 0; i < 6; i++) {
        result[5 - i] = number % 10;
        number /= 10;
    }
    return result;
}

void score(parametre_t *p)
{
    sfSprite* sprite = sfSprite_create();
    sfVector2f scale = {
        (float)sfRenderWindow_getSize(p->window).x / 256,
        (float)sfRenderWindow_getSize(p->window).y / 240
    };
    int *score = inttolist(p->score);

    for (int i = 0; i < 6; i++){
        sfSprite_setTexture(sprite, p->texture, NULL);
        sfSprite_setTextureRect(sprite, p->vchiffre[score[i] + 10]);
        sfSprite_setPosition(sprite, (sfVector2f)
        {(192 + (8 * i)) * 1280 / 256, 206 * 720 / 240});
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_drawSprite(p->window, sprite, NULL);
    }
}

void disp_sprite(parametre_t *p, int j)
{
    sfSprite* sprite = sfSprite_create();
    sfVector2f scale = {(float)sfRenderWindow_getSize(p->window).x / 256,
        (float)sfRenderWindow_getSize(p->window).y / 240
    };

    for (int i = 0; i < j && p->black == 0; i++)
        if (p->liste[i].affi == 1)
            sfRenderWindow_drawSprite(p->window, p->liste[i].sprite, NULL);
    sfSprite_setTexture(sprite, p->texture, NULL);
    sfSprite_setTextureRect(sprite, p->vchiffre[p->niveau]);
    sfSprite_setPosition(sprite, (sfVector2f)
    {39 * 1280 / 256, 191 * 720 / 240});
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(p->window, sprite, NULL);
    score(p);
    drawblacksquare(p->window, 8 * (1280 / 256), 8 * (720 / 240), p->balle);
    if (p->black == 1)
        sfRenderWindow_clear(p->window, sfBlack);
    sfRenderWindow_display(p->window);
}
