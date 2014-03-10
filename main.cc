// main file
// work in progress

//#include <conio.h>
#include <stdlib.h>
#include "allegro.h"

int main(void) {
    ///////// define variables //////////
    ///////// set up game ///////////////

    allegro_init();                  // initialize allegro
    install_keyboard();              // set up keyboard
    srand(time(NULL));               // initialize random number generator

    int ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
                                     // initialize video mode
                                     // For tests: "GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);"
                                     // Windowed mode just makes it easier to test and debug.
                                     // Change these values after tests are complete

    if (ret != 0) {                  // If the setgfxmode function fails,
        allegro_message(allegro_error); // it returns a non-zero, and we
        return 0;                     // print out an error message in a popup window
    }

    set_color_depth(8);

    BITMAP *sqr;
    sqr = load_bmp("bmp_24.bmp", NULL);
    int x = SCREEN_W/2 - sqr->w/2;
    int y = SCREEN_H/2 - sqr->h/2;

    while(!key[KEY_ESC]) {           // Let's make a nice pretty green border around our screen

        hline(screen, 0, 0, 639, makecol(0, 204, 0));
        hline(screen, 0, 479, 639, makecol(0, 204, 0));
        vline(screen, 0, 0, 479, makecol(0, 204, 0));
        vline(screen, 639, 0, 479, makecol(0, 204, 0));


                                     // Let's write some test text
        textout(screen, font, "SPACE INVADERS", 50, 10, makecol(230, 0 , 0));
        textout(screen, font, "Press Esc key to exit", 50, 20, makecol(230, 0, 0));
        
        // erase the sprite
        rectfill(screen, x, y, x+sqr->w, y+sqr->h, 0);

        if (x-- <2)
            x = SCREEN_W - sqr->w;
            
        draw_sprite(screen, sqr, x, y);
        rest(1);

    }
    
    destroy_bitmap(sqr);
    allegro_exit();
    return 0;
}

END_OF_MAIN();
    ///////// play game /////////////////
