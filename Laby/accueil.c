/**
 *\file accueil.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author THIEULART Godefroy
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "JDR1_0.h"
#include "deplacement.h"
#include "accueil.h"
#include "IA.h"

int quitter = 0;
extern t_coordonees ma_position;
extern t_coordonees sorti;

void ecran_accueil(){
	char verif = 'a';
	clear();
	printw("\n");
	printw("\n");
	printw("                       II            II IIIIII II     IIII    IIII  IIII  IIII IIIIII                       \n");
	printw("                        II    II    II  II     II    II   II II  II II IIII II II                           \n");
	printw("                         II  IIII  II   IIII   II   II       II  II II  II  II IIII                         \n");
	printw("                          IIII  IIII    II     II    II   II II  II II      II II                           \n");
	printw("                           II    II     IIIIII IIII   IIII    IIII  II      II IIIIII                       \n");
	printw("\n");
	printw("                                    IIIIII   IIII    IIIIII II  II IIIIII                                   \n");
	printw("                                      II    II  II     II   II  II II                                       \n");
	printw("                                      II    II  II     II   IIIIII IIII                                     \n");
	printw("                                      II    II  II     II   II  II II                                       \n");
	printw("                                      II     IIII      II   II  II IIIIII                                   \n");
	printw("\n");
	printw("II   IIIIII  IIII   IIII   II  II IIIIII    IIII  IIIIII   IIII   IIII   IIII  II     II IIIIII III   II    \n");
	printw("II   II     II  II II  II  II  II II       II  II II       II II  II II II  II  II   II  II     IIII  II    \n");
	printw("II   IIII   IIIIII II      II  II IIII     II  II IIII     II  II IIII  IIIIII   II II   IIII   II II II    \n");
	printw("II   II     II  II II  III II  II II       II  II II       II II  III   II  II   IIII    II     II  IIII    \n");
	printw("IIII IIIIII II  II  IIII I  IIII  IIIIII    IIII  II       IIII   II II II  II    II     IIIIII II   III ©  \n");
	printw("\n");
	printw("                                  Press enter to start the game                                             \n");
		
	while(verif != '\n'){
		verif = getch();
	}
	refresh();
}

void Option_jeu(int matrice[N][N]){
	int verif = 0;
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                        ______________________________________________        |||   \n");
	printw("        |||                                       //                                            \\\\       ||| \n");
	printw("        |||                   |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printw("        |||                   |Z           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printw("        |||                   |   pour     |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printw("        |||                   |      Monter|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printw("        |||                   |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printw("        |||   |Q           |  | S          |  |D           |        |    -4-     |    |    -5-     |     |||   \n");
	printw("        |||   |   pour     |  |   pour     |  |   pour     |        |Option      |    |Retour      |     |||   \n");
	printw("        |||   |   la Gauche|  |   Descendre|  |   La Droite|        |      de jeu|    |    au  Menu|     |||   \n");
	printw("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |            VEUILLEZ            |                               |||   \n");
	printw("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printw("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	refresh();
	while(verif!=5){
		scanw(" %i", &verif);
	}
	Menu_Jeu(matrice);
}

void Menu_Jeu(int matrice[N][N]){
	int verif=-1;
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|    |============|    |============|    |============|    |============|     |||   \n");
	printw("        |||   |    -1-     |    |    -2-     |    |    -3-     |    |    -4-     |    |    -5-     |     |||   \n");
	printw("        |||   |Nouvelle    |    |Charger     |    |Cheat       |    |Option      |    |Quitter     |     |||   \n");
	printw("        |||   |      Partie|    |      Partie|    |        Code|    |      de jeu|    |     le jeu |     |||   \n");
	printw("        |||   |============|    |============|    |============|    |============|    |============|     |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |            VEUILLEZ            |                               |||   \n");
	printw("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printw("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	refresh();
	while(verif<='0' || verif>'5'){
		verif = getch();
	}
	switch(verif){
		case '1' : nouvelle_partie(matrice); Menu_Jeu(matrice); break;
		case '2' : charger_par(matrice); Menu_Jeu(matrice); break;
		case '4' : Option_jeu(matrice); break ;
		case '5' : Quitter_Jeu(); break;
	}
}

void Quitter_Jeu(){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                         O|=====================================|O                            |||   \n");
	printw("        |||                            \\        MERCI                   /                                |||  \n");
	printw("        |||                             \\                              /                                 |||  \n");
	printw("        |||                              \\          D'AVOIR           /                                  |||  \n");
	printw("        |||                               \\                          /                                   |||  \n");
	printw("        |||                                \\              JOUE      /                                    |||  \n");
	printw("        |||                                 \\                      /                                     |||  \n");
	printw("        |||                                  \\____________________/                                      |||  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |      NOUS ESPERONS VOUS        |                               |||   \n");
	printw("        |||                             |             REVOIR             |                               |||   \n");
	printw("        \\|/                             |        PROCHAINEMENT           |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	printw("                                          Press Enter to leave the game                                        \n");
	while(verif != '\n'){
		verif = getch();
	}
	quitter = 1;
}

void defeat(int matrice[N][N]){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                          IIII    IIIIII IIIIII IIIIII  IIII  IIIIII                          |||   \n");
	printw("        |||                          II  II  II     II     II     II  II   II                            |||   \n");
	printw("        |||                          II   II IIII   IIII   IIII   IIIIII   II                            |||   \n");
	printw("        |||                          II  II  II     II     II     II  II   II                            |||   \n");
	printw("        |||                          IIII    IIIIII II     IIIIII II  II   II                            |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |      RETOUR                    |                               |||   \n");
	printw("        |||                             |             SUR LE             |                               |||   \n");
	printw("        \\|/                             |                   MENU         |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	printw("                                             Press Enter to continue                                           \n");

	while(verif != '\n'){
		verif = getch();
	}
}

void victory(int matrice[N][N]){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                       II     II IIII  IIII  IIIIII  IIII  IIII  II  II                       |||   \n");
	printw("        |||                       II     II  II  II  II   II   II  II II II  IIII                        |||   \n");
	printw("        |||                        II   II   II  II       II   II  II IIII    II                         |||   \n");
	printw("        |||                         II II    II  II  II   II   II  II III     II                         |||   \n");
	printw("        |||                           I     IIII  IIII    II    IIII  II II   II                         |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |      RETOUR                    |                               |||   \n");
	printw("        |||                             |             SUR LE             |                               |||   \n");
	printw("        \\|/                             |                   MENU         |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	printw("                                             Press Enter to continue                                           \n");

	while(verif != '\n'){
		verif = getch();
	}
}

void continuer(int matrice[N][N]){
	
	int VD=-1;
	int pvMob=100;
	rechercheJoueur(matrice);
	sorti=ma_position;
	while(matrice[ma_position.x][ma_position.y] != OBJECTIF && quitter != 1){
		rechercheJoueur(matrice);
		affichage(matrice);
		deplacement_perso(matrice, &pvMob);
		VD=IA(matrice);
		if(VD==1){
			defeat(matrice);
			quitter=0;
		}
		else {
			if(coffre(matrice)){
				matrice[sorti.x][sorti.y] = OBJECTIF;
			}		
			affichage(matrice);
		}
	}
	if(VD==0){
		victory(matrice);
	}
}
