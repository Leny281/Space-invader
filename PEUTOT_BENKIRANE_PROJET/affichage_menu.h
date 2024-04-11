#ifndef _AFFICHAGE_MENU_H_
#define _AFFICHAGE_MENU_H_

void afficher_menu(image liste[], int boutton/*0 pour l'affichage par default, 1 pour la coupe, 2 pour jouer, 3 pour l'affichage sans bouttons*/);
void afficher_menu_sauvegarde();
void afficher_menu_solo_duo();
void afficher_menu_fin_partie();
int afficher_menu_classement(int classement[], int nb_joueur);

#endif
