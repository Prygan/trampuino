#include "Obstacle.h"


Obstacle::Obstacle(int x, int y, int length){
   this->x = x ;
   this->y = y ;
   this->length = length ;
}

void Obstacle::deplace(int speed){
   this->x = this->x - speed ;
}

//draw Obstacle
void Obstacle::draw(U8GLIB_NHD_C12864* u8g){
   u8g->drawBox(this->getX(), this->getY(), this->getLength(), this->getLength());
}

void Obstacle::reset(int maxX, int resetPosX){
	if(this->getX() <= maxX)
		this->x = resetPosX ;
}

int Obstacle::getX(void){
   return this->x ;
}

int Obstacle::getY(void){
   return this->y ;
}

int Obstacle::getLength(void){
   return this->length ;
}
