#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"


void initializeEnnemy(ENNEMY monstre)
{
    
    monstre.sprite = IMG_Load("walkright.png");
    monstre.pos.x = 300;
    monstre.pos.y = 220;
    monstre.direction=1;
    monstre.limite=20;
    
}

void drawEnnemy(stage s)
{
    /* Rectangle de destination Ã  blitter */
    SDL_Rect dest;
    
    dest.x = monstre.pos.x;
    dest.y = 200;
    dest.w = ENNEMY_WIDTH;
    dest.h = ENNEMY_HEIGHT;
    
    /* Rectangle source Ã  blitter */
    SDL_Rect src;
    
    
    //Pour connaÃ®tre le X de la bonne frame Ã  blitter, il suffit de multiplier
    //la largeur du sprite par le numÃ©ro de la frame Ã  afficher -> 0 = 0; 1 = 40; 2 = 80...
    src.x = monstre.frameNumber * ENNEMY_WIDTH;
    src.y = 0;
    src.w = ENNEMY_WIDTH;
    src.h = ENNEMY_HEIGHT;
    
    /* Blitte notre hÃ©ros sur l'Ã©cran aux coordonnÃ©es x et y */
    
    SDL_BlitSurface(monstre.sprite, &src, s.ecran, &dest);
    
}


void drawanimatedEnnemy(personnage personnage,stage s)
{
    
    /* Gestion du timer */
    
    // Si notre timer (un compte Ã  rebours en fait) arrive Ã  zÃ©ro
    if (abs(monstre.pos.x-personnage.position.x)>30 ) {
        
        if (monstre.frameTimer <= 0)
        {
            //On le rÃ©initialise
            
            monstre.frameTimer = TIME_BETWEEN_2_FRAMES;
            
            //Et on incrÃ©mente notre variable qui compte les frames de 1 pour passer Ã  la suivante
            
            monstre.frameNumber++;
            monstre.pos.x += (monstre.direction) * 15 ;
            
            
            
            
            if (monstre.pos.x < personnage.position.x)
            {
                monstre.direction = 1 ;
                monstre.sprite = IMG_Load("walkright.png");
            }
            
            if (monstre.pos.x  >= personnage.position.x)
            {
                monstre.direction= -1;
                monstre.sprite = IMG_Load("walkleft.png");
            }
            
            //Mais si on dÃ©passe la frame max, il faut revenir Ã  la premiÃ¨re
            //Pour connaÃ®tre la frame max, il suffit de diviser la longueur du spritesheet
            //par la longueur de notre hÃ©ros : 480 / 40 = 12 frames
            //Puisque la premiÃ¨re frame est la numÃ©ro 0, la derniÃ¨re est donc la numÃ©ro 11
            
            if(monstre.frameNumber >= monstre.sprite->w / ENNEMY_WIDTH)
                monstre.frameNumber = 0;
            
        }
        //Sinon, on dÃ©crÃ©mente notre timer
        else
            monstre.frameTimer--;
        
    }
    //Ensuite, on peut passer la main Ã  notre fonction
    drawEnnemy(s);
    
    
}

