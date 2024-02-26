/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

sfVideoMode mode = {1280, 720, 32};
sfIntRect vchiffre_init[] = {
    {389, 241, 397, 249}, {397, 241, 404, 249},
    {404, 241, 412, 249}, {412, 241, 420, 249},
    {420, 241, 428, 249}, {428, 241, 236, 249},
    {389, 249, 397, 257}, {397, 249, 405, 257},
    {405, 249, 413, 257}, {413, 249, 421, 257},
    {389, 257, 397, 265}, {397, 257, 404, 265},
    {404, 257, 412, 265}, {412, 257, 420, 265},
    {420, 257, 428, 265}, {428, 257, 436, 265},
    {389, 265, 397, 273}, {397, 265, 405, 273},
    {405, 265, 413, 273}, {413, 265, 421, 273}};

ImageInfo *ajouterimagealiste(ImageInfo *listeImages,
    sfIntRect coordFichier, int *coordSprite, int tailleListe)
{
    sfSprite* sprite = sfSprite_create();
    sfVector2f position = {coordSprite[0], coordSprite[1]};
    sfVector2f size;
    ImageInfo imageInfo;
    ImageInfo* nouvelleListe = malloc((tailleListe + 1) * sizeof(ImageInfo));

    coordFichier.width -= coordFichier.left;
    coordFichier.height -= coordFichier.top;
    sfSprite_setTextureRect(sprite, coordFichier);
    size = (sfVector2f){coordFichier.width, coordFichier.height};
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f){size.x / 574, size.y / 282});
    imageInfo = (ImageInfo){sprite, position, size, 0, 0, 1, 0};
    for (int i = 0; i < tailleListe; i++)
        nouvelleListe[i] = listeImages[i];
    nouvelleListe[tailleListe] = imageInfo;
    free(listeImages);
    return nouvelleListe;
}

ImageInfo *chargement(void)
{
    ImageInfo *liste = malloc(sizeof(ImageInfo));
    double coeff_x = 1280 / 256;
    double coeff_y = 720 / 240;

    liste = ajouterimagealiste(liste, (sfIntRect){0, 0, 256, 240},
    (int [2]){0, 0}, 0);
    liste = ajouterimagealiste(liste, (sfIntRect){12, 247, 27, 255},
    (int [2]){24 * coeff_x, 192 * coeff_y}, 1);
    liste = ajouterimagealiste(liste, (sfIntRect){56, 244, 82, 261},
    (int [2]){22 * coeff_x, 207 * coeff_y}, 2);
    liste = ajouterimagealiste(liste, (sfIntRect){84, 244, 196, 261},
    (int [2]){63 * coeff_x, 207 * coeff_y}, 3);
    liste = ajouterimagealiste(liste, (sfIntRect){207, 253, 255, 261},
    (int [2]){191 * coeff_x, 216 * coeff_y}, 4);
    liste = ajouterimagealiste(liste, (sfIntRect){264, 114, 296, 147},
    (int [2]){(256 / 2) * coeff_x, (240 / 2) * coeff_y}, 5);
    liste = ajouterimagealiste(liste, (sfIntRect){259, 4, 315, 46},
    (int [2]){0, 147 * coeff_y}, 6);
    return liste;
}

ImageInfo *limite(ImageInfo *liste)
{
    liste = ajouterimagealiste(liste, (sfIntRect){483, 124, 515, 155},
    (int [2]){0, 0}, 7);
    liste = ajouterimagealiste(liste, (sfIntRect){524, 122, 543, 154},
    (int [2]){50, 50}, 8);
    liste = ajouterimagealiste(liste, (sfIntRect){553, 34, 567, 41},
    (int [2]){0, 0}, 9);
    liste = ajouterimagealiste(liste, (sfIntRect){409, 64, 453, 104},
    (int [2]){0, 0}, 10);
    liste = ajouterimagealiste(liste, (sfIntRect){116, 264, 116, 272},
    (int [2]){95 * 1280 / 256, 208 * 720 / 240}, 11);
    liste[10].affi = 0;
    liste[9].affi = 0;
    liste[8].affi = 0;
    liste[7].affi = 0;
    liste[6].slimite = 5;
    liste[6].debut = sfSprite_getTextureRect(liste[6].sprite).left;
    liste[5].slimite = 3;
    liste[5].debut = sfSprite_getTextureRect(liste[5].sprite).left;
    return liste;
}

parametre_t *initialisation_windows(void)
{
    parametre_t *paramètres = malloc(sizeof(parametre_t));

    paramètres->mode = mode;
    paramètres->liste = chargement();
    paramètres->liste = limite(paramètres->liste);
    paramètres->vchiffre = malloc(sizeof(sfIntRect) * 20);
    for (int i = 0; i < 20; i++){
        vchiffre_init[i].width -= vchiffre_init[i].left;
        vchiffre_init[i].height -= vchiffre_init[i].top;
        paramètres->vchiffre[i] = vchiffre_init[i];
    }
    paramètres->texture = sfTexture_createFromFile("src/sprite.png", NULL);
    paramètres->window = sfRenderWindow_create(paramètres->mode,
    "My_hunter", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(paramètres->window, 32);
    paramètres->black = 0;
    paramètres->liste[5].affi = 0;
    paramètres->balle = -1;
    return paramètres;
}
