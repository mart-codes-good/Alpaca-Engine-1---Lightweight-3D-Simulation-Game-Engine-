#ifndef CAMERA_H
#define CAMERA_H

#ifndef M_PI
#define M_PI 3.14159265358979323846 // since my C compiler doesnt have M_PI apparently, why doesnt my math.c have pi?
#endif

#include <GLFW/glfw3.h>
#include <stdbool.h>

typedef struct
{
    float posX, posY, posZ; // actual movement 
    float angleX, angleY; // yaw and pitch, moving head
    float speed; // movement speed
    float sensitivity; // well, sensitivity
    bool isGravity;
}
Camera;

// Intializes a camera
void camInit(Camera *cam, float x, float y, float z, float speed, float sensitivity, bool isGravity);

// Handles keyboard input to update cam position and angles
void camProcessInput(Camera *cam, GLFWwindow *window);

// Applies and makes them visible using gluLookAt
void camApplyView(Camera *cam);

#endif