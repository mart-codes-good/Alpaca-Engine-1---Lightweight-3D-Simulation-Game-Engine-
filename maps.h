#ifndef MAPS_H
#define MAPS_H
#include "collisionAABB.h"

typedef struct
{
    Box ground;     // Base of entire map, could be a square or a rectangle, etc 
    Box geometry[10];  // All walls or extra geometry that goes on the base (AABB)
    int numGeo;   // to make loop iterations easier
    char *ambience;

}
Map;

void drawPlane(float size);

void testMap1Init(Map *map);

void testMap1Draw(Map * map);

/*
    Maps to implement:
    Skyscrap - Skyscrapper, map where you can fall off. you play on one of the top floors

    void skyScrapInit(Map *map);
    void skyScrapDraw(Map *map);

    Tower - Watch Tower, map with a watch tower in the middle

    void wTowerInit(Map *map);
    void wTowerDraw(Map * map);

*/



#endif