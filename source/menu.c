
#include "3ds.h"
#include "menu.h"


int selected = 0;
bool menupause = 1;
bool pongon = 0;
void display_menu(struct gfx_configuration *config)
{
    int res = 0;

    consoleClear();
    hidScanInput();

    // draw menu
    if(menupause == 1){
	printf("\x1b[4;3H %s normal pong [%s]\n", selected == 0 ? ">" : " ", config->pong ? "ON" : "OFF");
    printf("\x1b[5;3H %s Resume Game       \n", selected == 1 ? ">" : " ");
    printf("\x1b[6;3H %s Exit Game         \n", selected == 2 ? ">" : " ");
	}
	
    u32 kDown = hidKeysDown();
    if (kDown & KEY_DOWN)
    {
        selected = (selected + 1) % 4;
    }
    else if (kDown & KEY_UP)
    {
        selected = (selected + 3) % 4;
    }
    else if (kDown & KEY_A)
    {
        if (selected == 0)
        {
        	pong_game_loop();
        	menupause = 0;
        	pongon = 1;
        }
        else if (selected == 1)
        {
        	pong_game_loop();
        	menupause = 0;
        	pongon = 1;
        }
        else if (selected == 2)
        {
        	shouldrun = 0;
            res = 1;
        } else
        {
            res = -1;
        }
    }

    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();

    //Wait for VBlank
    gspWaitForVBlank();

    return res;
}


