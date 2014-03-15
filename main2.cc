// another main
// main2.cc

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <new>

#include "allegro.h"
#include "classes.h"


int main(void) {

///// Begin setup ////////////////////////////////////

    allegro_init();
    install_keyboard();
    srand(time(NULL));
    

    int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
    if (ret !=0) {
        allegro_message(allegro_error);
        return 0;
    }

    set_color_depth(8);
    
    Player player (3);
    Guard guard1 (70);
    Guard guard2 (140);
    Guard guard3 (210);
    Guard guard4 (280);

    BITMAP *buffer = create_bitmap(640, 480);

    int curframe = 0;
    int framedelay = 20;
    int framecount = 0;

    clear_bitmap(buffer);

////////////////////////////////////////////////////////


/////// Let's initalize a LOT of invaders //////////////
    //Invader *army = static_cast<Invader*> (::operator new (sizeof(Invader[56])));

    std::vector<Invader> army;
    army.reserve(55);

    Invader invader1 (10);
    Invader invader2 (10);
    Invader invader3 (10);
	Invader invader4 (10);
	Invader invader5 (10);
	Invader invader6 (10);
	Invader invader7 (10);
	Invader invader8 (10);
	Invader invader9 (10);
	Invader invader10 (10);
	Invader invader11 (10);
	Invader invader12 (10);
	Invader invader13 (10);
	Invader invader14 (10);
	Invader invader15 (10);
	Invader invader16 (10);
	Invader invader17 (10);
	Invader invader18 (10);
	Invader invader19 (10);
	Invader invader20 (10);
    Invader invader21 (10);
	Invader invader22 (10);
	Invader invader2_1 (20);
	Invader invader2_2 (20);
	Invader invader2_3 (20);
	Invader invader2_4 (20);
	Invader invader2_5 (20);
	Invader invader2_6 (20);
	Invader invader2_7 (20);
	Invader invader2_8 (20);
	Invader invader2_9 (20);
	Invader invader2_10 (20);
	Invader invader2_11 (20);
	Invader invader2_12 (20);
	Invader invader2_13 (20);
	Invader invader2_14 (20);
	Invader invader2_15 (20);
	Invader invader2_16 (20);
	Invader invader2_17 (20);
	Invader invader2_18 (20);
	Invader invader2_19 (20);
	Invader invader2_20 (20);
	Invader invader2_21 (20);
	Invader invader2_22 (20);
	Invader invader3_1 (40);
	Invader invader3_2 (40);
	Invader invader3_3 (40);
	Invader invader3_4 (40);
	Invader invader3_5 (40);
	Invader invader3_6 (40);
	Invader invader3_7 (40);
	Invader invader3_8 (40);
	Invader invader3_9 (40);
	Invader invader3_10 (40);
	Invader invader3_11 (40);

    army[1] = invader1;
    army[2] = invader2;
    army[3] = invader3;
    army[4] = invader4;
    army[5] = invader5;
    army[6] = invader6;
    army[7] = invader7;
    army[8] = invader8;
    army[9] = invader9;
    army[10] = invader10;
    army[11] = invader11;
    army[12] = invader12;
    army[13] = invader13;
    army[14] = invader14;
    army[15] = invader15;
    army[16] = invader16;
    army[17] = invader17;
    army[18] = invader18;
    army[19] = invader19;
    army[20] = invader20;    
    army[21] = invader21;
    army[22] = invader22;
    army[23] = invader2_1;
    army[24] = invader2_2;
    army[25] = invader2_3;
    army[26] = invader2_4;
    army[27] = invader2_5;
    army[28] = invader2_6;
    army[29] = invader2_7;
    army[30] = invader2_8;
    army[31] = invader2_9;
    army[32] = invader2_10;    
    army[33] = invader2_11;
    army[34] = invader2_12;
    army[35] = invader2_13;
    army[36] = invader2_14;
    army[37] = invader2_15;
    army[38] = invader2_16;
    army[39] = invader2_17;
    army[40] = invader2_18;
    army[41] = invader2_19;
    army[42] = invader2_20;
    army[43] = invader2_21;
    army[44] = invader2_22;    
    army[45] = invader3_1;
    army[46] = invader3_2;
    army[47] = invader3_3;
    army[48] = invader3_4;
    army[49] = invader3_5;
    army[50] = invader3_6;
    army[51] = invader3_7;
    army[52] = invader3_8;
    army[53] = invader3_9;
    army[54] = invader3_10;
    army[55] = invader3_11;
//////////////////////////////////////////////////////


//////// Starting positions /////////////////////////

    // positions for player sprite //
    int x = WIDTH/2 - (player.plyr)->w/2;
    int y = 430;

    // positions for alien sprite //
    int a = 20;
    int b = 30;

//////////////////////////////////////////////////////

    
    // start while !esc loop //
    while (!key[KEY_ESC]) {

        clear_keybuf();
        hline(buffer, 0, 0, 638, makecol(0, 204, 0));
        hline(buffer, 0, 478, 638, makecol(0, 204, 0));
        vline(buffer, 0, 0, 478, makecol(0, 204, 0));
        vline(buffer, 638, 0, 478, makecol(0, 204, 0));

        rectfill(screen, x, y, x+(player.plyr->w), y+(player.plyr->h), 0);
        rectfill(screen, a, b, a+invader1.invdr[0]->w, b+invader1.invdr[0]->h, 0);
        
        // Player movement //

        if (key[KEY_RIGHT]) {
            x+=5;
            if (x>WIDTH-20) x = WIDTH-20;
        }
        else if (key[KEY_LEFT]) {
            x-=5;
            if (x<2) x=2;
        }
        /////////////////////

        // Animations for the invaders //

        if (framecount++ > framedelay) {
            framecount = 0;
            curframe++;
            
            if (curframe >1) {
                for (std::vector<Invader>::iterator i = army.begin(); i != army.end(); ++i) {
					(*i).x +=15;
				}
                curframe = 0;
            }
            else if (curframe ==1) {
                for (std::vector<Invader>::iterator i = army.begin(); i != army.end(); i++) {
					(*i).x +=15;
				}
            }
        }
        ///////////////////////////////////
              

        
        // Player goes 'pew pew' //////////

        Bullet bullet;
        if (key[KEY_SPACE]) { 
            bool done = true;
            do {
            set_keyboard_rate(500, 1);
            bullet.i = x+15;
            bullet.j = y-17;
            done = false;
            } while (done == true);
            set_keyboard_rate(0,0);
        }

        bullet.j -=4;

        if (bullet.j == 0) {
            destroy_bitmap(bullet.bllt);
        }
        ///////////////////////////////////////




///// Draw everything to the screen //////////////////

        clear_bitmap(buffer);
        draw_sprite(buffer, player.plyr, x, y);

    ////// Draw ALL the invaders to the buffer.... //////////////////
          // I am aware that this is terribly inefficient, but I have a 
          // time restraint for this project

    draw_sprite(buffer, invader1.invdr[curframe], invader1.x, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+40, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+80, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+120, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+160, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+200, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+240, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+280, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+320, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+360, invader1.y);
    draw_sprite(buffer, invader1.invdr[curframe], invader1.x+400, invader1.y);    
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+40, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+80, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+120, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+160, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+200, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+240, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+280, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+320, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+360, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+400, invader2_1.y+40);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+40, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+80, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+120, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+160, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+200, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+240, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+280, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+320, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+360, invader2_1.y+80);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x+400, invader2_1.y+80);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+40, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+80, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+120, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+160, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+200, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+240, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+280, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+320, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+360, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+400, invader3_1.y+120);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+40, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+80, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+120, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+160, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+200, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+240, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+280, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+320, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+360, invader3_1.y+160);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x+400, invader3_1.y+160);

    /////// Now draw the invaders to the screen ////////////

    draw_sprite(screen, invader1.invdr[curframe], invader1.x, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+40, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+80, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+120, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+160, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+200, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+240, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+280, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+320, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+360, invader1.y);
    draw_sprite(screen, invader1.invdr[curframe], invader1.x+400, invader1.y);    
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+40, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+80, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+120, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+160, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+200, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+240, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+280, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+320, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+360, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+400, invader2_1.y+40);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+40, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+80, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+120, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+160, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+200, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+240, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+280, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+320, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+360, invader2_1.y+80);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x+400, invader2_1.y+80);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+40, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+80, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+120, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+160, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+200, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+240, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+280, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+320, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+360, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+400, invader3_1.y+120);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+40, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+80, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+120, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+160, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+200, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+240, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+280, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+320, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+360, invader3_1.y+160);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x+400, invader3_1.y+160);

    //////////////////////////////////////////////////////////////////////////////

        /// Draw everything else /////////////////////
        draw_sprite(buffer, guard1.grd, guard1.x, guard1.y);
        draw_sprite(buffer, bullet.bllt, bullet.i, bullet.j);
        draw_sprite(screen, player.plyr, x, y);
        draw_sprite(screen, guard1.grd, guard1.x, guard1.y);
        draw_sprite(screen, bullet.bllt, bullet.i, bullet.j);
        vsync();
        blit(buffer, screen, 0,0,0,0,640,480);
        rest(1);
/////// End of !Esc loop ///////////////////////////////////////////////////////////
    }

///////// Clean up //////////////////////

    destroy_bitmap(player.plyr);
    destroy_bitmap(invader1.invdr[0]);
    destroy_bitmap(invader1.invdr[1]);
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();

