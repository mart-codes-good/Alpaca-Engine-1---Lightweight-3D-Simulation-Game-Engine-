#ifndef COLLISIONAABB_H
#define COLLISIONAABB_H

#include <stdbool.h>

typedef struct 
{
    float minX, maxX; 
    float minY, maxY;
    float minZ, maxZ;
}
Box;

// Create a Box struct which holds all the data needed to make the collison Box and the box in OpenGl
void boxInit(Box *box, float x1, float x2, float y1, float y2, float z1, float z2);

// Check for collison by comparing points
bool isCollide(Box a, Box b);

#endif