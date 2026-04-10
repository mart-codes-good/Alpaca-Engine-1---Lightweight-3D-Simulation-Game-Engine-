#ifndef WEAPONS_H
#define WEAPONS_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "sound.h"


/*
hud model
sound
hitscan or projectile
dmg, reserve ammo
fire rate, criticalhits enabled or no
weapon type 
*/

typedef struct{
    
    char type; // h - hitscan, p - projectile, e explosive projectile 
    float dmg;
    int clipSize;
    int reserve;
    bool isGravityWpn; // for projectile weapons, is it affected by gravity 
    bool criticalHits; // random critical hit chance, can be adjusted if guranteed ex: headshotable weapons
    const char *shootSound; // paths to sound files
    const char *equipSound;

}
Weapon;

void revolverInit(Weapon *revolver);

void hitscanShoot(Weapon wpn, GLFWwindow *window);

void rocketLauncherInit(Weapon *RPG);

void projectileShoot(Weapon wpn, GLFWwindow *window);

#endif