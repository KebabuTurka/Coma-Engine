#include "SDL/SDL.h" 

#ifndef _PLAYER_H
#include "player.h"
#endif

#ifndef _MAP_H
#include "map.h"
#endif

#ifndef _OPS_H
#include "ops.h"
#endif

#ifndef _EVENTS_H
#include "events.h"
#endif

#ifndef _PLAYER_H
#include "player.h"
#endif

#ifndef _VEC_H
#include "SimpVec.h"
#endif

#ifndef _TREE_H
#include "tree.h"
#endif

#ifndef _TIMER_H
#include "timer.h"
#endif

#include <string>



extern "C" int main(int argc, char** argv)  { 
    
    SDL_Init( SDL_INIT_EVERYTHING );                                            //Inicjacja SDL
    ekran = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE);                     //Ustawienie sterownika okna SDL
    CMap *world = new CMap("data/mapa.japierdole");                             //Konstruktor œwiata
    CPlayer *player = new CPlayer( "data/grog.japierdole",150,150,1);           //Konstruktor gracza
    CEvents *events = new CEvents;                                              //Konstruktor pêtli
    
    player->draw();                                                             //rysowanie gracza
    world->draw();                                                              //rysowanie œwiata
    SDL_Flip( ekran );                                                          //"przerzucenie" ekranu - podwójny bufor
    events->loop();                                                             //pêtla
	
	delete world;                                                               //Destruktor œwiata
	delete player;                                                              //destruktor gracza
	delete events;                                                              //destruktor pêtli
    SDL_Quit();                                                                 //wy³¹cza SDL
    
    return 0;
}




