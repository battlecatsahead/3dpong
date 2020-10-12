// Simple citro2d untextured shape example
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pong.h"

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240
struct gfx_configuration gfx_config = {true, false}; // pong or snake

void pong_game_loop(){
	moveball();
	collision();
	controls();
	drawpong();
}
shouldrun = 1;
//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	// Create colors
	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	u32 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
	u32 clrBlue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);

	u32 clrCircle1 = C2D_Color32(0xFF, 0x00, 0xFF, 0xFF);
	u32 clrCircle2 = C2D_Color32(0xFF, 0xFF, 0x00, 0xFF);
	u32 clrCircle3 = C2D_Color32(0x00, 0xFF, 0xFF, 0xFF);

	u32 clrSolidCircle = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF);

	u32 clrTri1 = C2D_Color32(0xFF, 0x15, 0x00, 0xFF);
	u32 clrTri2 = C2D_Color32(0x27, 0x69, 0xE5, 0xFF);

	u32 clrRec1 = C2D_Color32(0x9A, 0x6C, 0xB9, 0xFF);
	u32 clrRec2 = C2D_Color32(0xFF, 0xFF, 0x2C, 0xFF);
	u32 clrRec3 = C2D_Color32(0xD8, 0xF6, 0x0F, 0xFF);
	u32 clrRec4 = C2D_Color32(0x40, 0xEA, 0x87, 0xFF);

	u32 clrClear = C2D_Color32(0x00, 0x00, 0x00, 0x00);

	// Main loop
	while (aptMainLoop() && shouldrun == 1)
	{
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
		    printf("START pressed, exitting...");
			break; // break in order to return to hbmenu
		}
		if(kDown & KEY_SELECT){
			display_menu(&gfx_config);
			pongon = 0;
		}

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);
		if(menupause == 1){
		display_menu(&gfx_config);
		}
		if(pongon == 1){
			pong_game_loop();
		}
		C3D_FrameEnd(0);
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
