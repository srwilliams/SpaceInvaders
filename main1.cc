// another main
// main1.cc

#include <stdio.h>
#include <stdlib.h>
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
    
    Invader invader (20);
    Player player (3);
    Bullet bullet;
    Guard guard (30);

    // positions for player sprite //
    int x = WIDTH/2 - (player.plyr)->w/2;
    int y = 430;


    // Animations of sprites //
    int curframe = 0;
    int framedelay = 20;
    int framecount = 0;

    // Load alien sprites //
    //alien[0] = load_bitmap("sprite1.bmp", NULL);
    //alien[1] = load_bitmap("sprite2.bmp", NULL);

    // positions for alien sprite //
    int a = 0;
    int b = 30;

    
    // start while !esc loop //
    while (!key[KEY_ESC]) {

        clear_keybuf();
        hline(screen, 0, 0, 638, makecol(0, 204, 0));
        hline(screen, 0, 478, 638, makecol(0, 204, 0));
        vline(screen, 0, 0, 478, makecol(0, 204, 0));
        vline(screen, 638, 0, 478, makecol(0, 204, 0));

        rectfill(screen, x, y, x+(player.plyr->w), y+(player.plyr->h), 0);
        rectfill(screen, a, b, a+invader.invdr[0]->w, b+invader.invdr[0]->h, 0);

        if (key[KEY_RIGHT]) {
            x+=2;
            if (x>WIDTH-20) x = WIDTH-20;
        }
        else if (key[KEY_LEFT]) {
            x-=2;
            if (x<2) x=2;
        }

        if (a <WIDTH - (2+invader.invdr[0]->w)) a+=2;

        if (framecount++ > framedelay) {
            framecount = 0;
            curframe++;
            if (curframe >1) {
                curframe = 0;
            }
        }

        // Let's try the shooting thing now //
        if (key[KEY_SPACE]) {
            playershoot(bullet, guard, x, y);
            for (y>=1; y-=2;) {
                draw_sprite(screen, bullet.bllt, x, y);
                if ((guard.x == bullet.x) && (guard.y == bullet.y)) {
                    guard.health -=20;
                    if (guard.health ==80) guard.grd = load_bitmap("guard80.bmp", NULL);
                    else if (guard.health ==60) guard.grd = load_bitmap("guard60.bmp", NULL);
                    else if (guard.health ==40) guard.grd = load_bitmap("guard40.bmp", NULL);
                    else if (guard.health ==20) guard.grd = load_bitmap("guard20.bmp", NULL);
                    else destroy_bitmap(guard.grd);
                }
                else if ((bullet.x == invader.x) && (bullet.y == invader.y)) {
                    BITMAP *boom = load_bitmap("boom.bmp", NULL);
                    draw_sprite(screen, boom, invader.x, invader.y);
                    //insert timer here///
                    destroy_bitmap(boom);
                    player.score += invader.pointValue;
                }
                else if (bullet.y <=2) destroy_bitmap(bullet.bllt);
            }
        }




        draw_sprite(screen, player.plyr, x, y);
        draw_sprite(screen, invader.invdr[curframe], invader.x, invader.y);
        rest(1);
    }

    destroy_bitmap(player.plyr);
    destroy_bitmap(invader.invdr[0]);
    destroy_bitmap(invader.invdr[1]);
    allegro_exit();
    return 0;
}
END_OF_MAIN();


    
