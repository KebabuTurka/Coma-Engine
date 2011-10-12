#include "SDL/SDL.h" 
#include <string>
#ifndef _EVENTS_H
#include "events.h"
#endif

#ifndef _PLAYER_H
#include "player.h"
#endif


CEvents::CEvents()
{
                  quit = false;
                  debug = false;
                  
}

CEvents::~CEvents(){}

int CEvents::loop(){
while (quit == false) 
      {
      while (SDL_PollEvent(&event)) 
            {
            if (event.type == SDL_QUIT) 
               {
                           quit = true;
               }
            }
            Uint8 *keystates = SDL_GetKeyState( NULL );
            if ( keystates[SDLK_ESCAPE])
               {
                 quit = true;
               }
            if ( keystates[SDLK_p])
               {
                 debug = true;
                 //CPlayer->draw_box = true;
               }
            if ( SDL_Flip(ekran) == -1) 
               {
                 return 0;
               }
      }
}
