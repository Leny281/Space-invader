#ifndef _BALLE_H_
#define _BALLE_H_

#include "type.h"

void avance_tire(bullet *b1,MLV_Image *balle_ennemie);

void activer_balle1(ship *joueur);

void activer_balle2(ship *joueur);

void generation_balle_ennemie(enemy *enemie,int nb_enemie,MLV_Image* balle_ennemi);


    
#endif