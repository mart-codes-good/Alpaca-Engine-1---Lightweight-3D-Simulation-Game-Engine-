#define WIN32_LEAN_AND_MEAN // need to include or wont work
#include <windows.h>

#include "camera.h"
#include <GL/glu.h>
#include <math.h>

void camInit(Camera *cam, float x, float y, float z, float speed, float sens, bool gravity){
    cam -> posX = x;
    cam -> posY = y;
    cam -> posZ = z;

    cam -> angleX = 0.0f;
    cam -> angleY = -30.0f; // I set it to tilted down for testing

    cam -> speed = speed;
    cam -> sensitivity = sens;

    cam->isGravity = gravity;

}

void camProcessInput(Camera *cam, GLFWwindow *window){

    // camera rotation
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        cam->angleX -= cam->sensitivity;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cam->angleX += cam->sensitivity;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && cam->angleY < 89.0f) // to avoid flipping, necks don't move like this anyways
        cam->angleY += cam->sensitivity;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && cam->angleY > -8.0f)
        cam->angleY -= cam->sensitivity;

    float radX = cam->angleX * M_PI / 180.0f; // for radians
    float radY = cam->angleY * M_PI / 180.0f;

    float forwardX = cosf(radY) * sinf(radX);
    float forwardZ = -cosf(radY) * cosf(radX);
    float rightX = sinf(radX - M_PI / 2.0f);
    float rightZ = -cosf(radX - M_PI / 2.0f);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cam->posX += forwardX * cam->speed;
        cam->posZ += forwardZ * cam->speed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cam->posX -= forwardX * cam->speed;
        cam->posZ -= forwardZ * cam->speed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cam->posX += rightX * cam->speed;
        cam->posZ += rightZ * cam->speed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cam->posX -= rightX * cam->speed;
        cam->posZ -= rightZ * cam->speed;
    }

    if(cam->isGravity){
        if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && cam->posY <= 2.0)
            cam->posY += 2.0;
        if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS && cam->posY > 0.0) // i dont know why this works without the > 0 condition but ill put it just in case
            cam->posY -= 1.0;
    }

    if(!cam->isGravity){
        if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            cam->posY += 1.5;
        if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            cam->posY -= 1.5;
    }
};

void camApplyView(Camera *cam){

    float radX = cam->angleX * M_PI / 180.0f;
    float radY = cam->angleY * M_PI / 180.0f;

    float forwardX = cosf(radY) * sinf(radX);
    float forwardY = sinf(radY);
    float forwardZ = -cosf(radY) * cosf(radX);

     gluLookAt(cam->posX, cam->posY, cam->posZ,
              cam->posX + forwardX,
              cam->posY + forwardY,
              cam->posZ + forwardZ,
              0.0, 1.0, 0.0);

}