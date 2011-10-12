#ifndef _EVENTS_H
#define _EVENTS_H

#include "SDL/SDL.h" 
#ifndef _OPS_H
#include "ops.h"
#endif


class CEvents {
      public:
             CEvents();
             ~CEvents();
             SDL_Event event;
             
             int loop();
      private:
              bool quit;
              bool debug;
};

#endif
