#include "SDL/SDL.h" 
#include <string>
#include "ops.h"

SDL_Surface *ekran = NULL;

void blit( int x, int y, SDL_Surface* source, SDL_Surface* destination) 
{ 
     //Holds offsets 
     SDL_Rect offset; 
     
     //Get offsets 
     offset.x = x; 
     offset.y = y; 
     
     //Blit 
     SDL_BlitSurface( source, NULL, destination, &offset ); 
     }


SDL_Surface * load_img(std::string filename)
{
            SDL_Surface* loaded = NULL;
            SDL_Surface* optimized = NULL;
            
            loaded = SDL_LoadBMP(filename.c_str());
            
            if(loaded != NULL)
            {
                      optimized = SDL_DisplayFormat(loaded);
                      SDL_FreeSurface(loaded);
                      
                      if(optimized != NULL)
                      {
                                   Uint32 colorkey = SDL_MapRGB(optimized->format,0xFF,0,0xFF);
                                   SDL_SetColorKey( optimized, SDL_SRCCOLORKEY, colorkey );
                      }
                      return optimized;
            }
}
