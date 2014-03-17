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

//////////// Enemies ///////////////////

struct Invader {
public:
    int x;
    int y;
    int pointValue;
    BITMAP *invdr[3];
    Invader (int, int, int);
    bool hit;
};

Invader:: Invader (int val, int _x, int _y) {
    x = 20+_x;
    y = 40+_y;
    pointValue = val;
    if (val == 40) {   
        invdr[0] = load_bitmap("sprite1.bmp", NULL);
        invdr[1] = load_bitmap("sprite2.bmp", NULL);
    }
    else if (val == 20) {
        invdr[0] = load_bitmap("alien21.bmp", NULL);
        invdr[1] = load_bitmap("alien22.bmp", NULL);
    }
    else if (val == 10) {
        invdr[0] = load_bitmap("alien32.bmp", NULL);
        invdr[1] = load_bitmap("alien31.bmp", NULL);
    }
	hit = false;
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
    plyr = load_bitmap("ship2.bmp", NULL);

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
    grd =load_bitmap("guard2100.bmp", NULL);
}

#endif

