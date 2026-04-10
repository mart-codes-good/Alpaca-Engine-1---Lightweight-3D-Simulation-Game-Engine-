#include <GL/glut.h>
#include "playerUI.h"
#include <stdio.h>

void playerUiInit(playerUI *pui, int hp, int ammo, int r){
    pui->hp = hp;
    pui->ammo = ammo;
    pui->reserve = r;
}

void drawText(float x, float y, const char *text){ // OPTOMIZE LATER
    glPushMatrix();
    glLoadIdentity();

    // Disable depth so text always shows
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720); // your window size

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1); // white text
    glRasterPos2f(x, y);

    while (*text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);

    // Restore everything
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void drawPlayerUI(playerUI pui){
    char buff[64];

    sprintf(buff, "HP: %d", pui.hp);
    drawText(200, 200, buff); 

    sprintf(buff, "Ammo: %d / %d", pui.ammo, pui.reserve);
    drawText(900, 200, buff); 
}