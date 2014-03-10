//Classes for space invaders code
//classes.cc

#include <iostream>
using namespace std;

//////////// Enemies ///////////////////

class Invader {
public:
    bool hit;
    int position;
    int pointValue;
}


//////////// Player ////////////////////

class Player {
public:
    int lives;
    bool hit;
    int position;
    int score;
    bool shoot;
}

Player::Player(int life) {
    lives = life;
    hit = false;
    position = 12;    ////// Change this!!!!! /////////
    score = 0;
    shoot = false;
}

/////////////// Bullet ///////////////

class Bullet {
public:
    int position;
}

////////////// Guards ///////////////

class Guard {
public:
    int position;
    bool hit;
    int health;
}

Guard::Guard(int pos) {
    position = pos;
    hit = false;
    health = 100;
}


