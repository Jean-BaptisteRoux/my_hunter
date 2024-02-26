/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void animation(ImageInfo image)
{
    sfIntRect carre = sfSprite_getTextureRect(image.sprite);

    if (carre.left == image.debut + ((image.slimite - 1) * image.size.x))
        carre.left = image.debut;
    else
        carre.left += carre.width;
    sfSprite_setTextureRect(image.sprite, carre);
}

void debut_suite(parametre_t *p, sfClock *chrono, sfClock *chrono2)
{
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono)) < 6500) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono2)) % 2)
            sfSprite_move(p->liste[6].sprite, (sfVector2f){0, -5});
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono)) > 6300)
            sfSprite_setTextureRect(p->liste[6].sprite,
            (sfIntRect){362, 69, 34, 33});
        disp_sprite(p, 7);
        event(p);
    }
}

void debut(parametre_t *p)
{
    sfClock *chrono = sfClock_create();
    sfClock *chrono2 = sfClock_create();

    while (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono)) < 5000) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono2)) % 2)
            sfSprite_move(p->liste[6].sprite, (sfVector2f){5.3, 0});
        if ((sfTime_asMilliseconds(sfClock_getElapsedTime(chrono2)) / 10) % 2)
            animation(p->liste[6]);
        disp_sprite(p, 7);
        event(p);
    }
    sfSprite_setTextureRect(p->liste[6].sprite, (sfIntRect){259, 58, 56, 51});
    disp_sprite(p, 7);
    sfSleep((sfTime){1000000});
    sfSprite_setTextureRect(p->liste[6].sprite, (sfIntRect){320, 55, 37, 47});
    debut_suite(p, chrono, chrono2);
    p->liste[6].affi = 0;
}

void boucle(parametre_t *p)
{
    sfClock *chrono = sfClock_create();
    sfClock *chrono2 = sfClock_create();

    while (sfRenderWindow_isOpen(p->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono)) > 0.2){
            avancercanard(&(p->liste[5]), 10 + (p->niveau * 10 + p->nmort));
            sfClock_restart(chrono);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono2)) > 40){
            animation(p->liste[5]);
            sfClock_restart(chrono2);
        }
        if (p->balle == 4){
            break;
        }
        event(p);
        disp_sprite(p, 12);
    }
}

void letsbeguinthegame(parametre_t *p)
{
    playmusic("src/Stardew Valley OST Stardew Valley Overture.ogg", 1);
    sfRenderWindow_display(p->window);
    ajuste_fond(p, 12);
    debut(p);
    p->liste[6].affi = 0;
    p->liste[5].affi = 1;
    sfSprite_setScale(p->liste[5].sprite, (sfVector2f) {4, 3 * 0.8});
    initialisercanard(&(p->liste[5]));
    boucle(p);
}
