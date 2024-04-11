#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>

#include"macros.h"
#include"type.h"
#include"affichage_menu.h"
#include"animations.h"


/*
Prend en entrée les différentes images en format MLV et structure ainisi que les variables nécessaire à l'affichage du menu.
Gère les interactions avec le menu (boutton jouer, calssement, etc.)
Renvoie 1 si le boutton classement est clické, 2 si le boutton paramètre est clické, 3 si le boutton jouer est clické.
*/
int gerer_bouttons_menu(image liste[]){
    int x_souris, y_souris;
    int cas=0;
    int compteur_cycle=1;
    MLV_Event event=0;
    
    MLV_actualise_window();

    do{
        event = MLV_get_event( 
            NULL, NULL, NULL,
            NULL, NULL,
            &x_souris, &y_souris, NULL,
            NULL
            );

        compteur_cycle=animation_fond_menu(liste, (compteur_cycle+1), 0);
   
        
        if(x_souris>liste[COUPE].x &&
           x_souris<liste[COUPE].x+liste[COUPE].largeur &&
           y_souris>liste[COUPE].y &&
           y_souris<liste[COUPE].y+liste[COUPE].hauteur)
            cas = 1; /*la souris est sur le boutton coupe*/
        
        
        if(x_souris>liste[PLAY].x &&
           x_souris<liste[PLAY].x+liste[PLAY].largeur &&
           y_souris>liste[PLAY].y &&
           y_souris<liste[PLAY].y+liste[PLAY].hauteur)
            cas = 2; /*la souris est sur le boutton jouer*/ 
        
        switch(cas){
        case 1:
            afficher_menu(liste, CLASSEMENT);
            if(event==MLV_MOUSE_BUTTON)
                return 1;
            if (!(x_souris>liste[COUPE].x &&
                  x_souris<liste[COUPE].x+liste[COUPE].largeur &&
                  y_souris>liste[COUPE].y &&
                  y_souris<liste[COUPE].y+liste[COUPE].hauteur))
                cas = 0; /*la souris n'est plus sur le boutton*/
            break;
            
        case 2:
            afficher_menu(liste, JOUER);
            if(event==MLV_MOUSE_BUTTON)
                return 2;
            if(!(x_souris>liste[PLAY].x &&
                 x_souris<liste[PLAY].x+liste[PLAY].largeur &&
                 y_souris>liste[PLAY].y && 
                 y_souris<liste[PLAY].y+liste[PLAY].hauteur))
                cas = 0; /*la souris n'est plus sur le boutton*/
            break;
            
        default:
            afficher_menu(liste, TOUT);
            break;
        }
        MLV_actualise_window();
        
    }while(1);
    
    MLV_actualise_window();
    
    return 0;
}


int gerer_menu_solo_duo(image liste[]){
    int x_souris, y_souris;
    int cas=0;
    int compteur_cycle=1;
    MLV_Event event=0;
    
    do{
        event = MLV_get_event( 
            NULL, NULL, NULL,
            NULL, NULL,
            &x_souris, &y_souris, NULL,
            NULL
            );
        compteur_cycle=animation_fond_menu(liste, (compteur_cycle+5), 1);
        afficher_menu_solo_duo(liste, TOUT);

        if (x_souris>LARGEUR/3-(LARGEUR/8) &&
            x_souris<LARGEUR/3-(LARGEUR/8) + LARGEUR/4 &&
            y_souris>HAUTEUR/3 &&
            y_souris<HAUTEUR/3 + HAUTEUR/8
            )
            cas = 1;
        
        if (x_souris>LARGEUR/1.8 &&
            x_souris<LARGEUR/1.8 + LARGEUR/4 &&
            y_souris>HAUTEUR/3 &&
            y_souris<HAUTEUR/3 + HAUTEUR/8
            )
            cas = 2;
        
        switch(cas){
        case 1 :
            if(event==MLV_MOUSE_BUTTON)
                return 1;
            if (!(x_souris>LARGEUR/3-(LARGEUR/8) &&
                  x_souris<LARGEUR/3-(LARGEUR/8) + LARGEUR/4 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2) + HAUTEUR/8
                    ))
                cas = 0; /*la souris n'est plus sur le boutton*/
            break;
        case 2 :
            if(event==MLV_MOUSE_BUTTON)
                return 2;
            if (!(x_souris>LARGEUR/1.75-(LARGEUR/8) &&
                  x_souris<LARGEUR/1.75-(LARGEUR/8) + LARGEUR/4 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2) + HAUTEUR/8
                    ))
                cas = 0; /*la souris n'est plus sur le boutton*/
            break;
        default :
            break;
        }
        MLV_actualise_window();
    }while(1);
}

    
int gerer_bouttons_sauvegarde(image liste []){
    int x_souris, y_souris;
    int cas=0;
    int compteur_cycle=1;
    MLV_Event event=0;
    
    MLV_actualise_window();
    
    do{
        event = MLV_get_event( 
            NULL, NULL, NULL,
            NULL, NULL,
            &x_souris, &y_souris, NULL,
            NULL
            );

        compteur_cycle=animation_fond_menu(liste, (compteur_cycle+5), 1);
        afficher_menu_sauvegarde();
        
        if(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
           x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
           y_souris>HAUTEUR/2-(HAUTEUR/3.2) &&
           y_souris<HAUTEUR/2-(HAUTEUR/3.2) + HAUTEUR/8
            )
            cas = 1; /* Nouvelle partie */
        
        
        if(x_souris>LARGEUR/3-(LARGEUR/4.4) &&
           x_souris<LARGEUR/3-(LARGEUR/4.4) + LARGEUR/2.2 &&
           y_souris>HAUTEUR/2-(HAUTEUR/18) &&
           y_souris<HAUTEUR/2-(HAUTEUR/18) + HAUTEUR/8
            )
            cas = 2; /* Sauvergarde 1 */

        
        if(x_souris>LARGEUR/1.8 &&
           x_souris<LARGEUR/1.8 + LARGEUR/2.2 &&
           y_souris>HAUTEUR/2-(HAUTEUR/18) &&
           y_souris<HAUTEUR/2-(HAUTEUR/18) + HAUTEUR/8
            )
            cas = 3; /* Sauvegarde 2 */

        
        if(x_souris>LARGEUR/2-(LARGEUR/6) &&
           x_souris<LARGEUR/2-(LARGEUR/6) + LARGEUR/2.2 &&
           y_souris>HAUTEUR/1.7 &&
           y_souris<HAUTEUR/1.7 + HAUTEUR/8
            )
            cas = 4; /* Sauvegarde 3 */

        
        if(x_souris>LARGEUR/2-(LARGEUR/11) &&
           x_souris<LARGEUR/2-(LARGEUR/11) + LARGEUR/5.5 &&
           y_souris>HAUTEUR/1.2 &&
           y_souris<HAUTEUR/1.2 + HAUTEUR/10
            )
            cas = 5; /* Retour */ 

        
        switch(cas){
        case 1:
            if(event==MLV_MOUSE_BUTTON)
                return 1;
                        
            if (!(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
                  x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2) + HAUTEUR/8
                    ))
                cas = 0; /*la souris n'est plus sur le boutton*/
            
            break;


        case 2:            
            if(event==MLV_MOUSE_BUTTON)
                return 2;
            
            if (!(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
                  x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2)+5+HAUTEUR/8 &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2)+5+HAUTEUR/8 + HAUTEUR/8)
                )
                cas = 0; /*la souris n'est plus sur le boutton*/
            break;

        case 3:
            if(event==MLV_MOUSE_BUTTON)
                return 3;
                        
            if (!(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
                  x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2)+2*(5+HAUTEUR/8) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2)+2*(5+HAUTEUR/8) + HAUTEUR/8)
                )
                cas = 0; /*la souris n'est plus sur le boutton*/
            
            break;
            
        case 4:
            if(event==MLV_MOUSE_BUTTON)
                return 4;
                        
            if (!(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
                  x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2)+3*(5+HAUTEUR/8) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2)+3*(5+HAUTEUR/8) + HAUTEUR/8)
                )
                cas = 0; /*la souris n'est plus sur le boutton*/
            
            break;

        case 5:
            if(event==MLV_MOUSE_BUTTON)
                return 5;
                        
            if (!(x_souris>LARGEUR/2-(LARGEUR/4.4) &&
                  x_souris<LARGEUR/2-(LARGEUR/4.4) + LARGEUR/2.2 &&
                  y_souris>HAUTEUR/2-(HAUTEUR/3.2)+4*(5+HAUTEUR/8) &&
                  y_souris<HAUTEUR/2-(HAUTEUR/3.2)+4*(5+HAUTEUR/8) + HAUTEUR/8)
                )
                cas = 0; /*la souris n'est plus sur le boutton*/
            
            break;
            
        default:
            break;
        }
        MLV_actualise_window();
        
    }while(1);      
}

int gerer_menu_fin_partie(){
    int x_souris, y_souris;
    int cas=0;

    MLV_wait_mouse(&x_souris, &y_souris);

    if (x_souris>LARGEUR/2-LARGEUR/3 &&
        x_souris<LARGEUR/2 + LARGEUR/1.5 &&
        y_souris>HAUTEUR/3 &&
        y_souris<HAUTEUR/3 + HAUTEUR/8
        )
        cas = 1;
    
    if (x_souris>LARGEUR/2-LARGEUR/4 &&
        x_souris<LARGEUR/2 + LARGEUR/4 &&
        y_souris>HAUTEUR/3+20+HAUTEUR/8 &&
        y_souris<HAUTEUR/3+20+HAUTEUR/8 + HAUTEUR/8
        )
        cas = 2;
    
    switch(cas){
    case 1 :
        return 1;
        break;
    case 2 :
        return 2;
        break;
    default :
        break;
    }
}
