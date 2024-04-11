#include <MLV/MLV_all.h>
#include "type.h"

/*-------------------------verifie si lenemie est touche par la balle du joueur--------------------------*/


void verif_ennemie_toucher(bullet *b1,enemy *enemie,int nb_enemie,int *score){
    int i;
    for (i = 0; i < nb_enemie; i++) {
            
        if (enemie[i].visible && b1->lancer &&
            b1->x >= enemie[i].x && b1->x <= (enemie[i].x + enemie[i].largeur) &&
            b1->y >= enemie[i].y && b1->y <= (enemie[i].y + enemie[i].longueur)) {
            b1->lancer = 0;
            enemie[i].pv--;
            if (enemie[i].pv == 0) {
                enemie[i].visible = 0;
                *score += enemie[i].point;
            }
        }
    }
}




/*-------------verifie si le joueur est toucher par une des balles enemies--------------- */


void verif_joueur_toucher(ship *joueur,enemy *enemie,int nb_enemie){
    int i;
    for (i = 0; i < nb_enemie; i++) {
            
        if (enemie[i].balle.x >= joueur->x && enemie[i].balle.x<= (joueur->x + joueur->largeur) &&
            enemie[i].balle.y>= joueur->y && enemie[i].balle.y <= (joueur->y + joueur->longueur) && enemie[i].balle.lancer== 1 ) {
            enemie[i].balle.lancer = 0;
            joueur->pv--;
        }
    }

}

void colision_joueur_ennemie(ship *vaisseau,enemy *ennemie,partie game){
    int i=0;
    for (i=0;i<game.nb_enemie;i++){
        if ((ennemie[i].pv>0) &&(vaisseau->x < ennemie[i].x + ennemie[i].largeur) &&
            (vaisseau->x + vaisseau->largeur > ennemie[i].x) &&
            (vaisseau->y < ennemie[i].y +ennemie[i].longueur) &&
            (vaisseau->y + vaisseau->longueur > ennemie[i].y))
        {
            vaisseau->pv-=1;
            ennemie[i].pv-=1;
            ennemie[i].visible=0;
        }

    }
}



void ennemie_atteint_sol(ship *joueur1,ship *joueur2,enemy *ennemie,partie game){
    int i=0;
    for (i=0;i<game.nb_enemie;i++){
        if ((ennemie[i].pv>0) && ennemie[i].y>=LONGUEUR)
        {
            joueur1->pv-=1;
            joueur2->pv-=1;
            ennemie[i].pv-=1;
            ennemie[i].visible=0;
        }

    }


}