#include "tpl_os.h"
#include "Arduino.h"
#include "U8glib/U8glib.h"
#include "Dino.h"
#include "Obstacle.h"

// System const
#define SCK   13
#define MOSI  11
#define CS    10
#define A0    9
#define RST   8

// Game const
#define FLOOR 50
#define DINO_WIDTH 10
#define DINO_HEIGHT 10
#define DINO_X 10
#define DINO_HEIGHT_JUMP 20
#define OBSTACLE_LENGTH 5
#define WIDTH 127
#define HEIGHT 63 
#define SPEED 7

U8GLIB_NHD_C12864 u8g(SCK, MOSI, CS, A0, RST);


static Dino * dino = NULL;
//also work with : 
//Dino dino2(0,0,0,0);
static Obstacle * o = NULL;
int score = 0;

bool buttonDown(){
  return (analogRead(0) <= 900 && analogRead(0) > 700);
}

void draw(){
//  char buffer [33] = "Score : ";
//  itoa (score,buffer,8);
//	u8g.drawStr(10,3,buffer);
	dino->draw(&u8g);
	o->draw(&u8g);
}

void drawGameOver(){
	u8g.drawStr(10,10,"GAME OVER");
}

void setup() {
  u8g.setRot180();      // rotate screen, if required
  u8g.setContrast(0);
  
  u8g.setFont(u8g_font_6x12);//4x6 5x7 5x8 6x10 6x12 6x13
  u8g.setFontRefHeightText();
  u8g.setFontPosTop();
  
  Serial.begin(9600);

  //10, 50 - 10, 10, 10
  // 10, 40, 20, 50
  dino = new Dino(DINO_X, FLOOR-DINO_HEIGHT, DINO_HEIGHT,DINO_WIDTH);
  o = new Obstacle(WIDTH-OBSTACLE_LENGTH, FLOOR-OBSTACLE_LENGTH, OBSTACLE_LENGTH);
  dino->startIdle();

}

TASK(periodicTask) {
  score ++;
  o->reset(0,WIDTH);
  if(dino->onFloor(FLOOR) && buttonDown()){ //pressbutton
    dino->startIdle();
    dino->startJump();
  }

  if(dino->isJumping())
    dino->jump(SPEED) ;
  
  if(dino->onTop(DINO_HEIGHT_JUMP)){
    dino->startIdle();
    dino->startFall();
  }
  
  if(dino->isFalling())
    dino->fall(SPEED);
  
  if(dino->onFloor(FLOOR)){
    dino->startIdle();
  }
  
  //move
  o->deplace(SPEED);
  
	u8g.firstPage();
      do {
        draw();
      } while(u8g.nextPage());
  
  if(dino->isTouching(*o)){
    if(dino){
      delete dino; 
      dino = NULL;
    }

    if(o){
      delete o;
      o = NULL;
    }
    u8g.firstPage();
      do {
        drawGameOver();
      } while(u8g.nextPage());
  }
}

