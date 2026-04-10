#include "weapons.h"
#include "camera.h"
#include "hitscan.h"
#include <GLFW/glfw3.h>


void revolverInit(Weapon *revolver){
   
    revolver->type = 'h'; // hitscan
    revolver->dmg = 40.0f;
    revolver->clipSize = 6;
    revolver->reserve = 6 * 4;
    revolver->isGravityWpn = false;
    revolver->criticalHits = true;
    revolver->shootSound = "assets/revolverShootSound.wav";
    revolver->equipSound = "assets/sounds/revolverEquipSound.wav";

}

void hitscanShoot(Weapon wpn, GLFWwindow *window){

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && wpn.clipSize > 0){
        wpn.clipSize -= 1;
        soundPlay(wpn.shootSound);

        /*
            
            if hitscanIsHit && Box is player box && !criticalHit
                player.hp -= revolver.dmg
        
             if hitscanIsHit && Box is player box && criticalHit
                player.hp -= revolver.dmg * 3

        */
    }

}