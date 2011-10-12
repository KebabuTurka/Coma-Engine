#ifndef _OPS_H
#define _OPS_H

#include "SDL/SDL.h" 
#include <string>



;extern SDL_Surface *ekran;


extern void blit( int x, int y, SDL_Surface* source, SDL_Surface* destination) ;


extern SDL_Surface * load_img(std::string filename);

#endif
