#ifndef _PLAYER_H
#define _PLAYER_H

#include "SDL/SDL.h" 
#include <string>

class CPlayer
{
      public:
             CPlayer(std::string file,int x,int y,int dir);
             ~CPlayer();
             
             
             void load(std::string file);
             void loadbox(std::string file);
             void draw();
             void unload();
             bool draw_box;
      private:
              SDL_Surface *imag;
              SDL_Surface *ibox;
              SDL_Rect box;
              int x,y,w,h,dir;
              
};

#endif
