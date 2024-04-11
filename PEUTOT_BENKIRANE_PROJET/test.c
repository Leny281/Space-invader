#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>

#define LARGEUR 900
#define LONGUEUR 900
#define EN 100
#define BAS LONGUEUR-180
#define NB_ENEMIE_MAX 30


typedef struct {
    int x;
    int y;
    int lancer;
} bullet;

typedef struct {
    int x;
    int y;
    int largeur;
    int longueur;
    int pv;
    int visible;
    int sens_deplacement;
    bullet balle;
    int point;
    int vitesse;
} enemy;

typedef struct {
    int x;
    int y;
    int largeur;
    int longueur;
    int pv;
    int vitesse;
    bullet b1;
} ship;


typedef struct{
    ship joueur1;
    ship joueur2;
    int solo_duo;
    int score;
    int wave;
    int nb_enemie;
    int nm_save;
}partie;


int main(){

    partie save;
    FILE *fic;
    char texte[100];
    int i;

    save.wave=1;
    if (save.wave*3>12){
        save.nb_enemie=12;
    }else
    {
         
        save.nb_enemie=save.wave*2;
    }
    save.joueur1.x = LARGEUR / 2;
    save.joueur1.y = LONGUEUR-LONGUEUR/8;
    save.joueur1.largeur = 40;
    save.joueur1.longueur = 50;
    save.joueur1.pv = 3;
    save.joueur1.b1.lancer = 0;
    save.score = 0;
    save.nm_save = 0;

    
    save.solo_duo=1;
    
    save.joueur2.pv = 0;


    save.joueur2.x = LARGEUR / 2;
    save.joueur2.y = LONGUEUR-LONGUEUR/8-50;
    save.joueur2.largeur = 40;
    save.joueur2.longueur = 50;
    save.joueur2.b1.lancer = 0;
    save.score = 0;
    save.nm_save = 0;


    

    for(i=0;i<4;i++){
        sprintf(texte, "SAVE/save%d.bin", i);
        
        fic = fopen(texte,"wb+");
        save.nm_save = i;
        if (fic == NULL){
            printf("Erreur fichier non cree");
            exit(EXIT_FAILURE);
            
        
        }

        fwrite(&save, sizeof(save), 1, fic);


        fclose(fic);

    }

    
    
    return 0;


}