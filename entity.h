/*
    Some notes about entities:
    An Entity is basically any object in the world:
        A player
        An enemy
        A prop or pickup
        Even a projectile

    They all share some common data:
        position (Vec3 pos)
        rotation (Vec3 rot)
        collider (Box collider)
        state (active, health, etc.)

    Components to inplement:
        the struct (fields),
        the list that stores all entities,
        additional list to hold only players (hitscan for loop? scoreboard?), 
        helper functions to create, update, and remove entities.
*/

#ifndef ENTITY_H
#define ENTITY_H

#ifndef MAX_ENTITIES
#define MAX_ENTITIES 512 // Max entities is set to 2^9, if scale up move to 2^10, 2^11....
#endif

#include "vectors.h"
#include "collisionAABB.h"

typedef struct{
    vec3 pos;
    vec3 rot;
    Box collider;
    int health;
    int active; // 0 inactive, 1 alive, 2 dying, 4 frozen
    char *name;
}
Entity;

/*
    extern says There’s a real entities array defined in another .c file — I just want to use it.
    Without extern, each .c file that 
    includes your header would create its own separate copy of entities
    With extern, all files share one instance defined in entity.c.
*/
extern Entity entities[MAX_ENTITIES];

Entity createEntity(vec3 pos, vec3 rot, Box collider, int health, int active, char *name);
void updateEntities();

#endif