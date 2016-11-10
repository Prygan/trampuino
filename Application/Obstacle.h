#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "U8glib/U8glib.h"

class Obstacle {
private :

   int x, y, length ;

public :

   Obstacle(int x, int y, int length);

   void deplace(int speed);

   //draw Obstacle
   void draw(U8GLIB_NHD_C12864* u8g);

   int getX(void);

   int getY(void);

   int getLength(void);

   void reset(int maxY, int resetPosY);

};

#endif
