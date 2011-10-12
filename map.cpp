#include "SDL/SDL.h" 
#include <string>
#include "map.h"

#ifndef _OPS_H
#include "ops.h"
#endif

CMap::CMap(std::string file)
{
            img = NULL;
            load(file);
}

CMap::~CMap()
{
             SDL_FreeSurface(img);
}

void CMap::draw(){
               blit(0,0,img,ekran);
               }
               
void CMap::load(std::string file){
               img = load_img(file);
               }
               
void CMap::unload(){
               SDL_FreeSurface(img);
               } 
               
               
