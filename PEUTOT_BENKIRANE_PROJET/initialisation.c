#include<stdio.h>
#include<stdlib.h>
#include<MLV/MLV_all.h>

#include"macros.h"
#include"type.h"

#define LARGEUR 900
#define HAUTEUR 900
#define MAX 1024

/*
Prend en entrée le nom d'une image, les coordonnées x ety et la taille de l'image.
Remplie la structure en question avec les valeurs en paramètre.
Ne renvoie rien.
 */

void creer_image(image *nom, MLV_Image *mlv, int x, int y, int l, int h){
    nom->mlv = mlv;
    nom->x = x;
    nom->y = y;
    nom->largeur = l;
    nom->hauteur = h;
}

void init_images(image liste_images[]){
    MLV_Image *mlv_image;
    image img;

    /*Création de l'image de devant du menu (les imgs)*/
    mlv_image = MLV_load_image("images/menu_1er_plan.png");
    MLV_resize_image(mlv_image, LARGEUR, HAUTEUR);
    creer_image(&img, mlv_image, 0, 0, LARGEUR, HAUTEUR);
    liste_images[MONTAGNE] = img;

    /*Création de l'image de fond du menu (le ciel étoilé)*/
    mlv_image = MLV_load_image("images/menu_2eme_plan.png");
    MLV_resize_image(mlv_image, LARGEUR, HAUTEUR);
    creer_image(&img, mlv_image, 0, 0, LARGEUR, HAUTEUR);
    liste_images[ESPACE] = img;

    /*Création de l'image de fond du menu pour faire le cycle*/
    mlv_image = MLV_load_image("images/menu_2eme_plan.png");
    MLV_resize_image(mlv_image, LARGEUR, HAUTEUR);
    creer_image(&img, mlv_image ,LARGEUR, 0, LARGEUR, HAUTEUR);
    liste_images[ESPACE_C] = img;

    /*Création de l'image du img*/
    mlv_image = MLV_load_image("images/titre_jeu.png");
    creer_image(&img, mlv_image, LARGEUR/2, HAUTEUR/20, LARGEUR/1.125, HAUTEUR/9);
    img.x-=img.largeur/2;
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[TITRE] = img;

    /*Création de l'image du boutton img*/
    mlv_image = MLV_load_image("images/boutton_leaderboard.png");
    creer_image(&img, mlv_image, LARGEUR/1.4, HAUTEUR/3, LARGEUR/9, HAUTEUR/9);
    img.x-=img.largeur/2;
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[COUPE] = img;
    
    /*Création de l'image du boutton img enclenché*/
    mlv_image = MLV_load_image("images/boutton_leaderboard_sombre.png");
    creer_image(&img, mlv_image, LARGEUR/1.4, HAUTEUR/3, LARGEUR/9, HAUTEUR/9);
    img.x-=img.largeur/2;
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[COUPE_S] = img;

    /*Création du boutton de la img du classement*/
    mlv_image = MLV_load_image("images/boutton_play.png");
    creer_image(&img, mlv_image, LARGEUR/4, HAUTEUR/3, LARGEUR/9, HAUTEUR/9);
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[PLAY] = img;

    /*Création du boutton de la img du classement enclenché*/
    mlv_image = MLV_load_image("images/boutton_play_sombre.png");
    creer_image(&img, mlv_image, LARGEUR/4, HAUTEUR/3, LARGEUR/9, HAUTEUR/9);
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[PLAY_S] = img;

    /*Création de l'image du img*/
    mlv_image = MLV_load_image("images/vaisseau.png");
    creer_image(&img, mlv_image, LARGEUR/2, HAUTEUR/2, LARGEUR/3, HAUTEUR/2);
    img.x-=img.largeur/2+10;
    MLV_resize_image(mlv_image, img.largeur, img.hauteur);
    liste_images[VAISSEAU] = img;
}