#ifndef _OBJECT_H
#define _OBJECT_H

#include "SDL/SDL.h"
#include "SimpVec.h"
#include "tree.h"
#include "timer.h"

class CObject : public CNode {
      
      protected:
                virtual void OnAnimate(Uint32 time)
                {
                        position += velocity * time;
                        velocity += acceleration * time;
                }
                
                
                
      }
                
#endif
