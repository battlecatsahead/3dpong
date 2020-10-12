#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
struct gfx_configuration
{
   bool pong;
   bool snake;
};
void display_menu(struct gfx_configuration *config);
extern bool menupause;
extern bool pongon;
extern int shouldrun;
#endif

