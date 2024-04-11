#include <MLV/MLV_all.h>
#include "type.h"

void dessine_ship(ship ship,MLV_Image *vaisseau) {
    /* MLV_draw_filled_rectangle(ship.x, ship.y, ship.largeur, ship.longueur, MLV_COLOR_BLUE); */
    if (ship.pv>0){
        MLV_draw_image(vaisseau, ship.x, ship.y);
    }
}




void deplacement1(ship *joueur){
    if (MLV_get_keyboard_state(MLV_KEYBOARD_LEFT) == 0) {
        if (joueur->x > 10) {
            joueur->x -= 7;
        }
    } else if (MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT) == 0) {
        if (joueur->x < LARGEUR - 50) {
            joueur->x += 7;
        }
    }
    
    if (MLV_get_keyboard_state(MLV_KEYBOARD_UP) == 0) {
        if (joueur->y >0 ) {
            joueur->y -= 7;
        }
    } else if (MLV_get_keyboard_state(MLV_KEYBOARD_DOWN) == 0) {
        if (joueur->y < LONGUEUR - 80) {
            joueur->y += 7;
        }
    }


}

void deplacement2(ship *joueur){
    if (MLV_get_keyboard_state(MLV_KEYBOARD_q) == 0) {
        if (joueur->x > 10) {
            joueur->x -= 7;
        }
    } else if (MLV_get_keyboard_state(MLV_KEYBOARD_d) == 0) {
        if (joueur->x < LARGEUR - 50) {
            joueur->x += 7;
        }
    }
    
    if (MLV_get_keyboard_state(MLV_KEYBOARD_z) == 0) {
        if (joueur->y >0 ) {
            joueur->y -= 7;
        }
    } else if (MLV_get_keyboard_state(MLV_KEYBOARD_s) == 0) {
        if (joueur->y < LONGUEUR - 80) {
            joueur->y += 7;
        }
    }



    
}