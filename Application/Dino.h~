#ifndef DINO_H
#define DINO_H

#include "Obstacle.h"

class Dino {
private :

   int x, y, width, height ;
  
   bool isJumping, isFalling ;

   int getX(void);

   int getY(void);

   int getWidth(void) ;

   int getHeight(void) ;

public :

   Dino(int x, y, height, width);

   //test if we are on the floor
   bool onFloor(int Yfloor);

   //test if we are on the max of the jump
   bool onTop(void);

bool isJumping(void);

bool isFalling(void);

void startJump(void);

void startFall(void);

void startIdle(void);


   //move up until onTop
   void jump(void);

   //move down until on Floor
   void fall(void);

   //draw Dino
   void draw(void);

   //isTouching
   bool isTouching(Obstacle o);

}

#endif