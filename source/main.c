// Simple citro2d untextured shape example
#include <3ds.h>
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
int ball2x = 200;
int ball2y = 120;
// ball speed
float ballspeedx = 3;
float ballspeedy = 3;
float ball2speedx = -3;
float ball2speedy = -3;
// set score
int scorep1 = 0;
int scorep2 = 0;
bool twoball = 1;
int menuoptions = 1;

void moveball(){
	ballx += ballspeedx;
	bally += ballspeedy;
	ball2y += ball2speedy;
	ball2x += ball2speedx;
}

void collision(){

	if(ballx + 20 >= rect1x && rect1x + 100 >= ballx && bally + 20 >= rect1y && rect1y + 100 >= bally){
	ballspeedx *= -1;

	}
	if(ballx + 20 >= rect2x && rect2x + 20 >= ballx && bally + 20 >= rect2y && rect2y + 100 >= bally){
	ballspeedx *= -1;

	}
	
	if(ball2x + 20 >= rect1x && rect1x + 100 >= ball2x && ball2y + 20 >= rect1y && rect1y + 100 >= ball2y){
	ball2speedx *= -1;

	}
	if(ball2x + 20 >= rect2x && rect2x + 20 >= ball2x && ball2y + 20 >= rect2y && rect2y + 100 >= ball2y){
	ball2speedx *= -1;

	}

    if(bally+20 >= SCREEN_HEIGHT || bally <= 0){
   	ballspeedy *= -1;
    }
    
	if(ball2y+20 >= SCREEN_HEIGHT || ball2y <= 0){
   	ball2speedy *= -1;
    }
    
    if(ballx+20 >= SCREEN_WIDTH || ballx <= 0){
   	ballx = 200;
	bally = 120;
    }
    if(ball2x+20 >= SCREEN_WIDTH || ball2x <= 0){
   	ball2x = 200;
	ball2y = 120;
    }
    
    if(rect1y+100 >= SCREEN_HEIGHT){
   	rect1y -= 3;
    }   
	if(rect1y <= 0){
   	rect1y += 3;
    }
	  
	if(rect2y+100 >= SCREEN_HEIGHT){
   	rect2y -= 3;
    }   
	if(rect2y <= 0){
   	rect2y += 3;
    }     
 
}

void checkmode(){
	/*if(twoball == 0){
		C2D_DrawRectSolid(ball2x, ball2y, 0, 20, 20, clrWhite);
	}*/
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
 	PrintConsole leftWindow, rightWindow, bottomScreen;
 
	//Initialize console for each window
	consoleInit(GFX_BOTTOM, &leftWindow);
	consoleInit(GFX_BOTTOM, &rightWindow);

	consoleInit(GFX_BOTTOM, &bottomScreen);
 
 	//Now we specify the window position and dimension for each console window using consoleSetWindow(PrintConsole* console, int x, int y, int width, int height);
	//x, y, width and height are in terms of cells, not pixel, where each cell is composed by 8x8 pixels.
 	consoleSetWindow(&leftWindow, 1, 1, 23, 28);
 	consoleSetWindow(&rightWindow, 26, 1, 23, 28);
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
		rect1y += 3;
		}
		
		if(kHeld & KEY_X){
		rect1y -= 3;
		}
		if(kHeld & KEY_UP){
			rect2y -= 3;
		}
		if(kHeld & KEY_DOWN){
			rect2y += 3;
		}
		if(kDown & KEY_R){
			if(twoball == 1){
				twoball = 0;
			}else{
				twoball = 1;
			}
		}
				
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);
		if(twoball == 0){
		C2D_DrawRectSolid(ball2x, ball2y, 0, 20, 20, clrWhite);
		}
		C2D_DrawRectSolid(rect1x, rect1y, 0, 20, 100, clrWhite);
		C2D_DrawRectSolid(rect2x, rect2y, 0, 20, 100, clrWhite);
		C2D_DrawRectSolid(ballx, bally, 0, 20, 20, clrWhite);
		C2D_DrawRectSolid(200, 0, 0, 20, 240, clrWhite);
		game_menu();
		collision();
		moveball();
		//checkmode();
		C3D_FrameEnd(0);
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
