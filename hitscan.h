#ifndef HITSCAN_H
#define HITSCAN_H

#include "collisionAABB.h"
#include "camera.h"
#include <stdbool.h>

typedef struct{
    
    float x, y, z; // this represents the direction vector
    float t; 
}
Ray;

// I don't need to implment the origin since that is the camera

/*

    Equation that supports hitscan
    P(t) = O + tD

    P(t) = a point along hitscan ray
    O is the origin
    D  is a constant direction vector that is parallel to the line.
    t how far along the ray or the "range" of the ray

*/

// Intialize the ray/hitscan
void rayInit(Ray *ray, float x, float y, float z);

// Check if ray hits a target
bool hitscanIsHit(Ray ray, Camera cam, Box box);

#endif 
