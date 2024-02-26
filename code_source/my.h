/*
** EPITECH PROJECT, 2023
** osef
** File description:
** osef
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#ifndef MY_H_
    #define MY_H_
typedef struct {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f size;
    int debut;
    int slimite;
    int affi;
    float angle;
} ImageInfo;

typedef struct parametre {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    ImageInfo *liste;
    sfIntRect *vchiffre;
    sfMusic *music;
    sfTexture *texture;
    int taille_fond[2];
    int black;
    int mort;
    int nmort;
    int niveau;
    int score;
    int balle;
} parametre_t;

parametre_t *initialisation_windows(void);
void drawblacksquare(sfRenderWindow* window, float x, float y, int size);
int intl(int i);
void mort_canard(parametre_t *p);
void animation(ImageInfo image);
void initialisercanard(ImageInfo *canard);
void avancercanard(ImageInfo *canard, float vitesse);
void move_rect_left(sfVector2f *rect, int *offset);
void move_rect_top(sfVector2f *rect, int *offset);
void pstr(char const *str);
int strl(char const *str);
void letsbeguinthegame(parametre_t *p);
void event(parametre_t *p);
void playmusic( char *chemin, int x);
void ajuste_fond(parametre_t *p, int i);
void disp_sprite(parametre_t *p, int i);
#endif /* MY_H_ */
