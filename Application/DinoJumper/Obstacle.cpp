#include "Obstacle.h"



Obstacle::Obstacle(int x, y, length){
   this.x = x ;
   this.y = y ;
   this.length = length ;
}

void Obstacle::deplace(int speed){
   this.y = this.y - speed ;
}

//draw Obstacle
void Obstacle::draw(void){
   //todo
}

int Obstacle::getX(void){
   return this.x ;
}

int Obstacle::getY(void){
   return this.y ;
}

int Obstacle::getLength(void){
   return this.length ;
}
