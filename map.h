#ifndef _MAP_H
#define _MAP_H

#include "SDL/SDL.h" 
#include <string>

class CMap{
      public:
           CMap(std::string file);
           ~CMap();
          void draw();
          void load(std::string file);
          void unload();
          SDL_Rect boxes[255];
      private:
          SDL_Surface * img;
          }
#endif
              
