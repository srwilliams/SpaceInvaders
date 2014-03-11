// The class structs for the sprites and such
// sprites.cc

// This program courtesy of Johnathan S. Harbor
// Game Programming All In One, 2nd edition

typedef struct SPRITE {
    int x, y;                                 // Track the sprite's position
    int width, height;                        // Set to the size of the sprite image
    int xspeed, yspeed;                       // Set how many pixels the sprite will
    int xdelay, ydelay;                       //  move in conjunction with the velocity
    int xcount, ycount;                       //  delay (xcount, xdelay, ycount, ydelay)
    int curframe, maxframe, animdir;          // Help with sprite animation
    int framecount, framedelay;               // Slow down animation rate
}SPRITE;



void updateSprite(SPRITE *spr) {
    
    // Update x position
    if (++spr->xcount > spr->xdelay) {
        spr->xcount =0;
        spr->x += spr->xspeed;
    }

    // Update y position
    if (++spr->ycount > spr->ydelay) {
        spr->ycount =0;
        spr->y += spr->yspeed;
    }

    // Update frame based on animdir
    if (++spr->framecount > spr->framedelay) {
        spr->framecount =0;
        if (spr->animdir == -1) {
            if (--spr->curframe < 0) {
                spr->curframe = spr->maxframe;
            }
        }
        else if (spr->animdir == 1) {
            if (++spr->curframe > spr->maxframe) {
                spr->curframe = 0;
            }
        }
    }
}



