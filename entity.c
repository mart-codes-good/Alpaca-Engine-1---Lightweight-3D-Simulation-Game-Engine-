#include "entity.h"

Entity entities[MAX_ENTITIES];

Entity createEntity(vec3 pos, vec3 rot, Box collider, int health, int active, char *name){
    for(int i = 0; i < MAX_ENTITIES; i ++){ // if not active make new entity/overwrite for new entity, 
        // no need to set all to null manually after an entity is set to 0
        if(entities[i].active == 0){
            entities[i].pos = pos;
            entities[i].rot = rot;
            entities[i].collider = collider;
            entities[i].health = health;
            entities[i].active = active;
            entities[i].name = name;
        }
        return entities[i];
    }

}
/*
    the function loops through the pool just to find the first 
    free slot (inactive entity) to reuse. It doesn’t “create multiple things”; 
    it just searches for the first open space, fills it in, and returns it.
    Easy deletion: just set active = 0 to free a slot.
    Can't create an entity and then just add it to list since C doesnt have arraylist
*/

void updateEntities(){

    // Loop through all entities and apply updates
    for(int i = 0; i < MAX_ENTITIES; i ++){
        
        Entity *e = &entities[i]; // using a pointer to give myself easier time to write updates

        if(e->active == 0)
            continue; // if entites is unactive skip update

        if(e->active == 4)
            continue; // if entity is in frozen state, skip too (can be used for timestop, stun condition etc)

        // Here I write updates for all active/living entities

        // update collider with camera to move position

        // gravity

        // collision with world/current map

        // handle entity health, update damage taken/healed

        // handle entity deaths
       
        // handle shooting

    }
    
}