#include "Dino.h"
#include "Obstacle.h"

Dino::Dino(int x, y, height, width){
   this.x = x ;
   this.y = y ;
   this.height = height ;
   this.width = width ;
}

//test if we are on the floor
bool Dino::onFloor(int Yfloor){
   return this.getY()+this.height >= Yfloor ;
}

//test if we are on the max of the jump
bool Dino::onTop(int Ytop){
   return this.getY() <= Ytop ;
}

//move up until onTop
void Dino::jump(void){
   this.x = this.x - 1 ;
}

//move down until on Floor
void Dino::fall(void){
   this.y = this.y + 1 ;
}

//draw Dino
void Dino::draw(void){
   //todo
}

bool Dino::isTouching(Obstacle o){
   return o.getX()                 > this.getX()                   &&
          o.getX() + o.getLength() < this.getX() + this.getWidth() &&
          o.getY()                 > this.getY()                   &&
          o.getY() + o.getLength() < this.getY() + this.getHeight() ;
}


bool Dino::isJumping(void){
   return isJumping ;
}

bool Dino::isFalling(void){
   return isFalling ;
}

void Dino::startJump(void){
   isJumping = true ;
}

void Dino::startFall(void){
   isFalling = true ;
}

void Dino::startIdle(void){
   isJumping = false ;
   isFalling = false ;
}

int Dino::getX(void){
   return this.x ;
}

int Dino::getY(void){
   return this.y ;
}

int Dino::getWidth(void){
   return this.width ;
}

int Dino::getHeight(void){
   return this.height ;
}