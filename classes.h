//Classes for space invaders code
//classes.h

#ifndef _CLASSES_H
#define _CLASSES_H

#include <stdlib.h>
#include <ctime>
#include "allegro.h"

#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480

//////////// General ///////////////////

void timer(clock_t sec) {
    clock_t startTime = clock();
    clock_t endTime = sec*1000 + startTime;
    while(clock() != endTime);
}


//////////// Enemies ///////////////////

class Invader {
public:
    int x;
    int y;
    int pointValue;
    BITMAP *invdr[3];
    Invader (int);
    void move(int);
};

Invader:: Invader (int val) {
    x = 0;
    y = 30;
    pointValue = val;
    invdr[0] = load_bitmap("sprite1.bmp", NULL);
    invdr[1] = load_bitmap("sprite2.bmp", NULL);
}

//////////// Player ////////////////////

class Player {
public:
    int lives;
    int x;
    int y;
    int score;
    BITMAP *plyr;
    Player (int);
};

Player::Player(int life) {
    lives = life;
    x = 328;
    y = 430;
    score = 0;
    plyr = load_bitmap("ship.bmp", NULL);

}

/////////////// Bullet ///////////////
class Bullet {
public:
    int i;
    int j;
    BITMAP *bllt = load_bitmap("bullet.bmp", NULL);
};



////////////// Guards ///////////////

class Guard {
public:
    int x;
    int y;;
    bool hit;
    int health;
    Guard (int);
    BITMAP *grd;
};

Guard::Guard(int pos) {
    x = pos;
    y = 340;
    health = 100;
    grd =load_bitmap("guard100.bmp", NULL);
}





#endif

