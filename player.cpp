#include "SDL/SDL.h" 
#include <string>
#ifndef _OPS_H
#include "ops.h"
#endif
#include "player.h"

CPlayer::CPlayer(std::string file,int x,int y,int dir)
{
     load(file);
     this->x = x;
     this->y = y;
     this->dir = dir;
     this->w = imag->w;
     this->h = imag->h;
     draw_box = false;
}

CPlayer::~CPlayer()
{
    unload();
}

void CPlayer::load(std::string file)
{
     imag = load_img(file);
}

void CPlayer::loadbox(std::string file)
{
     ibox = load_img("data/box.japierdole");
}

void CPlayer::draw()
{
     blit(x,y,imag,ekran);
}
void CPlayer::unload()
{
     SDL_FreeSurface(imag);
}

