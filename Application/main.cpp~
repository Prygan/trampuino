#include "Dino.h"
#include "Obstacle.h"


#define FLOOR 62
#define DINO_WIDTH 10
#define DINO_HEIGHT 20
#define DINO_X 10
#define DINO_HEIGHT_JUMP 15
#define OBSTACLE_LENGTH 5
#define WIDTH 127
#define HEIGHT 63 
#define SPEED 1 



   /*
   0                               128
 0 +--------------------------------- 
   |
   |
   |
   |
   |    1--+
   |    |  |      +--+
   |    +--+      +--+
64 |0--------------------------------9

   1x = 
   1y =
   0x = 
   0y = 
   9x =
   9y = 

   */

int main() {

   //initialisation
   Dino dino = new Dino(DINO_X, FLOOR-DINO_HEIGHT, DINO_HEIGHT,DINO_WIDTH)

   Obstacle o = new Obstacle(WIDTH-OBSTACLE_LENGTH, FLOOR-OBSTACLE_LENGTH, OBSTACLE_LENGTH);
   
   dino.startIdle();

   //process
   while(true){
      if(dino.onFloor(FLOOR) && buttonDown()){ //pressbutton
         dino.startIdle();
         dino.startJump();
      }

      if(dino.isJumping())
         dino.jump() ;

      if(dino.onTop(DINO_HEIGHT_JUMP)){
         dino.startIdle();
         dino.startFall();
      }

      if(dino.isFalling())
         dino.fall();

      if(dino.onFloor(FLOOR)){
         dino.startIdle();
      }

      //move
      o.deplace(SPEED);

      //draw 
      dino.draw()
      o.draw() ; 

      if(dino.isTouching(o))
         return 0 ; //game over

   }
   return 0 ;
}

bool buttonDown(){
   return false ; //TODO
}