#include <MLV/MLV_all.h>
#include "type.h"


void avance_tire(bullet *b1,MLV_Image *balle_joueur){
    if (b1->lancer == 1) {
        if (b1->y < 0) {
            b1->lancer = 0;
        } else {
            b1->y -= 15;
            /* MLV_draw_filled_rectangle(b1->x, b1->y, 5, 40, MLV_COLOR_GREEN); */
            MLV_draw_image(balle_joueur,b1->x,b1->y);
        }
        
    }
}


void activer_balle1(ship *joueur){
    if (MLV_get_keyboard_state(MLV_KEYBOARD_m) == 0) {
        if (joueur->b1.lancer == 0) {
            joueur->b1.x = joueur->x + 20;
            joueur->b1.y = joueur->y - 30;
            joueur->b1.lancer = 1;
        }
    }

}

void activer_balle2(ship *joueur){
    if (MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == 0) {
        if (joueur->b1.lancer == 0) {
            joueur->b1.x = joueur->x + 20;
            joueur->b1.y = joueur->y - 30;
            joueur->b1.lancer = 1;
        }
    }

}





void generation_balle_ennemie(enemy *enemie,int nb_enemie,MLV_Image *balle_ennemie){
    int i;
    for (i=0;i<nb_enemie;i++){
        if (enemie[i].visible ==1){
            if ((rand() % 3 + 1)==3){
                if (enemie[i].balle.lancer == 0) {
                    enemie[i].balle.x = enemie[i].x + 20;
                    enemie[i].balle.y = enemie[i].y + 30;
                    enemie[i].balle.lancer = 1;
                        
                }
            }
        }
        if (enemie[i].balle.lancer == 1) {
            if (enemie[i].balle.y > LONGUEUR ) {
                enemie[i].balle.lancer = 0;
            } else {
                enemie[i].balle.y += 6;
                MLV_draw_image(balle_ennemie,enemie[i].balle.x,enemie[i].balle.y);
                /* MLV_draw_filled_rectangle(enemie[i].balle.x,enemie[i].balle.y, 5, 40, MLV_COLOR_BLUE); */
            }
        }
    }


}