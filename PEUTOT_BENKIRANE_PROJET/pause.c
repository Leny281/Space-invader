#include <MLV/MLV_all.h>
#include "type.h"
#include "menu.h"


void pause(partie check_point){
    int x,y,u=0;
    MLV_Font* font;
    MLV_Color grey = MLV_rgba(128, 128, 128, 100);
    FILE *fic;
    font = MLV_load_font( "8-bits/police.ttf" , 60 );
    
    if (MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) == 0){
        MLV_draw_filled_rectangle(0, 0, LONGUEUR, LARGEUR, grey);
        
        /*CONTINUER*/
        MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/2.7, LARGEUR/2,LARGEUR/10," Continuer",
                                    font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

        /*SAUVEGARDER*/
        MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/4, LARGEUR/2,LARGEUR/10, "Sauvegarder",
                                    font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);


        /*MENU*/
        MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2.7, LARGEUR/2,LARGEUR/10, "Menu",
                                    font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

        /* /\*QUITTER*\/ */
        MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2, LARGEUR/2,LARGEUR/10, "Quitter",
                                    font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);
        


        

        MLV_actualise_window();
        
        while(1){
        
            /*CONTINUER*/
            MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/2.7,
                                        LARGEUR/2,LARGEUR/10," Continuer",font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,
                                        MLV_COLOR_WHITE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

            /*SAUVEGARDER*/
            MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/4, LARGEUR/2,LARGEUR/10,
                                        "Sauvegarder",font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,
                                        MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);


            /*MENU*/
            MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2.7, LARGEUR/2,LARGEUR/10, "Menu",
                                        font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,
                                        MLV_TEXT_CENTER,MLV_TEXT_CENTER);

            /* /\*QUITTER*\/ */
            MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2, LARGEUR/2,LARGEUR/10, "Quitter",
                                        font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,
                                        MLV_TEXT_CENTER,MLV_TEXT_CENTER);
            
            MLV_actualise_window();
            MLV_wait_mouse (&x, &y);
            /*Continuer*/
            if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 - LARGEUR / 2.7 && y <= LARGEUR / 2 - LARGEUR / 2.7 + LARGEUR / 10)
            {
                return ;
            }
            /*Menu*/
            if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2.7 && y <= LARGEUR / 2.7 + LARGEUR / 10)
            {
                menu();
            }
            /*QUITTER*/
            if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 && y <= LARGEUR / 2 + LARGEUR / 10)
            {
                exit(EXIT_SUCCESS);
            }
            
            /*SAUVEGARDER*/
            if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 - LARGEUR / 4 && y <= LARGEUR / 2 - LARGEUR / 4 + LARGEUR / 10)
            {
                u=0;
                while(u==0){

                    MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/2.7,
                                                LARGEUR/2,LARGEUR/10, "Save 1",font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_ORANGE,
                                                MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

                    MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2-LARGEUR/4,
                                                LARGEUR/2,LARGEUR/10, "Save 2",font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,
                                                MLV_COLOR_ORANGE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

                    MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2.7, LARGEUR/2,LARGEUR/10,
                                                "Save 3",font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_ORANGE,
                                                MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);

                    MLV_draw_text_box_with_font(LONGUEUR/2-LONGUEUR/4.5,LARGEUR/2, LARGEUR/2,LARGEUR/10, "Retour",
                                                font,50,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_ORANGE,MLV_TEXT_CENTER,MLV_TEXT_CENTER,MLV_TEXT_CENTER);
                
                
                    MLV_actualise_window();


                
                    MLV_wait_mouse (&x, &y);

                    /*SAVE 1*/
                    if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 - LARGEUR / 2.7 && y <= LARGEUR / 2 - LARGEUR / 2.7 + LARGEUR / 10)
                    {
                        fic = fopen("SAVE/save1.bin","wb+");

                        if (fic == NULL){
                            printf("Erreur fichier non cree");
                            exit(EXIT_FAILURE);
                    
                        }
                        fwrite(&check_point, sizeof(check_point), 1, fic);


                        fclose(fic);
                        u++;
                    }
                    /*SAVE 2 */
                    if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 - LARGEUR / 4 && y <= LARGEUR / 2 - LARGEUR / 4 + LARGEUR / 10)
                    {
                        fic = fopen("SAVE/save2.bin","wb+");

                        if (fic == NULL){
                            printf("Erreur fichier non cree");
                            exit(EXIT_FAILURE);
                    
                        }
                        fwrite(&check_point, sizeof(check_point), 1, fic);


                        fclose(fic);
                        u++;
                    }

                    /*SAVE 3*/
                    if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2.7 && y <= LARGEUR / 2.7 + LARGEUR / 10)
                    {
                        fic = fopen("SAVE/save3.bin","wb+");

                        if (fic == NULL){
                            printf("Erreur fichier non cree");
                            exit(EXIT_FAILURE);
                    
                        }
                        fwrite(&check_point, sizeof(check_point), 1, fic);


                        fclose(fic);
                        u++;
                    }

                    if (x >= LONGUEUR / 2 - LONGUEUR / 4.5 && x <= LONGUEUR / 2 + LARGEUR / 2 && y >= LARGEUR / 2 && y <= LARGEUR / 2 + LARGEUR / 10)
                    {
                        u++;
                    }
                }
              
            }
            
           
            
             x=0;
             y=0;
            MLV_actualise_window();
    
        }
    }
    MLV_free_font(font);
 
}




