#include "model.h"
#include "camera.h"
#include <GL/gl.h>
#include <math.h>


void modelInit(Model *m, vec3 scale, vec3 offset){
    m->scale = scale;
    m->offset = offset;
    m->loaded = 1;
    m->path = NULL;
}

// Draw the bean for player enemy, living enitity placeholder
void modelDrawBean(){
    const int slices = 16;
    const float r = 0.3f, h = 1.2f;

    // cylinder body
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * M_PI;
        float x = cosf(a) * r, z = sinf(a) * r;
        glVertex3f(x, -h/2, z);
        glVertex3f(x,  h/2, z);
    }
    glEnd();

    // simple caps (flat disks for now)
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * M_PI;
        glVertex3f(cosf(a)*r,  h/2, sinf(a)*r);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= slices; i++) {
        float a = (float)i / slices * 2.0f * M_PI;
        glVertex3f(cosf(a)*r, -h/2, sinf(a)*r);
    }
    glEnd();
}