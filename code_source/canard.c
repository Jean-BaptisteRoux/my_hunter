/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** test
** test
*/
#include "my.h"

float genererangle(void)
{
    float random = (float)rand() / RAND_MAX;

    if (random < 0.5f) {
        return 20.0f + random * 50.0f;
    } else {
        return 110.0f + (random - 0.5f) * 40.0f;
    }
}

void initialisercanard(ImageInfo* canard)
{
    sfVector2f tmp = sfSprite_getScale(canard->sprite);

    canard->position.x = (((float)(rand() % 140) + 70) * 720 / 240);
    canard->position.y = (135 * 720 / 240);
    sfSprite_setPosition(canard->sprite, canard->position);
    canard->angle = genererangle() * -1;
    if (canard->angle < -109){
        if (tmp.x > 0)
            sfSprite_setScale(canard->sprite,
            (sfVector2f){tmp.x * -1, tmp.y});
    }else{
        if (tmp.x < 0)
            sfSprite_setScale(canard->sprite,
            (sfVector2f) {tmp.x * -1, tmp.y});
    }
}

void avancercanard(ImageInfo *canard, float vitesse)
{
    float dx = vitesse * cos(canard->angle * (M_PI / 180.0));
    float dy = vitesse * sin(canard->angle * (M_PI / 180.0));

    canard->position.x += dx;
    canard->position.y += dy;
    if (canard->position.x > 1280 || canard->position.y > 780
        || canard->position.x < -50)
        initialisercanard(canard);
    sfSprite_setPosition(canard->sprite, canard->position);
}

void mort_canard_suite(parametre_t *p)
{
    sfClock *chrono2 = sfClock_create();

    while (sfSprite_getPosition(p->liste[8].sprite).y < 380) {
        p->liste[8].affi = 1;
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(chrono2)) > 1){
            sfSprite_move(p->liste[8].sprite, (sfVector2f){0, 4});
            sfClock_restart(chrono2);
        }
        disp_sprite(p, 12);
        event(p);
    }
    p->liste[8].affi = 0;
    p->liste[10].affi = 1;
    sfSprite_setPosition(p->liste[10].sprite, (sfVector2f)
    {sfSprite_getPosition(p->liste[5].sprite).x, 112 * (720 / 240)});
    disp_sprite(p, 12);
    sfSleep((sfTime){500000});
    p->liste[10].affi = 0;
    p->liste[5].affi = 1;
    initialisercanard(&(p->liste[5]));
}

void mort_canard(parametre_t *p)
{
    sfFloatRect taille_sprite = sfSprite_getGlobalBounds(p->liste[5].sprite);

    sfSprite_setPosition(p->liste[7].sprite,
    sfSprite_getPosition(p->liste[5].sprite));
    sfSprite_setPosition(p->liste[9].sprite,
    sfSprite_getPosition(p->liste[5].sprite));
    sfSprite_move(p->liste[9].sprite, (sfVector2f){10, -7});
    p->liste[5].affi = 0;
    p->liste[7].affi = 1;
    p->liste[9].affi = 1;
    disp_sprite(p, 12);
    sfSleep((sfTime){500000});
    p->liste[8].affi = 1;
    p->liste[9].affi = 0;
    p->liste[7].affi = 0;
    sfSprite_setPosition(p->liste[8].sprite,
    sfSprite_getPosition(p->liste[5].sprite));
    mort_canard_suite(p);
}
