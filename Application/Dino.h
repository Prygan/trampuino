#ifndef DINO_H
#define DINO_H

#include "Obstacle.h"
#include "U8glib/U8glib.h"

class Dino {
 private :

  int x, y, width, height ;
  
  bool isJumping2, isFalling2 ;

  int getX(void);

  int getY(void);

  int getWidth(void) ;

  int getHeight(void) ;

 public :

  Dino(int x, int y, int height, int width);

  //test if we are on the floor
  bool onFloor(int Yfloor);

  //test if we are on the max of the jump
  bool onTop(int Ytop);

  bool isJumping(void);

  bool isFalling(void);

  void startJump(void);

  void startFall(void);

  void startIdle(void);


  //move up until onTop
  void jump(int speed);

  //move down until on Floor
  void fall(int speed);

  //draw Dino
  void draw(U8GLIB_NHD_C12864* u8g);

  //isTouching
  bool isTouching(Obstacle o);

};

#endif
