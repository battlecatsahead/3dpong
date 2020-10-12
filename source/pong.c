#include "pong.h"
#include "menu.h"
#include <citro2d.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
int twoball = 0;
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

    if(bally+20 >= 240 || bally <= 0){
   	ballspeedy *= -1;
    }
    
	if(ball2y+20 >= 240 || ball2y <= 0){
   	ball2speedy *= -1;
    }
    
    if(ballx+20 >= 400 || ballx <= 0){
   	ballx = 200;
	bally = 120;
    }
    if(ball2x+20 >= 400 || ball2x <= 0){
   	ball2x = 200;
	ball2y = 120;
    }
    
    if(rect1y+100 >= 400){
   	rect1y -= 3;
    }   
	if(rect1y <= 0){
   	rect1y += 3;
    }
	  
	if(rect2y+100 >= 400){
   	rect2y -= 3;
    }   
	if(rect2y <= 0){
   	rect2y += 3;
    }     
 
}

void controls(){
		hidScanInput();

		// Respond to user input
		u32 kHeld = hidKeysHeld();	
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
		printf("START pressed, exitting...");
		shouldrun = 0;
		}
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
}

void drawpong()
{
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
	C2D_DrawRectSolid(rect1x, rect1y, 0, 20, 100, clrWhite);
	C2D_DrawRectSolid(rect2x, rect2y, 0, 20, 100, clrWhite);
	C2D_DrawRectSolid(ballx, bally, 0, 20, 20, clrWhite);
	if(twoball == 1){
	C2D_DrawRectSolid(ball2x, ball2y, 0, 20, 20, clrWhite);
	}
	C2D_DrawRectSolid(200, 0, 0, 20, 240, clrWhite);
}



