#include <GL/glew.h> // window, input, OpenGL functions
#include <GLFW/glfw3.h> // modern OpenGL functons
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "camera.h"
#include "collisionAABB.h"
#include "playerUI.h"
#include "maps.h"
#include "weapons.h"

void updatePlayerPosition(Box *playerBox, Camera *cam){
    playerBox->minX = cam->posX - 0.3f;
    playerBox->maxX = cam->posX + 0.3f;
    playerBox->minY = cam->posY - 2.0f;
    playerBox->maxY = cam->posY;
    playerBox->minZ = cam->posZ - 0.3f;
    playerBox->maxZ = cam->posZ + 0.3f;
}

int main(void){

    if (!glfwInit()) {
        printf("GLFW init failed!\n");
        return -1;
    }
    // Creates a windown
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Collision and FP Camera engine", NULL, NULL);

    if (!window) {
        printf("Window creation failed!\n");
        return -1;
    }

    glfwMakeContextCurrent(window); // Tell OpenGL to draw inside window
    glewInit();

    if (glewInit() != GLEW_OK) {
        printf("GLEW init failed!\n");
        return -1;
    }

    // Initialize sound system once
    Sound globalSound;
    soundInit(&globalSound);


    // Initialize GLUT (needed for text rendering) OR ELSE WINDOW WILL CLOSE ITSELF RIGHT AFTER OPENING
    int argc = 1;
    char *argv[1] = { (char*)"App" };
    glutInit(&argc, argv);

    // Initialize player FP camera
    Camera cam;
    camInit(&cam, 0.0f, 2.0f, 5.0f, 0.1f, 1.5f, true);

    // Intialize player UI, stores hp and ammo
    playerUI playerUI;
    playerUiInit(&playerUI, 200, 4, 20); 

    // Also make the players collision/hitbox
    Box playerBox;
    boxInit(&playerBox,
        cam.posX - 0.3f, cam.posX + 0.3f,   // X: left to right
        cam.posY - 2.0f, cam.posY,          // Y: bottom to top (2 units tall)
        cam.posZ - 0.3f, cam.posZ + 0.3f    // Z: front to back
    );

    glEnable(GL_DEPTH_TEST);

    // Set the background color (dark blue-gray)
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

    // Intialize revolver to test
    Weapon primary;
    revolverInit(&primary);

    Map map1;
    testMap1Init(&map1);

     while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, 1280.0 / 720, 0.1, 100); // DONT TOUCH THIS MARTIN, THIS SHOULD NEVER CHANGE

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        updatePlayerPosition(&playerBox, &cam); // move player cam with collision/hitbox

        if(cam.isGravity) // makes you fall after jumping, resets y pos
            cam.posY -= 0.05;  
        if(isCollide(playerBox, map1.ground)){
            cam.posY = map1.ground.maxY + 2.0;
        }
        
        hitscanShoot(primary, window);
        camProcessInput(&cam, window);
        camApplyView(&cam); // must go before anything is drawn

        testMap1Draw(&map1); // map draw has to go before UI 
        drawPlayerUI(playerUI); 

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleans up memoery and closes everything properly
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}