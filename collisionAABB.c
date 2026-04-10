#include "collisionAABB.h"
#include <stdbool.h>

void boxInit(Box *box, float x1, float x2, float y1, float y2, float z1, float z2){
    box -> minX = x1;
    box -> maxX = x2;
    box -> minY = y1;
    box -> maxY = y2;
    box -> minZ = z1;
    box -> maxZ = z2;

}

// check if a and b collide
bool isCollide(Box a, Box b){
    return (a.minX <= b.maxX && a.maxX >= b.minX) &&
           (a.minY <= b.maxY && a.maxY >= b.minY) &&
           (a.minZ <= b.maxZ && a.maxZ >= b.minZ);
}

/*
Check if a1 is less than b1 and a1 is less than b2, 
if true then the lines from a1->a2 and b1->b2 are not touching

(a.minX < b.minX && a.maxX < b.maxX)

Now apply this to all planes

(a.minX < b.minX && a.maxX > b.maxX) &&
(a.minY < b.minY && a.maxY > b.maxY) &&
(a.minZ < b.minZ && a.maxZ > b.maxZ) 

This way we check if all planes collide or not, by getting true or false

*/