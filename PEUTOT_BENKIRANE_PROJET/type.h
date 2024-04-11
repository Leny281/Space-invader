#ifndef type
#define type

#include <MLV/MLV_all.h>




#define LARGEUR 900
#define LONGUEUR 900
#define HAUTEUR 900
#define EN 100
#define NB_ENEMIE_MAX 30
#define MAX_CLASSEMENT 100
#define TAILLE_MAX_PSEUDO 10

typedef struct {
    MLV_Image *mlv;
    int x;
    int y;
    int largeur;
    int hauteur;
}image;

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


#endif
