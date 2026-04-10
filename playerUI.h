#ifndef PLAYERUI_H
#define PLAYERUI_H
#include <GL/glut.h>

typedef struct 
{
    int hp;
    int ammo;
    int reserve;
}
playerUI;

void playerUiInit(playerUI *pui, int hp, int ammo, int r);

void drawText(float x, float y, const char *text);

void drawPlayerUI(playerUI pui);

#endif