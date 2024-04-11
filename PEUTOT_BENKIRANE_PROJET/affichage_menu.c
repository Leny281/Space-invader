#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>

#include"type.h"
#include"macros.h"

#define LARGEUR 900
#define HAUTEUR 900
#define MAX 1024

void afficher_menu(image liste[], int boutton/*0 pour l'affichage par default, 1 pour la coupe, 2 pour jouer, 3 pour l'affichage sans bouttons*/){ 
    MLV_draw_image(liste[ESPACE].mlv, liste[ESPACE].x, liste[ESPACE].y);
    MLV_draw_image(liste[ESPACE_C].mlv, liste[ESPACE_C].x, liste[ESPACE_C].y);
    MLV_draw_image(liste[MONTAGNE].mlv, liste[MONTAGNE].x, liste[MONTAGNE].y);
    MLV_draw_image(liste[VAISSEAU].mlv, liste[VAISSEAU].x, liste[VAISSEAU].y);
    MLV_draw_image(liste[TITRE].mlv, liste[TITRE].x, liste[TITRE].y);
    switch(boutton){
    case 1 :
        MLV_draw_image(liste[COUPE_S].mlv, liste[COUPE_S].x, liste[COUPE_S].y);
        MLV_draw_image(liste[PLAY].mlv, liste[PLAY].x, liste[PLAY].y);
        break;
        
    case 2 :
        MLV_draw_image(liste[PLAY_S].mlv, liste[PLAY_S].x, liste[PLAY_S].y);
        MLV_draw_image(liste[COUPE].mlv, liste[COUPE].x, liste[COUPE].y);
        break;
        
    case 3:
        break;
        
    default :
        MLV_draw_image(liste[PLAY].mlv, liste[PLAY].x, liste[PLAY].y);
        MLV_draw_image(liste[COUPE].mlv, liste[COUPE].x, liste[COUPE].y);
        break;
    }
}

void afficher_menu_sauvegarde(){
    MLV_Font* font;
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 50);

    MLV_draw_filled_rectangle(0, 0, LARGEUR, HAUTEUR, MLV_rgba(128, 128, 128, 100));

    MLV_draw_text_box_with_font(LARGEUR/2-(LARGEUR/4.4), HAUTEUR/2-(HAUTEUR/3.2), LARGEUR/2.2, HAUTEUR/8, "NOUVELLE PARTIE", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);
    
    MLV_draw_text_box_with_font(LARGEUR/3-(LARGEUR/4.4), HAUTEUR/2-(HAUTEUR/18), LARGEUR/3, HAUTEUR/8, "SAUVEGARDE 1", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_draw_text_box_with_font(LARGEUR/1.8, HAUTEUR/2-(HAUTEUR/18), LARGEUR/3, HAUTEUR/8, "SAUVEGRADE 2", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_draw_text_box_with_font(LARGEUR/2-(LARGEUR/6), HAUTEUR/1.7, LARGEUR/3, HAUTEUR/8, "SAUVEGRADE 3", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_draw_text_box_with_font(LARGEUR/2-(LARGEUR/11), HAUTEUR/1.2, LARGEUR/5.5, HAUTEUR/10, "RETOUR", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_free_font(font);
}

void afficher_menu_solo_duo(){
    MLV_Font* font;
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 50);

    MLV_draw_filled_rectangle(0, 0, LARGEUR, HAUTEUR, MLV_rgba(128, 128, 128, 100));
    
    MLV_draw_text_box_with_font(LARGEUR/3-LARGEUR/8, HAUTEUR/3, LARGEUR/4, HAUTEUR/8, "SOLO", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_draw_text_box_with_font(LARGEUR/1.8, HAUTEUR/3, LARGEUR/4, HAUTEUR/8, "DUO", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);

    MLV_free_font(font);
}

void afficher_menu_fin_partie(){
    MLV_Font* font;
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 50);
    
    MLV_draw_filled_rectangle(0, 0, LARGEUR, HAUTEUR, MLV_rgba(128, 128, 128, 100));
    
    MLV_draw_text_box_with_font(LARGEUR/2-LARGEUR/3, HAUTEUR/3, LARGEUR/1.5, HAUTEUR/8, "ENREGISTRER LE SCORE", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);
    
    MLV_draw_text_box_with_font(LARGEUR/2-LARGEUR/4, HAUTEUR/3+20+HAUTEUR/8, LARGEUR/2, HAUTEUR/8, "RETOUR AU MENU", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);
    
    MLV_actualise_window();
    
    MLV_free_font(font);
}

int afficher_menu_classement(int classement[], int nb_joueur){
    int x, y;
    MLV_Font* font;
    int i = 0;
    int decalage = 0;
    int score;
    char score_c[10];
    
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 50);
    
    MLV_draw_filled_rectangle(0, 0, LARGEUR, HAUTEUR, MLV_rgba(128, 128, 128, 100));

    
    if(nb_joueur > 0){
        
        if (nb_joueur > 10)
            nb_joueur = 10;
    
        for (i=0;i<nb_joueur;i++){
            score = classement[i];
            sprintf(score_c, "%d", score);
        
            MLV_draw_filled_rectangle(LARGEUR/2-LARGEUR/6, HAUTEUR/20+decalage, LARGEUR/3, HAUTEUR/14, MLV_COLOR_ORANGE);
            MLV_draw_rectangle(LARGEUR/2-LARGEUR/6, HAUTEUR/20+decalage, LARGEUR/3, HAUTEUR/14, MLV_COLOR_BLACK);
        
            MLV_draw_text_box_with_font(LARGEUR/2-LARGEUR/6+1, HAUTEUR/20+decalage+1, LARGEUR/3-2, HAUTEUR/14-2, score_c, font, 50, MLV_COLOR_ORANGE, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);
          
            MLV_actualise_window();
        
            decalage += HAUTEUR/14 + 10;
        }
    }
    
    MLV_draw_text_box_with_font(LARGEUR/2-LARGEUR/8, HAUTEUR/20+decalage, LARGEUR/4, HAUTEUR/14, "RETOUR", font, 50, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_ORANGE, MLV_TEXT_LEFT, MLV_TEXT_CENTER, MLV_TEXT_CENTER, MLV_TEXT_CENTER);
    
    MLV_actualise_window();
    
    MLV_wait_mouse(&x, &y);
    
    if(x>LARGEUR/2-(LARGEUR/1.5-2)/4 &&
       x<LARGEUR/2+(LARGEUR/1.5-2)/4 &&
       y>HAUTEUR/20+decalage+1 &&
       y<HAUTEUR/20+decalage+1+HAUTEUR/14-2
        )
        return 1;
    
    return 0;
}
