// another main
// main1.cc

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include "allegro.h"
#include "classes.h"


int main(void) {

    ////////// Begin setup ///////////

    allegro_init();
    install_keyboard();
    srand(time(NULL));

    int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
    if (ret !=0) {
        allegro_message(allegro_error);
        return 0;
    }

    set_color_depth(8);
    
    //Invader invader (20);
    Player player (3);
    Guard guard (70);


    ///////// Initialize Invaders //////////////////
    Invader *invaderArmy[5];
    Invader *invaderRow1[12];    // there are 11 invaders in a row:
    Invader *invaderRow2[12];    // two rows of 10-point invaders
    Invader *invaderRow3[12];    // two rows of 20-point invaders
    Invader *invaderRow4[12];    // and one row of 40-point invaders
    Invader *invaderRow5[12];

    for (int i=0; i<12, i++) {




    // positions for player sprite //
    int x = WIDTH/2 - (player.plyr)->w/2;
    int y = 430;


    // Animations of sprites //
    int curframe = 0;
    int framedelay = 20;
    int framecount = 0;


    // positions for alien sprite //
    int a = 20;
    int b = 30;
    //////////////////////////////////////////////

    
    // start while !esc loop //
    while (!key[KEY_ESC]) {

        clear_keybuf();
        hline(screen, 0, 0, 638, makecol(0, 204, 0));
        hline(screen, 0, 478, 638, makecol(0, 204, 0));
        vline(screen, 0, 0, 478, makecol(0, 204, 0));
        vline(screen, 638, 0, 478, makecol(0, 204, 0));

        rectfill(screen, x, y, x+(player.plyr->w), y+(player.plyr->h), 0);
        rectfill(screen, a, b, a+invader.invdr[0]->w, b+invader.invdr[0]->h, 0);
        
        // Player movement //

        if (key[KEY_RIGHT]) {
            x+=2;
            if (x>WIDTH-20) x = WIDTH-20;
        }
        else if (key[KEY_LEFT]) {
            x-=2;
            if (x<2) x=2;
        }
        /////////////////////

        // Animations for the invaders //

        if (a <WIDTH - (2+invader.invdr[0]->w)) {
            a+=2;
            invader.x = a;
        }

        if (framecount++ > framedelay) {
            framecount = 0;
            curframe++;
            if (curframe >1) {
                curframe = 0;
            }
        }
        ///////////////////////////////////
              

        
        // Let's try the shooting thing now //

        Bullet bullet;
        if (key[KEY_SPACE]) { 
            bullet.i = x;
            bullet.j = y;
        }

        bullet.j -=2;

        if (bullet.j == 0) {
            destroy_bitmap(bullet.bllt);
        }
        ///////////////////////////////////////



        draw_sprite(screen, player.plyr, x, y);
        draw_sprite(screen, invader.invdr[curframe], invader.x, invader.y);
        draw_sprite(screen, guard.grd, guard.x, guard.y);
        draw_sprite(screen, bullet.bllt, bullet.i, bullet.j);
        rest(1);
    }

    destroy_bitmap(player.plyr);
    destroy_bitmap(invader.invdr[0]);
    destroy_bitmap(invader.invdr[1]);
    allegro_exit();
    return 0;
}
END_OF_MAIN();


    
