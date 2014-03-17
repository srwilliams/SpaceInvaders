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
    srand(time(NULL));    // For the Invader shoot function
 

    int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
    if (ret !=0) {
        allegro_message(allegro_error);
        return 0;
    }

	if(install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) {
		allegro_message("Error initalizing sound system");
		return 0;
	}


	int panning = 128;
	int pitch = 1000;
	int volume = 128;

	SAMPLE *shoot;
	shoot = load_sample("shoot.wav");
	SAMPLE *beep;
	beep = load_sample("beep.wav");
    set_color_depth(8);
    
    Player player (3);
    Guard guard1 (70);
    Guard guard2 (200);
    Guard guard3 (330);
    Guard guard4 (420);
	BITMAP *boom[2];
	boom[0] = load_bitmap("boom.bmp", NULL);
	boom[1] = load_bitmap("boom2.bmp", NULL);
	boom[2] = load_bitmap("boom.bmp", NULL);

   /// Load sounds ////
	


    BITMAP *buffer = create_bitmap(640, 480);

    int curframe = 0;
    int framedelay = 20;
    int framecount = 0;
    int move = 0;

    clear_bitmap(buffer);


////////////////////////////////////////////////////////





/////// Let's initalize a LOT of invaders //////////////
    Invader invader1 (10, 0, 160);
    Invader invader2 (10, 40, 160);
    Invader invader3 (10, 80, 160);
	Invader invader4 (10, 120, 160);
	Invader invader5 (10, 160, 160);
	Invader invader6 (10, 200, 160);
	Invader invader7 (10, 240, 160);
	Invader invader8 (10, 280, 160);
	Invader invader9 (10, 320, 160);
	Invader invader10 (10, 360, 160);
	Invader invader11 (10, 400, 160);
	Invader invader12 (10, 0, 120);
	Invader invader13 (10, 40, 120);
	Invader invader14 (10, 80, 120);
	Invader invader15 (10, 120, 120);
	Invader invader16 (10, 160, 120);
	Invader invader17 (10, 200, 120);
	Invader invader18 (10, 240, 120);
	Invader invader19 (10, 280, 120);
	Invader invader20 (10, 320, 120);
    Invader invader21 (10, 360, 120);
	Invader invader22 (10, 400, 120);
	Invader invader2_1 (20, 0, 80);
	Invader invader2_2 (20, 40, 80);
	Invader invader2_3 (20, 80, 80);
	Invader invader2_4 (20, 120, 80);
	Invader invader2_5 (20, 160, 80);
	Invader invader2_6 (20, 200, 80);
	Invader invader2_7 (20, 240, 80);
	Invader invader2_8 (20, 280, 80);
	Invader invader2_9 (20, 320, 80);
	Invader invader2_10 (20, 360, 80);
	Invader invader2_11 (20, 400, 80);
	Invader invader2_12 (20, 0, 40);
	Invader invader2_13 (20, 40, 40);
	Invader invader2_14 (20, 80, 40);
	Invader invader2_15 (20, 120, 40);
	Invader invader2_16 (20, 160, 40);
	Invader invader2_17 (20, 200, 40);
	Invader invader2_18 (20, 240, 40);
	Invader invader2_19 (20, 280, 40);
	Invader invader2_20 (20, 320, 40);
	Invader invader2_21 (20, 360, 40);
	Invader invader2_22 (20, 400, 40);
	Invader invader3_1 (40, 0, 10);
	Invader invader3_2 (40, 40, 10);
	Invader invader3_3 (40, 80, 10);
	Invader invader3_4 (40, 120, 10);
	Invader invader3_5 (40, 160, 10);
	Invader invader3_6 (40, 200, 10);
	Invader invader3_7 (40, 240, 10);
	Invader invader3_8 (40, 280, 10);
	Invader invader3_9 (40, 320, 10);
	Invader invader3_10 (40, 360, 10);
	Invader invader3_11 (40, 400, 10);


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
        // Player movement //

        if (key[KEY_RIGHT]) {
            x+=5;
            if (x>WIDTH-50) x = WIDTH-50;
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
			move++;
            
            if (curframe >1) {
                if (move <=35) {
					    invader1.x +=5;
						invader2.x +=5;
						invader3.x +=5;
						invader4.x +=5;
						invader5.x +=5;
						invader6.x +=5;
						invader7.x +=5;
						invader8.x +=5;
						invader9.x +=5;
						invader10.x +=5;
						invader11.x +=5;
						invader12.x +=5;
						invader13.x +=5;
						invader14.x +=5;
						invader15.x +=5;
						invader16.x +=5;
						invader17.x +=5;
						invader18.x +=5;
						invader19.x +=5;
						invader20.x +=5;
						invader21.x +=5;
						invader22.x +=5;
						invader2_1.x +=5;
						invader2_2.x +=5;
						invader2_3.x +=5;
						invader2_4.x +=5;
						invader2_5.x +=5;
						invader2_6.x +=5;
						invader2_7.x +=5;
						invader2_8.x +=5;
						invader2_9.x +=5;
						invader2_10.x +=5;
						invader2_11.x +=5;
						invader2_12.x +=5;
						invader2_13.x +=5;
						invader2_14.x +=5;
						invader2_15.x +=5;
						invader2_16.x +=5;
						invader2_17.x +=5;
						invader2_18.x +=5;
						invader2_19.x +=5;
						invader2_20.x +=5;
						invader2_21.x +=5;
						invader2_22.x +=5;
						invader3_1.x +=5;
						invader3_2.x +=5;
						invader3_3.x +=5;
						invader3_4.x +=5;
						invader3_5.x +=5;
						invader3_6.x +=5;
						invader3_7.x +=5;
						invader3_8.x +=5;
						invader3_9.x +=5;
						invader3_10.x +=5;
						invader3_11.x +=5;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >35) && (move <=38)) {
						invader1.y +=7;
						invader2.y +=7;
						invader3.y +=7;
						invader4.y +=7;
						invader5.y +=7;
						invader6.y +=7;
						invader7.y +=7;
						invader8.y +=7;
						invader9.y +=7;
						invader10.y +=7;
						invader11.y +=7;
						invader12.y +=7;
						invader13.y +=7;
						invader14.y +=7;
						invader15.y +=7;
						invader16.y +=7;
						invader17.y +=7;
						invader18.y +=7;
						invader19.y +=7;
						invader20.y +=7;
						invader21.y +=7;
						invader22.y +=7;
						invader2_1.y +=7;
						invader2_2.y +=7;
						invader2_3.y +=7;
						invader2_4.y +=7;
						invader2_5.y +=7;
						invader2_6.y +=7;
						invader2_7.y +=7;
						invader2_8.y +=7;
						invader2_9.y +=7;
						invader2_10.y +=7;
						invader2_11.y +=7;
						invader2_12.y +=7;
						invader2_13.y +=7;
						invader2_14.y +=7;
						invader2_15.y +=7;
						invader2_16.y +=7;
						invader2_17.y +=7;
						invader2_18.y +=7;
						invader2_19.y +=7;
						invader2_20.y +=7;
						invader2_21.y +=7;
						invader2_22.y +=7;
						invader3_1.y +=7;
						invader3_2.y +=7;
						invader3_3.y +=7;
						invader3_4.y +=7;
						invader3_5.y +=7;
						invader3_6.y +=7;
						invader3_7.y +=7;
						invader3_8.y +=7;
						invader3_9.y +=7;
						invader3_10.y +=7;
						invader3_11.y +=7;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >38) && (move <=71)) {
						invader1.x -=5;
						invader2.x -=5;
						invader3.x -=5;
						invader4.x -=5;
						invader5.x -=5;
						invader6.x -=5;
						invader7.x -=5;
						invader8.x -=5;
						invader9.x -=5;
						invader10.x -=5;
						invader11.x -=5;
						invader12.x -=5;
						invader13.x -=5;
						invader14.x -=5;
						invader15.x -=5;
						invader16.x -=5;
						invader17.x -=5;
						invader18.x -=5;
						invader19.x -=5;
						invader20.x -=5;
						invader21.x -=5;
						invader22.x -=5;
						invader2_1.x -=5;
						invader2_2.x -=5;
						invader2_3.x -=5;
						invader2_4.x -=5;
						invader2_5.x -=5;
						invader2_6.x -=5;
						invader2_7.x -=5;
						invader2_8.x -=5;
						invader2_9.x -=5;
						invader2_10.x -=5;
						invader2_11.x -=5;
						invader2_12.x -=5;
						invader2_13.x -=5;
						invader2_14.x -=5;
						invader2_15.x -=5;
						invader2_16.x -=5;
						invader2_17.x -=5;
						invader2_18.x -=5;
						invader2_19.x -=5;
						invader2_20.x -=5;
						invader2_21.x -=5;
						invader2_22.x -=5;
						invader3_1.x -=5;
						invader3_2.x -=5;
						invader3_3.x -=5;
						invader3_4.x -=5;
						invader3_5.x -=5;
						invader3_6.x -=5;
						invader3_7.x -=5;
						invader3_8.x -=5;
						invader3_9.x -=5;
						invader3_10.x -=5;
						invader3_11.x -=5;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >71) && (move <= 74)) {
						invader1.y +=7;
						invader2.y +=7;
						invader3.y +=7;
						invader4.y +=7;
						invader5.y +=7;
						invader6.y +=7;
						invader7.y +=7;
						invader8.y +=7;
						invader9.y +=7;
						invader10.y +=7;
						invader11.y +=7;
						invader12.y +=7;
						invader13.y +=7;
						invader14.y +=7;
						invader15.y +=7;
						invader16.y +=7;
						invader17.y +=7;
						invader18.y +=7;
						invader19.y +=7;
						invader20.y +=7;
						invader21.y +=7;
						invader22.y +=7;
						invader2_1.y +=7;
						invader2_2.y +=7;
						invader2_3.y +=7;
						invader2_4.y +=7;
						invader2_5.y +=7;
						invader2_6.y +=7;
						invader2_7.y +=7;
						invader2_8.y +=7;
						invader2_9.y +=7;
						invader2_10.y +=7;
						invader2_11.y +=7;
						invader2_12.y +=7;
						invader2_13.y +=7;
						invader2_14.y +=7;
						invader2_15.y +=7;
						invader2_16.y +=7;
						invader2_17.y +=7;
						invader2_18.y +=7;
						invader2_19.y +=7;
						invader2_20.y +=7;
						invader2_21.y +=7;
						invader2_22.y +=7;
						invader3_1.y +=7;
						invader3_2.y +=7;
						invader3_3.y +=7;
						invader3_4.y +=7;
						invader3_5.y +=7;
						invader3_6.y +=7;
						invader3_7.y +=7;
						invader3_8.y +=7;
						invader3_9.y +=7;
						invader3_10.y +=7;
						invader3_11.y +=7;
						play_sample(beep, volume, panning, pitch, FALSE);
						move = 0;
					}
				
                curframe = 0;
            }
            else if (curframe ==1) {
                if (move <=35) {
					    invader1.x +=5;
						invader2.x +=5;
						invader3.x +=5;
						invader4.x +=5;
						invader5.x +=5;
						invader6.x +=5;
						invader7.x +=5;
						invader8.x +=5;
						invader9.x +=5;
						invader10.x +=5;
						invader11.x +=5;
						invader12.x +=5;
						invader13.x +=5;
						invader14.x +=5;
						invader15.x +=5;
						invader16.x +=5;
						invader17.x +=5;
						invader18.x +=5;
						invader19.x +=5;
						invader20.x +=5;
						invader21.x +=5;
						invader22.x +=5;
						invader2_1.x +=5;
						invader2_2.x +=5;
						invader2_3.x +=5;
						invader2_4.x +=5;
						invader2_5.x +=5;
						invader2_6.x +=5;
						invader2_7.x +=5;
						invader2_8.x +=5;
						invader2_9.x +=5;
						invader2_10.x +=5;
						invader2_11.x +=5;
						invader2_12.x +=5;
						invader2_13.x +=5;
						invader2_14.x +=5;
						invader2_15.x +=5;
						invader2_16.x +=5;
						invader2_17.x +=5;
						invader2_18.x +=5;
						invader2_19.x +=5;
						invader2_20.x +=5;
						invader2_21.x +=5;
						invader2_22.x +=5;
						invader3_1.x +=5;
						invader3_2.x +=5;
						invader3_3.x +=5;
						invader3_4.x +=5;
						invader3_5.x +=5;
						invader3_6.x +=5;
						invader3_7.x +=5;
						invader3_8.x +=5;
						invader3_9.x +=5;
						invader3_10.x +=5;
						invader3_11.x +=5;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >35) && (move <=38)) {
						invader1.y +=7;
						invader2.y +=7;
						invader3.y +=7;
						invader4.y +=7;
						invader5.y +=7;
						invader6.y +=7;
						invader7.y +=7;
						invader8.y +=7;
						invader9.y +=7;
						invader10.y +=7;
						invader11.y +=7;
						invader12.y +=7;
						invader13.y +=7;
						invader14.y +=7;
						invader15.y +=7;
						invader16.y +=7;
						invader17.y +=7;
						invader18.y +=7;
						invader19.y +=7;
						invader20.y +=7;
						invader21.y +=7;
						invader22.y +=7;
						invader2_1.y +=7;
						invader2_2.y +=7;
						invader2_3.y +=7;
						invader2_4.y +=7;
						invader2_5.y +=7;
						invader2_6.y +=7;
						invader2_7.y +=7;
						invader2_8.y +=7;
						invader2_9.y +=7;
						invader2_10.y +=7;
						invader2_11.y +=7;
						invader2_12.y +=7;
						invader2_13.y +=7;
						invader2_14.y +=7;
						invader2_15.y +=7;
						invader2_16.y +=7;
						invader2_17.y +=7;
						invader2_18.y +=7;
						invader2_19.y +=7;
						invader2_20.y +=7;
						invader2_21.y +=7;
						invader2_22.y +=7;
						invader3_1.y +=7;
						invader3_2.y +=7;
						invader3_3.y +=7;
						invader3_4.y +=7;
						invader3_5.y +=7;
						invader3_6.y +=7;
						invader3_7.y +=7;
						invader3_8.y +=7;
						invader3_9.y +=7;
						invader3_10.y +=7;
						invader3_11.y +=7;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >38) && (move <=71)) {
						invader1.x -=5;
						invader2.x -=5;
						invader3.x -=5;
						invader4.x -=5;
						invader5.x -=5;
						invader6.x -=5;
						invader7.x -=5;
						invader8.x -=5;
						invader9.x -=5;
						invader10.x -=5;
						invader11.x -=5;
						invader12.x -=5;
						invader13.x -=5;
						invader14.x -=5;
						invader15.x -=5;
						invader16.x -=5;
						invader17.x -=5;
						invader18.x -=5;
						invader19.x -=5;
						invader20.x -=5;
						invader21.x -=5;
						invader22.x -=5;
						invader2_1.x -=5;
						invader2_2.x -=5;
						invader2_3.x -=5;
						invader2_4.x -=5;
						invader2_5.x -=5;
						invader2_6.x -=5;
						invader2_7.x -=5;
						invader2_8.x -=5;
						invader2_9.x -=5;
						invader2_10.x -=5;
						invader2_11.x -=5;
						invader2_12.x -=5;
						invader2_13.x -=5;
						invader2_14.x -=5;
						invader2_15.x -=5;
						invader2_16.x -=5;
						invader2_17.x -=5;
						invader2_18.x -=5;
						invader2_19.x -=5;
						invader2_20.x -=5;
						invader2_21.x -=5;
						invader2_22.x -=5;
						invader3_1.x -=5;
						invader3_2.x -=5;
						invader3_3.x -=5;
						invader3_4.x -=5;
						invader3_5.x -=5;
						invader3_6.x -=5;
						invader3_7.x -=5;
						invader3_8.x -=5;
						invader3_9.x -=5;
						invader3_10.x -=5;
						invader3_11.x -=5;
						play_sample(beep, volume, panning, pitch, FALSE);
					}
					else if ((move >71) && (move <= 74)) {
						invader1.y +=7;
						invader2.y +=7;
						invader3.y +=7;
						invader4.y +=7;
						invader5.y +=7;
						invader6.y +=7;
						invader7.y +=7;
						invader8.y +=7;
						invader9.y +=7;
						invader10.y +=7;
						invader11.y +=7;
						invader12.y +=7;
						invader13.y +=7;
						invader14.y +=7;
						invader15.y +=7;
						invader16.y +=7;
						invader17.y +=7;
						invader18.y +=7;
						invader19.y +=7;
						invader20.y +=7;
						invader21.y +=7;
						invader22.y +=7;
						invader2_1.y +=7;
						invader2_2.y +=7;
						invader2_3.y +=7;
						invader2_4.y +=7;
						invader2_5.y +=7;
						invader2_6.y +=7;
						invader2_7.y +=7;
						invader2_8.y +=7;
						invader2_9.y +=7;
						invader2_10.y +=7;
						invader2_11.y +=7;
						invader2_12.y +=7;
						invader2_13.y +=7;
						invader2_14.y +=7;
						invader2_15.y +=7;
						invader2_16.y +=7;
						invader2_17.y +=7;
						invader2_18.y +=7;
						invader2_19.y +=7;
						invader2_20.y +=7;
						invader2_21.y +=7;
						invader2_22.y +=7;
						invader3_1.y +=7;
						invader3_2.y +=7;
						invader3_3.y +=7;
						invader3_4.y +=7;
						invader3_5.y +=7;
						invader3_6.y +=7;
						invader3_7.y +=7;
						invader3_8.y +=7;
						invader3_9.y +=7;
						invader3_10.y +=7;
						invader3_11.y +=7;
						play_sample(beep, volume, panning, pitch, FALSE);
						move = 0;
					}
				
                
				}
            }
        
        ///////////////////////////////////
              

        
        // Player goes 'pew pew' //////////

        Bullet bullet;
        if (key[KEY_SPACE]) { 
			play_sample(shoot, volume, panning, pitch, FALSE);
            bool done = true;
            do {
            set_keyboard_rate(500, 1);
            bullet.i = x+23;
            bullet.j = y-24;						
            done = false;
            } while (done == true);
            set_keyboard_rate(0,0);
        }

        bullet.j -=5;

        if (bullet.j == 0) {
            destroy_bitmap(bullet.bllt);
        }

        ///////////////////////////////////////
		
///// Draw everything to the screen //////////////////

        clear_bitmap(buffer);


    ////// Draw ALL the invaders to the buffer.... //////////////////
          // I am aware that this is terribly inefficient, but I have a 
          // time restraint for this project

    draw_sprite(buffer, invader1.invdr[curframe], invader1.x, invader1.y);
    draw_sprite(buffer, invader2.invdr[curframe], invader2.x, invader2.y);
    draw_sprite(buffer, invader3.invdr[curframe], invader3.x, invader3.y);
    draw_sprite(buffer, invader4.invdr[curframe], invader4.x, invader4.y);
    draw_sprite(buffer, invader5.invdr[curframe], invader5.x, invader5.y);
    draw_sprite(buffer, invader6.invdr[curframe], invader6.x, invader6.y);
    draw_sprite(buffer, invader7.invdr[curframe], invader7.x, invader7.y);
    draw_sprite(buffer, invader8.invdr[curframe], invader8.x, invader8.y);
    draw_sprite(buffer, invader9.invdr[curframe], invader9.x, invader9.y);
    draw_sprite(buffer, invader10.invdr[curframe], invader10.x, invader10.y);
    draw_sprite(buffer, invader11.invdr[curframe], invader11.x, invader11.y);    
    draw_sprite(buffer, invader12.invdr[curframe], invader12.x, invader12.y);
    draw_sprite(buffer, invader13.invdr[curframe], invader13.x, invader13.y);
    draw_sprite(buffer, invader14.invdr[curframe], invader14.x, invader14.y);
    draw_sprite(buffer, invader15.invdr[curframe], invader15.x, invader15.y);
    draw_sprite(buffer, invader16.invdr[curframe], invader16.x, invader16.y);
    draw_sprite(buffer, invader17.invdr[curframe], invader17.x, invader17.y);
    draw_sprite(buffer, invader18.invdr[curframe], invader18.x, invader18.y);
    draw_sprite(buffer, invader19.invdr[curframe], invader19.x, invader19.y);
    draw_sprite(buffer, invader20.invdr[curframe], invader20.x, invader20.y);
    draw_sprite(buffer, invader21.invdr[curframe], invader21.x, invader21.y);
    draw_sprite(buffer, invader22.invdr[curframe], invader22.x, invader22.y);
    draw_sprite(buffer, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y);
    draw_sprite(buffer, invader2_2.invdr[curframe], invader2_2.x, invader2_2.y);
    draw_sprite(buffer, invader2_3.invdr[curframe], invader2_3.x, invader2_3.y);
    draw_sprite(buffer, invader2_4.invdr[curframe], invader2_4.x, invader2_4.y);
    draw_sprite(buffer, invader2_5.invdr[curframe], invader2_5.x, invader2_5.y);
    draw_sprite(buffer, invader2_6.invdr[curframe], invader2_6.x, invader2_6.y);
    draw_sprite(buffer, invader2_7.invdr[curframe], invader2_7.x, invader2_7.y);
    draw_sprite(buffer, invader2_8.invdr[curframe], invader2_8.x, invader2_8.y);
    draw_sprite(buffer, invader2_9.invdr[curframe], invader2_9.x, invader2_9.y);
    draw_sprite(buffer, invader2_10.invdr[curframe], invader2_10.x, invader2_10.y);
    draw_sprite(buffer, invader2_11.invdr[curframe], invader2_11.x, invader2_11.y);
    draw_sprite(buffer, invader2_12.invdr[curframe], invader2_12.x, invader2_12.y);
    draw_sprite(buffer, invader2_13.invdr[curframe], invader2_13.x, invader2_13.y);
    draw_sprite(buffer, invader2_14.invdr[curframe], invader2_14.x, invader2_14.y);
    draw_sprite(buffer, invader2_15.invdr[curframe], invader2_15.x, invader2_15.y);
    draw_sprite(buffer, invader2_16.invdr[curframe], invader2_16.x, invader2_16.y);
    draw_sprite(buffer, invader2_17.invdr[curframe], invader2_17.x, invader2_17.y);
    draw_sprite(buffer, invader2_18.invdr[curframe], invader2_18.x, invader2_18.y);
    draw_sprite(buffer, invader2_19.invdr[curframe], invader2_19.x, invader2_19.y);
    draw_sprite(buffer, invader2_20.invdr[curframe], invader2_20.x, invader2_20.y);
    draw_sprite(buffer, invader2_21.invdr[curframe], invader2_21.x, invader2_21.y);
    draw_sprite(buffer, invader2_22.invdr[curframe], invader2_22.x, invader2_22.y);
    draw_sprite(buffer, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y);
    draw_sprite(buffer, invader3_2.invdr[curframe], invader3_2.x, invader3_2.y);
    draw_sprite(buffer, invader3_3.invdr[curframe], invader3_3.x, invader3_3.y);
    draw_sprite(buffer, invader3_4.invdr[curframe], invader3_4.x, invader3_4.y);
    draw_sprite(buffer, invader3_5.invdr[curframe], invader3_5.x, invader3_5.y);
    draw_sprite(buffer, invader3_6.invdr[curframe], invader3_6.x, invader3_6.y);
    draw_sprite(buffer, invader3_7.invdr[curframe], invader3_7.x, invader3_7.y);
    draw_sprite(buffer, invader3_8.invdr[curframe], invader3_8.x, invader3_8.y);
    draw_sprite(buffer, invader3_9.invdr[curframe], invader3_9.x, invader3_9.y);
    draw_sprite(buffer, invader3_10.invdr[curframe], invader3_10.x, invader3_10.y);
    draw_sprite(buffer, invader3_11.invdr[curframe], invader3_11.x, invader3_11.y);

    /////// Now draw the invaders to the screen ////////////

    draw_sprite(screen, invader1.invdr[curframe], invader1.x, invader1.y);
    draw_sprite(screen, invader2.invdr[curframe], invader2.x, invader2.y);
    draw_sprite(screen, invader3.invdr[curframe], invader3.x, invader3.y);
    draw_sprite(screen, invader4.invdr[curframe], invader4.x, invader4.y);
    draw_sprite(screen, invader5.invdr[curframe], invader5.x, invader5.y);
    draw_sprite(screen, invader6.invdr[curframe], invader6.x, invader6.y);
    draw_sprite(screen, invader7.invdr[curframe], invader7.x, invader7.y);
    draw_sprite(screen, invader8.invdr[curframe], invader8.x, invader8.y);
    draw_sprite(screen, invader9.invdr[curframe], invader9.x, invader9.y);
    draw_sprite(screen, invader10.invdr[curframe], invader10.x, invader10.y);
    draw_sprite(screen, invader11.invdr[curframe], invader11.x, invader11.y);    
    draw_sprite(screen, invader12.invdr[curframe], invader12.x, invader12.y);
    draw_sprite(screen, invader13.invdr[curframe], invader13.x, invader13.y);
    draw_sprite(screen, invader14.invdr[curframe], invader14.x, invader14.y);
    draw_sprite(screen, invader15.invdr[curframe], invader15.x, invader15.y);
    draw_sprite(screen, invader16.invdr[curframe], invader16.x, invader16.y);
    draw_sprite(screen, invader17.invdr[curframe], invader17.x, invader17.y);
    draw_sprite(screen, invader18.invdr[curframe], invader18.x, invader18.y);
    draw_sprite(screen, invader19.invdr[curframe], invader19.x, invader19.y);
    draw_sprite(screen, invader20.invdr[curframe], invader20.x, invader20.y);
    draw_sprite(screen, invader21.invdr[curframe], invader21.x, invader21.y);
    draw_sprite(screen, invader22.invdr[curframe], invader22.x, invader22.y);
    draw_sprite(screen, invader2_1.invdr[curframe], invader2_1.x, invader2_1.y);
    draw_sprite(screen, invader2_2.invdr[curframe], invader2_2.x, invader2_2.y);
    draw_sprite(screen, invader2_3.invdr[curframe], invader2_3.x, invader2_3.y);
    draw_sprite(screen, invader2_4.invdr[curframe], invader2_4.x, invader2_4.y);
    draw_sprite(screen, invader2_5.invdr[curframe], invader2_5.x, invader2_5.y);
    draw_sprite(screen, invader2_6.invdr[curframe], invader2_6.x, invader2_6.y);
    draw_sprite(screen, invader2_7.invdr[curframe], invader2_7.x, invader2_7.y);
    draw_sprite(screen, invader2_8.invdr[curframe], invader2_8.x, invader2_8.y);
    draw_sprite(screen, invader2_9.invdr[curframe], invader2_9.x, invader2_9.y);
    draw_sprite(screen, invader2_10.invdr[curframe], invader2_10.x, invader2_10.y);
    draw_sprite(screen, invader2_11.invdr[curframe], invader2_11.x, invader2_11.y);
    draw_sprite(screen, invader2_12.invdr[curframe], invader2_12.x, invader2_12.y);
    draw_sprite(screen, invader2_13.invdr[curframe], invader2_13.x, invader2_13.y);
    draw_sprite(screen, invader2_14.invdr[curframe], invader2_14.x, invader2_14.y);
    draw_sprite(screen, invader2_15.invdr[curframe], invader2_15.x, invader2_15.y);
    draw_sprite(screen, invader2_16.invdr[curframe], invader2_16.x, invader2_16.y);
    draw_sprite(screen, invader2_17.invdr[curframe], invader2_17.x, invader2_17.y);
    draw_sprite(screen, invader2_18.invdr[curframe], invader2_18.x, invader2_18.y);
    draw_sprite(screen, invader2_19.invdr[curframe], invader2_19.x, invader2_19.y);
    draw_sprite(screen, invader2_20.invdr[curframe], invader2_20.x, invader2_20.y);
    draw_sprite(screen, invader2_21.invdr[curframe], invader2_21.x, invader2_21.y);
    draw_sprite(screen, invader2_22.invdr[curframe], invader2_22.x, invader2_22.y);
    draw_sprite(screen, invader3_1.invdr[curframe], invader3_1.x, invader3_1.y);
    draw_sprite(screen, invader3_2.invdr[curframe], invader3_2.x, invader3_2.y);
    draw_sprite(screen, invader3_3.invdr[curframe], invader3_3.x, invader3_3.y);
    draw_sprite(screen, invader3_4.invdr[curframe], invader3_4.x, invader3_4.y);
    draw_sprite(screen, invader3_5.invdr[curframe], invader3_5.x, invader3_5.y);
    draw_sprite(screen, invader3_6.invdr[curframe], invader3_6.x, invader3_6.y);
    draw_sprite(screen, invader3_7.invdr[curframe], invader3_7.x, invader3_7.y);
    draw_sprite(screen, invader3_8.invdr[curframe], invader3_8.x, invader3_8.y);
    draw_sprite(screen, invader3_9.invdr[curframe], invader3_9.x, invader3_9.y);
    draw_sprite(screen, invader3_10.invdr[curframe], invader3_10.x, invader3_10.y);
    draw_sprite(screen, invader3_11.invdr[curframe], invader3_11.x, invader3_11.y);

    //////////////////////////////////////////////////////////////////////////////

        /// Draw everything else /////////////////////        
		draw_sprite(buffer, player.plyr, x, y);
        draw_sprite(buffer, guard1.grd, guard1.x, guard1.y);
		draw_sprite(buffer, guard2.grd, guard2.x, guard2.y);
		draw_sprite(buffer, guard3.grd, guard3.x, guard3.y);
		draw_sprite(buffer, guard4.grd, 460, 340);
        draw_sprite(buffer, bullet.bllt, bullet.i, bullet.j);
        draw_sprite(screen, player.plyr, x, y);
        draw_sprite(screen, guard1.grd, guard1.x, guard1.y);
        draw_sprite(screen, guard2.grd, guard2.x, guard2.y);
        draw_sprite(screen, guard3.grd, guard3.x, guard3.y);
        draw_sprite(screen, guard4.grd, 460, 340);
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

