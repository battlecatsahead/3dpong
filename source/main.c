// Simple citro2d untextured shape example
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240
// paddle1 start coordinates
int rect1x = 380;
int rect1y = 120;

// paddle1 speed
rect1speedx = 0;
rect1speedy = 0;

// paddle2 start coordinates
int rect2x = 1;
int rect2y = 120;

// ball coordinates
int ballx = 200;
int bally = 120;

// ball speed
ballspeedx = 3;
ballspeedy = 3;

// set score
int score = 0;

void moveball(){
	ballx += ballspeedx;
	bally += ballspeedy;
}

void collision(){
	if(ballx + 20 >= rect1x && rect1x + 100 >= ballx && bally + 20 >= rect1y && rect1y + 100 >= bally){
	ballspeedx *= -1;
	}
	if(ballx + 20 >= rect2x && rect2x + 20 >= ballx && bally + 20 >= rect2y && rect2y + 100 >= bally){
	ballspeedx *= -1;
	}

    if(bally+20 >= SCREEN_HEIGHT || bally <= 0){
   	ballspeedy *= -1;
    }
    
    if(ballx+20 >= SCREEN_WIDTH || ballx <= 0){
   	ballx = 200;
	bally = 120;
    }
    
	if(bally+20 >= SCREEN_HEIGHT || bally <= 0){
   	ballspeedy *= -1;
    }    
}

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
	while (aptMainLoop())
	{
		hidScanInput();

		// Respond to user input
		u32 kHeld = hidKeysHeld();	
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		// control the paddles
		if(kHeld & KEY_B){
			rect1y -= 3;
		}
		
		if(kHeld & KEY_X){
			rect1y += 3;
		}
		
		if(kHeld & KEY_DUP){
			rect2y -= 3;
		}
		if(kHeld & KEY_DDOWN){
			rect2y += 3;
		}
		if (kDown & KEY_SELECT){
			ballx = 200;
			bally = 120;
		}
		
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);
		C2D_DrawRectSolid(rect1x, rect1y, 0, 20, 100, clrGreen);
		C2D_DrawRectSolid(rect2x, rect2y, 0, 20, 100, clrGreen);
		C2D_DrawRectSolid(ballx, bally, 0, 20, 20, clrGreen);
		collision();
		moveball();
		C3D_FrameEnd(0);
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
