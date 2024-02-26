/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void taille(parametre_t *p)
{
    sfVector2u tailleActuelle = sfRenderWindow_getSize(p->window);
    sfVector2u tailleMin = {800, 600};
    sfVector2u tailleMax = {1920, 1080};

    if (tailleActuelle.x < tailleMin.x || tailleActuelle.y < tailleMin.y) {
        sfRenderWindow_setSize(p->window, tailleMin);
    } else if (tailleActuelle.x > tailleMax.x ||
        tailleActuelle.y > tailleMax.y) {
        sfRenderWindow_setSize(p->window, tailleMax);
    }
}

void tir(parametre_t *p)
{
    sfFloatRect taille_sprite = sfSprite_getGlobalBounds(p->liste[5].sprite);
    sfIntRect taille = sfSprite_getTextureRect(p->liste[11].sprite);
    // sfMusic *music = malloc(sizeof(sfMusic));

    if (p->event.mouseButton.x > taille_sprite.left &&
        p->event.mouseButton.x < taille_sprite.left + taille_sprite.width &&
        p->event.mouseButton.y > taille_sprite.top &&
        p->event.mouseButton.y < taille_sprite.top + taille_sprite.height){
        p->nmort++;
        playmusic("src/bruh.wav", 0);
        taille.width += 8;
        sfSprite_setTextureRect(p->liste[11].sprite, taille);
        p->score += 500;
        mort_canard(p);
        p->balle = 0;
        if (p->nmort == 10){
            taille.width = 0;
            sfSprite_setTextureRect(p->liste[11].sprite, taille);
            p->niveau++;
            p->nmort = 0;
            p->score += 1000;
        }
    }
}

void drawblacksquare(sfRenderWindow *window, float x, float y, int size)
{
    sfRectangleShape *square = sfRectangleShape_create();

    if (size == 4)
        size = 3;
    if (size != 0){
        sfRectangleShape_setSize(square, (sfVector2f){x * size, y});
        sfRectangleShape_setFillColor(square, sfBlack);
        sfRectangleShape_setPosition(square, (sfVector2f)
        {22 * (1280 / 256), 207 * (720 / 240)});
        sfRenderWindow_drawRectangleShape(window, square, NULL);
        sfRectangleShape_destroy(square);
    }
}

void event(parametre_t *p)
{
    // sfMusic *music = malloc(sizeof(sfMusic));

    while (sfRenderWindow_pollEvent(p->window, &(p->event))) {
        switch (p->event.type){
            case sfEvtClosed:
                sfRenderWindow_close(p->window);
            case sfEvtResized:
                taille(p);
            case sfEvtMouseButtonPressed:
                playmusic("src/shot.wav", 0);
                p->balle++;
                tir(p);
            default:
                continue;
        }
    }
}
