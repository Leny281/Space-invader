#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<MLV/MLV_all.h>

#include"macros.h"
#include"type.h"
#include"affichage_menu.h"
#include"animations.h"
#include"initialisation.h"
#include"jsave.h"
#include"gerer_menu.h"

void menu(){
    int action_menu;
    int retour = 0;
    int lancer;
    int i = 0;
    int j, k;
    int tmp;
    int action_sauvegarde, nb_joueur = 0, save;
    image liste_images[100];
    int quitter = 0;
    FILE *fichier_score = NULL;
    int classement[MAX_CLASSEMENT];
    char score[100];

    

    init_images(liste_images);
    
    do
    {
        liste_images[VAISSEAU].y = liste_images[VAISSEAU].hauteur;
        afficher_menu(liste_images, TOUT);
        
        action_menu = gerer_bouttons_menu(liste_images);
        
        switch(action_menu){
        case 1 : /* classement */

            fichier_score = fopen("classement.txt", "r");
            
            if (fichier_score == NULL){
                printf("Erreur");
                exit(EXIT_FAILURE);
            }
            i=0;
            while ((i < MAX_CLASSEMENT) && (fscanf(fichier_score, "%d", &classement[i]) == 1)){
                i++;
            }
                        
            fclose(fichier_score);

            for (k=0;k<i-1; k++) {
                for (j=0;j<i-k-1;j++) {
                    if (classement[j] < classement[j+1]) {
                        tmp = classement[j];
                        classement[j] = classement[j+1];
                        classement[j+1] = tmp;
                    }
                }
            }

            retour = afficher_menu_classement(classement, i);
            if (retour == 1)
                break;
            
        case 2 : /* jeu */
            action_sauvegarde = gerer_bouttons_sauvegarde(liste_images);
            switch(action_sauvegarde){
            case 1:
                nb_joueur = gerer_menu_solo_duo(liste_images);
                lancer = 1;
                save = 0;
                break;
            case 2 :
                save = 1;
                lancer = 1;
                break;
            case 3 :
                save = 2;
                lancer = 1;
                break;
            case 4 :
                save = 3;
                lancer = 1;
                break;
            case 5 :
                lancer = 0;
                break;
            default :
                break;
            }
            if (lancer == 1){
                animation_lancer_jeu(liste_images);
                MLV_clear_window(MLV_COLOR_BLACK);
                lancer_jeu(save, nb_joueur);
            }
            if (lancer == 0)
                break;
            
        default :
            break;
        }
    }while(quitter == 0);
        
    MLV_actualise_window();
    MLV_free_window();
    return ;
}


int main(){
    MLV_create_window("menu", "menu", LARGEUR, HAUTEUR);
    menu();
    return 0;

}