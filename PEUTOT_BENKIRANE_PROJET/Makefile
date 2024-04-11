CC=gcc
OPTION= -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV`
O1 = `pkg-config --libs-only-other --libs-only-L MLV`
O2 = `pkg-config --libs-only-l MLV`

jeu : menu.o gerer_menu.o affichage_menu.o animations.o initialisation.o jsave.o pause.o joueur.o enemie.o balle.o collision.o
	$(CC) $(OPTION) $(O1) menu.o gerer_menu.o affichage_menu.o animations.o initialisation.o jsave.o enemie.o collision.o balle.o pause.o joueur.o -o jeu $(O2)

menu.o : menu.c affichage_menu.c animations.c initialisation.c
	$(CC) $(OPTIONS) $(OPTIONS_A) -c menu.c

jsave.o : jsave.c type.h jsave.h
	$(CC) $(OPTION) $(O1) -c jsave.c

pause.o : pause.c pause.h 
	$(CC) $(OPTION) $(O1) -c pause.c

collision.o : collision.c collision.h
	$(CC) $(OPTION) $(O1) -c collision.c

joueur.o: joueur.c joueur.h
	$(CC) $(OPTION) $(O1) -c joueur.c

balle.o : balle.c balle.h
	$(CC) $(OPTION) $(O1) -c balle.c

enemie.o : enemie.c enemie.h
	$(CC) $(OPTION) $(O1) -c enemie.c

affichage_menu.o : affichage_menu.c affichage_menu.h
	$(CC) $(OPTIONS) $(OPTIONS_A) -c affichage_menu.c

animations.o : animations.c animations.h
	$(CC) $(OPTIONS) $(OPTIONS_A) -c animations.c

initialisation.o : initialisation.c initialisation.h
	$(CC) $(OPTIONS) $(OPTIONS_A) -c initialisation.c

gerer_menu.o : gerer_menu.c gerer_menu.h
	$(CC) $(OPTIONS) $(OPTIONS_A) -c gerer_menu.c



clean :
	rm -rf *.o *~ jeu

