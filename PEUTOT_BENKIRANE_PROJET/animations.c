#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>

#include"macros.h"
#include"type.h"
#include"affichage_menu.h"

#define LARGEUR 900
#define HAUTEUR 900
#define MAX 1024

int animation_fond_menu(image liste[], int compteur_cycle, int boutton){
    if(liste[ESPACE].x+LARGEUR==0 || liste[ESPACE_C].x==0){
        liste[ESPACE].x=0;
        liste[ESPACE_C].x=LARGEUR;
    }
    
    if(compteur_cycle>=15){
        liste[ESPACE].x-=1;
        liste[ESPACE_C].x-=1;
        compteur_cycle=0;
    }
    compteur_cycle++;

    if (boutton == 0)
        afficher_menu(liste, TOUT);
    else
        afficher_menu(liste, RIEN);
    return compteur_cycle;
}

void animation_lancer_jeu(image liste[]){
    int i=0;
    int compteur_cycle=0;
    while((liste[VAISSEAU].y + liste[VAISSEAU].hauteur) > 0){
        compteur_cycle=animation_fond_menu(liste, compteur_cycle, 1);
        liste[VAISSEAU].y--;
        liste[VAISSEAU].y--;
        MLV_actualise_window();
        i++;
    }
}