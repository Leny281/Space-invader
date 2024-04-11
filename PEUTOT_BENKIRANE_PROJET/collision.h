#ifndef _COLLISION_H
#define _COLLISION_H_

void verif_ennemie_toucher(bullet *b1,enemy *enemie,int nb_enemie,int *score);

void verif_joueur_toucher(ship *joueur,enemy *enemie,int nb_enemie);

void ennemie_atteint_sol(ship *joueur1,ship *joueur2,enemy *ennemie,partie game);
void colision_joueur_ennemie(ship *vaisseau,enemy *ennemie,partie game);
#endif