
#ifndef monster_h
#define monster_h
#define ENNEMY_WIDTH 80
#define ENNEMY_HEIGHT 80
#define TIME_BETWEEN_2_FRAMES 6
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct ENNEMY
{
    
    SDL_Surface *sprite;
    SDL_Rect pos;
    int frameNumber, frameTimer;
    int direction ;
    int limite;
    
} ENNEMY;
void initializeEnnemy();
void drawEnnemy(stage s);
void drawanimatedEnnemy(personnage personnage,stage s);
ENNEMY monstre;



#endif /* monster_h */
