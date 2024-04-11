#include <MLV/MLV_all.h>
#include "type.h"

void dessine_enemy(enemy e,MLV_Image *mechant){
    if (e.visible) {
        /* MLV_draw_filled_rectangle(e.x, e.y, e.largeur, e.longueur, MLV_COLOR_YELLOW); */
       
        MLV_draw_image(mechant, e.x, e.y);
    }
}



void cree_enemie_basic(enemy *enemie, int n,int wave) {
    int i, y, ligne,sens;
    y = 80;
    ligne = 0;
    sens = 1;
    for (i = 0; i < n; i++) {
        enemie[i].x = ((i % 6) + 1) * 130; 
        enemie[i].y = y + ligne * 60; 
        enemie[i].largeur = 80;
        enemie[i].longueur = 80;
        enemie[i].pv = 1;
        enemie[i].visible = 1;
        enemie[i].sens_deplacement = sens;
        enemie[i].balle.lancer = 0;
        enemie[i].point = 20;
        enemie[i].vitesse = 5+wave;

        if ((i + 1) % 6 == 0) {
            ligne++;
            sens*= -1;
        }
    }
}




void cree_enemie_invisible(enemy *enemie, int n) {
    int i;
    for (i = 0; i < n; i++) {
        enemie[i].largeur = 80;
        enemie[i].longueur = 80;
        enemie[i].visible = 0;
        enemie[i].pv = 0;
    }
}


void dessine_ennemie(enemy *enemie, int nb_enemie,MLV_Image *mechant) {
    int i;
    for (i = 0; i < nb_enemie; i++) {
        dessine_enemy(enemie[i],mechant);
    }
}


void deplacement_ennemie(enemy *enemie,int nb_enemie){
    int i;
    for (i = 0; i < nb_enemie; i++) {
        if (enemie[i].visible) {
                
            /* Mettez à jour la position des ennemis en fonction du sens_deplacement */
            enemie[i].x += enemie[i].vitesse * enemie[i].sens_deplacement;
                
            /* Changez le sens_deplacement si l'ennemi atteint les bords de l'écran */
            if (enemie[i].x >= LARGEUR || enemie[i].x <= -60) {
                enemie[i].y += 60;
                enemie[i].sens_deplacement *= -1;
            }
        }
    }
    
}


int tout_ennemie_mort(enemy enemie[],int nb_enemie){
    int i,vivant;
    vivant=0;
    for (i=0;i<=nb_enemie-1;i++){
        if (enemie[i].pv!=0){
            vivant +=1;
        }
    }
    return vivant; 

}
