#include "Dino.h"
#include "Obstacle.h"

Dino::Dino(int x, int y, int height, int width){
   this->x = x ;
   this->y = y ;
   this->height = height ;
   this->width = width ;
}

//test if we are on the floor
bool Dino::onFloor(int Yfloor){
   return this->getY()+this->height >= Yfloor ;
}

//test if we are on the max of the jump
bool Dino::onTop(int Ytop){
   return this->getY() <= Ytop ;
}

//move up until onTop
void Dino::jump(int speed){
   this->y = this->y - speed ;
}

//move down until on Floor
void Dino::fall(int speed){
   this->y = this->y + speed ;
}

//draw Dino
void Dino::draw(U8GLIB_NHD_C12864* u8g){
  u8g->drawBox(this->getX(), this->getY(),this->getWidth(),this->getHeight());
}

bool Dino::isTouching(Obstacle o){
   return (o.getX()                 > this->getX()                   &&
          o.getX()	           < this->getX() + this->getWidth() &&
          o.getY()                 > this->getY()                   &&
          o.getY()  	 	   < this->getY() + this->getHeight()) ||
	  (o.getX() + o.getLength()> this->getX()                   &&
          o.getX()  + o.getLength()< this->getX() + this->getWidth() &&
          o.getY()                 > this->getY()                   &&
          o.getY()  	 	   < this->getY() + this->getHeight());
}


bool Dino::isJumping(void){
   return isJumping2;
}

bool Dino::isFalling(void){
   return isFalling2;
}

void Dino::startJump(void){
   isJumping2 = true ;
}

void Dino::startFall(void){
   isFalling2 = true ;
}

void Dino::startIdle(void){
   isJumping2 = false ;
   isFalling2 = false ;
}

int Dino::getX(void){
   return this->x ;
}

int Dino::getY(void){
   return this->y ;
}

int Dino::getWidth(void){
   return this->width ;
}

int Dino::getHeight(void){
   return this->height ;
}
