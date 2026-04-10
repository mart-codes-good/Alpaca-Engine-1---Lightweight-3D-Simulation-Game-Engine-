#include "hitscan.h"
#include "camera.h"
#include "collisionAABB.h"

// Intialize the ray/hitscan
void rayInit(Ray *ray, float x, float y, float z){
    ray->x = x;
    ray->y = y;
    ray->z = z;
}

// Check if ray hits a target
bool hitscanIsHit(Ray ray, Camera cam, Box box){
    
    // Find where the ray crosses the box on the X axis
    // tx1 = entry, tx2 = exit (swap if direction is negative)
    float tx1 = (box.minX - cam.posX) / ray.x;
    float tx2 = (box.maxX - cam.posX) / ray.x;
    if (tx1 > tx2) { float swap = tx1; tx1 = tx2; tx2 = swap; }

    // same for y and z plane
    float ty1 = (box.minY - cam.posY) / ray.y;
    float ty2 = (box.maxY - cam.posY) / ray.y;
    if (ty1 > ty2) { float swap = ty1; ty1 = ty2; ty2 = swap; }

    float tz1 = (box.minZ - cam.posZ) / ray.z;
    float tz2 = (box.maxZ - cam.posZ) / ray.z;
    if (tz1 > tz2) { float swap = tz1; tz1 = tz2; tz2 = swap; }

   // Find where ray actually enters and exits the box, where all 3 axes overlap
    float tEnter = tx1;
    if (ty1 > tEnter) tEnter = ty1;
    if (tz1 > tEnter) tEnter = tz1;

    float tExit = tx2;
    if (ty2 < tExit) tExit = ty2;
    if (tz2 < tExit) tExit = tz2;

    // Ray hits if entry happens before exit and IF in front of camera
    return (tExit >= tEnter && tExit > 0.0f);

}