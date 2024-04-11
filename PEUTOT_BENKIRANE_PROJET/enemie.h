#ifndef _ENEMIE_H_
#define _ENEMIE_H_

#include "type.h"

void dessine_enemy(enemy e,MLV_Image *mechant);

void cree_enemie_basic(enemy *enemie, int n,int wave) ;

void cree_enemie_invisible(enemy *enemie, int n);

void dessine_ennemie(enemy *enemie, int nb_enemie,MLV_Image *mechant);


void deplacement_ennemie(enemy *enemie,int nb_enemie);

int tout_ennemie_mort(enemy enemie[],int nb_enemie);

#endif