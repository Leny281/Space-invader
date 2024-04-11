#include <MLV/MLV_all.h>
#include <time.h>
#include "type.h"
#include "pause.h"
#include "joueur.h"
#include "enemie.h"
#include "balle.h"
#include "collision.h"
#include "gerer_menu.h"
#include "affichage_menu.h"

#define LARGEUR 900
#define LONGUEUR 900
#define EN 100
#define NB_ENEMIE_MAX 30



/*------------------------------affiche les hp du joueur--------------------------------*/

void af_hp1(ship *joueur,MLV_Image *coeur){
    int i,e;
    e = 0;
    for(i=1;i<=joueur->pv;i++){
        MLV_draw_image(coeur, 20+e, 20);
        e+=80;
        
    }
}

void af_hp2(ship *joueur,MLV_Image *coeur){
    int i,e;
    e = 0;
    for(i=1;i<=joueur->pv;i++){
        MLV_draw_image(coeur, 20+e, 70);
        e+=80;
        
    }
}



void gestion_wave(enemy *enemie,partie *game_actuel,int *compteur,partie *check_point, MLV_Font *font){
    char truc[20];
    if (tout_ennemie_mort(enemie,game_actuel->nb_enemie)==0){
        *compteur-=1;
        sprintf(truc, "WAVE %d", game_actuel->wave);
        MLV_draw_text_with_font(LARGEUR/2-200, LONGUEUR/2-200,truc,font, MLV_COLOR_WHITE);
        check_point->joueur1=game_actuel->joueur1;
        check_point->joueur2=game_actuel->joueur2;
        check_point->score=game_actuel->score ;
        check_point->wave=game_actuel->wave;
        check_point->nb_enemie=game_actuel->nb_enemie;
        check_point->nm_save = game_actuel->nm_save;
            
    }
        
    if (*compteur == 0){
        if (game_actuel->nb_enemie<12){
            game_actuel->nb_enemie+=3;
        }
        cree_enemie_basic(enemie, game_actuel->nb_enemie,game_actuel->wave);
        *compteur=100;
        game_actuel->wave+=1;
    } 
}

void set_up_game(partie *game_actuel,partie *check_point,partie game){
    
    game_actuel->joueur1=game.joueur1;
    game_actuel->joueur2=game.joueur2;
    game_actuel->score=game.score ;
    game_actuel->wave=game.wave;
    game_actuel->nb_enemie=game.nb_enemie;
    game_actuel->nm_save=game.nm_save;
    game_actuel->solo_duo=game.solo_duo;
     
    check_point->joueur1=game_actuel->joueur1;
    check_point->joueur2=game_actuel->joueur2;
    check_point->score=game_actuel->score ;
    check_point->wave=game_actuel->wave;
    check_point->nb_enemie=game_actuel->nb_enemie;
    check_point->nm_save=game_actuel->nm_save;
    check_point->solo_duo=game_actuel->solo_duo; 

}


/*------------------------------fonction corps du jeu---------------------------*/

partie jeu(partie game) {
    MLV_Image* etoile1;
    MLV_Image* etoile2;
    partie game_actuel,check_point;
    int fin=0;
    int y1=0;
    int y2=0-LONGUEUR;
    double accum;
    struct timespec start, stop;
    char texte[20];
    int compteur=100;
    MLV_Font* font;
    MLV_Font* font2;
    MLV_Image* vaisseau;
    MLV_Image* mechant;
    MLV_Image* coeur;
    MLV_Image* balle_ennemie;
    MLV_Image* balle_joueur;
    MLV_Image* coeur2;
    enemy enemie[NB_ENEMIE_MAX];
    FILE *fichier_score = NULL;
    
    srand(time(NULL));
    
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 150 );
    font2 = MLV_load_font( "8-bits/truc.ttf" , 40 );
    
    vaisseau = MLV_load_image( "images/vaisseau.png" );
    mechant = MLV_load_image( "images/mechant.png" );
    coeur = MLV_load_image( "images/pv.png" );
     coeur2 = MLV_load_image( "images/pv2.png" );
    balle_ennemie = MLV_load_image( "images/balle_ennemie.png" );
    balle_joueur = MLV_load_image( "images/balle_joueur.png" );
    etoile1=MLV_load_image( "images/etoile1.png" );
    etoile2=MLV_load_image( "images/etoile1.png" );

    MLV_resize_image_with_proportions( coeur, 60, 60);
     MLV_resize_image_with_proportions( coeur2, 60, 60);
    MLV_resize_image_with_proportions( vaisseau, game.joueur1.largeur, game.joueur1.longueur+200);
    MLV_resize_image_with_proportions( balle_ennemie, 5, 40);

    set_up_game(&game_actuel,&check_point,game);
    
    cree_enemie_invisible(enemie, game_actuel.nb_enemie);
    
    MLV_resize_image_with_proportions( mechant, enemie->largeur, enemie->longueur);
    MLV_resize_image_with_proportions( etoile1, LARGEUR, LONGUEUR);
    MLV_resize_image_with_proportions( etoile2, LARGEUR, LONGUEUR);
    
   
    while (game_actuel.joueur1.pv>0 || game_actuel.joueur2.pv>0) {

        
        clock_gettime(CLOCK_REALTIME, &start );
        
        /*MLV_clear_window(MLV_COLOR_BLACK);*/
        if(y1==LONGUEUR){
            y1=0-LONGUEUR;
        }
        if(y2==LONGUEUR){
            y2=0-LONGUEUR;
        }   


        MLV_draw_image(etoile1, 0, y1);
        MLV_draw_image(etoile2, 0, y2);
        y1++;
        y2++;
        gestion_wave(enemie,&game_actuel,&compteur,&check_point,font);

        /*printf( "joueur1 : %d \n", game_actuel.joueur1.pv);*/
        /*printf( "joueur2 :%d \n", game_actuel.joueur2.pv);*/


        sprintf(texte, "SCORE %d", game_actuel.score);
        MLV_draw_text_with_font(LARGEUR-LARGEUR/4,20 ,texte,font2, MLV_COLOR_WHITE); 
        if (game_actuel.solo_duo==2 && game_actuel.joueur2.pv>0){
            af_hp2(&game_actuel.joueur2,coeur2);
            dessine_ship(game_actuel.joueur2,vaisseau);
            avance_tire(&game_actuel.joueur2.b1,balle_joueur); 
            activer_balle2(&game_actuel.joueur2);
            deplacement2(&game_actuel.joueur2);
            colision_joueur_ennemie(&game_actuel.joueur2,enemie,game_actuel);
            verif_ennemie_toucher(&game_actuel.joueur2.b1,enemie,game_actuel.nb_enemie,&game_actuel.score);
            verif_joueur_toucher(&game_actuel.joueur2,enemie,game_actuel.nb_enemie);
        }
        
        if (game_actuel.joueur1.pv>0){
            dessine_ship(game_actuel.joueur1,vaisseau);
            af_hp1(&game_actuel.joueur1,coeur);
            avance_tire(&game_actuel.joueur1.b1,balle_joueur);
            activer_balle1(&game_actuel.joueur1);
            deplacement1(&game_actuel.joueur1);
            colision_joueur_ennemie(&game_actuel.joueur1,enemie,game_actuel);
            verif_ennemie_toucher(&game_actuel.joueur1.b1,enemie,game_actuel.nb_enemie,&game_actuel.score);
            verif_joueur_toucher(&game_actuel.joueur1,enemie,game_actuel.nb_enemie);
           
        }
       

        ennemie_atteint_sol(&game_actuel.joueur1,&game_actuel.joueur2,enemie,game_actuel)  ;
        dessine_ennemie(enemie,game_actuel.nb_enemie,mechant);
        generation_balle_ennemie(enemie,game_actuel.nb_enemie,balle_ennemie);
        deplacement_ennemie(enemie,game_actuel.nb_enemie);
        pause(check_point);
        

        
        MLV_actualise_window();
        
        clock_gettime( CLOCK_REALTIME, &stop);
        accum=20-(( stop.tv_sec - start.tv_sec )+ ( stop.tv_nsec - start.tv_nsec )/1000000);
        /*printf( "%f\n", accum ); */
        if (accum>0 && accum<=28){
            MLV_wait_milliseconds(accum);}
    }

    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_with_font(LARGEUR/2-320, LONGUEUR/2-200,"GAME OVER",font, MLV_COLOR_WHITE);
    sprintf(texte, "SCORE  %d", game_actuel.score);
    MLV_draw_text_with_font(LARGEUR/2-350, LONGUEUR/2-400,texte,font, MLV_COLOR_BLACK);
    MLV_actualise_window();
    
    MLV_wait_seconds(3);
    
    MLV_free_font(font);
    MLV_free_font(font2);
    
    font = MLV_load_font( "8-bits/8-bitArcadeIn.ttf" , 30 );
    
    MLV_desactivate_input_box();
    afficher_menu_fin_partie();
    MLV_actualise_window();
    
    fin = gerer_menu_fin_partie();
    switch(fin){
    case 1:
        MLV_clear_window(MLV_COLOR_BLACK);
        
        fichier_score = fopen("classement.txt", "a");
	
        if (fichier_score == NULL){
	  printf("Erreur");
	  exit(EXIT_FAILURE);
	}
	
	fprintf(fichier_score, "%d\n", game_actuel.score);
	fclose(fichier_score);
	
        break;
    case 3:
        /*menu();*/
        break;
    default :
        break;
    }

    /*menu()*/
    return game;
}



void lancer_jeu(int num_save, int nb_joueur){
    FILE *fic;
    partie save;
    size_t elements_lus;
    char texte[20];

    sprintf(texte, "SAVE/save%d.bin", num_save);
    
    fic = fopen(texte,"rb");

    if (fic == NULL){
        printf("Erreur fichier non existant\n");
        exit(EXIT_FAILURE);

    }
    
    elements_lus = fread(&save, sizeof(save), 1, fic);
    if (elements_lus != 1) {
        fprintf(stderr, "Erreur lors de la lecture du fichier.\n");
    }

    fclose(fic);
    
    if (nb_joueur == 0){
        jeu(save);
        
    }else{
        save.solo_duo = nb_joueur;
        if(nb_joueur == 1)
            save.joueur2.pv = 0;
        else
            save.joueur2.pv = 3;
        jeu(save);
    }
    
    return ;

}
