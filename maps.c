#include "maps.h"
#include "sound.h"
#include <GL/gl.h>
#include <stdio.h>
#include <AL/al.h>



void drawPlane(float size){

    float half = size / 2.0;

    glColor3f(0.2, 0.5, 0.2);
    glBegin(GL_QUADS);
        glVertex3f(-half, 0.0, -half);
        glVertex3f(half, 0.0, -half);
        glVertex3f(half, 0.0, half);
        glVertex3f(-half, 0.0, half);

    glEnd();

     // Collision box for testing plane
    Box plane;
    boxInit(&plane, -15, 15, -0.1, 0, -15, 15);

}

void testMap1Init(Map *map) {
    // Ground plane collision 
    boxInit(&map->ground, -30, 30, -0.1, 0, -30, 30);

    // Example wall
    boxInit(&map->geometry[0], -2, 2, 0, 3, -5, -4);
    map->numGeo = 1;

    printf("testMap1Init: loading ambience...\n");
    alGetError(); // clear any prior OpenAL errors
    soundPlay("assets/sounds/revolverShootSound.wav");
    ALenum err = alGetError();
    if (err != AL_NO_ERROR) {
        printf("OpenAL error after soundPlay: %d\n", err);
    }
    printf("testMap1Init: soundPlay called!\n");

    
}

void testMap1Draw(Map *map) {
    // Draw ground 
    glColor3f(0.2f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
        glVertex3f(-30, 0.0f, -30);
        glVertex3f( 30, 0.0f, -30);
        glVertex3f( 30, 0.0f,  30);
        glVertex3f(-30, 0.0f,  30);
    glEnd();

    // Draw walls as simple cubes or quads
    glColor3f(0.6f, 0.4f, 0.2f);
    for (int i = 0; i < map->numGeo; i++) {
        Box w = map->geometry[i];
        glBegin(GL_QUADS);
            glVertex3f(w.minX, w.minY, w.minZ);
            glVertex3f(w.maxX, w.minY, w.minZ);
            glVertex3f(w.maxX, w.maxY, w.minZ);
            glVertex3f(w.minX, w.maxY, w.minZ);
        glEnd();
    }
}
