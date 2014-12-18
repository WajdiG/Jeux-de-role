/**
 *\file accueil.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author THIEULART Godefroy
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include <time.h>
#include "JDR1_0.h"
#include "deplacement.h"
#include "accueil.h"
#include "IA.h"

int quitter = 0;
int cpt_laby=0;
extern t_joueur joueur;
extern t_coordonees ma_position;
extern t_coordonees sorti;
extern t_statcombat statcombat;

void ecran_accueil(){
	char verif = 'a';
	system("clear");
	printf("\n");
	printf("\n");
	printf("                       II            II IIIIII II     IIII    IIII  IIII  IIII IIIIII                       \n");
	printf("                        II    II    II  II     II    II   II II  II II IIII II II                           \n");
	printf("                         II  IIII  II   IIII   II   II       II  II II  II  II IIII                         \n");
	printf("                          IIII  IIII    II     II    II   II II  II II      II II                           \n");
	printf("                           II    II     IIIIII IIII   IIII    IIII  II      II IIIIII                       \n");
	printf("\n");
	printf("                                    IIIIII   IIII    IIIIII II  II IIIIII                                   \n");
	printf("                                      II    II  II     II   II  II II                                       \n");
	printf("                                      II    II  II     II   IIIIII IIII                                     \n");
	printf("                                      II    II  II     II   II  II II                                       \n");
	printf("                                      II     IIII      II   II  II IIIIII                                   \n");
	printf("\n");
	printf("II   IIIIII  IIII   IIII   II  II IIIIII    IIII  IIIIII   IIII   IIII   IIII  II     II IIIIII III   II    \n");
	printf("II   II     II  II II  II  II  II II       II  II II       II II  II II II  II  II   II  II     IIII  II    \n");
	printf("II   IIII   IIIIII II      II  II IIII     II  II IIII     II  II IIII  IIIIII   II II   IIII   II II II    \n");
	printf("II   II     II  II II  III II  II II       II  II II       II II  III   II  II   IIII    II     II  IIII    \n");
	printf("IIII IIIIII II  II  IIII I  IIII  IIIIII    IIII  II       IIII   II II II  II    II     IIIIII II   III ©  \n");
	printf("\n");
	printf("                                  Press enter to start the game                                             \n");
		
	while(verif != '\n'){
		scanf("%c", &verif);
	}
}

void Option_jeu(int matrice[N][N]){
	int verif = 0;
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                        ______________________________________________        |||   \n");
	printf("        |||                                       //                                            \\\\       ||| \n");
	printf("        |||                   |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printf("        |||                   |Z           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printf("        |||                   |   pour     |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printf("        |||                   |      Monter|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printf("        |||                   |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printf("        |||   |Q           |  | S          |  |D           |        |    -4-     |    |    -5-     |     |||   \n");
	printf("        |||   |   pour     |  |   pour     |  |   pour     |        |page        |    |Retour      |     |||   \n");
	printf("        |||   |   la Gauche|  |   Descendre|  |   La Droite|        |    suivante|    |    au  Menu|     |||   \n");
	printf("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |            VEUILLEZ            |                               |||   \n");
	printf("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printf("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");

	scanf("%i", &verif);
	switch(verif){
		case 4 : Option_jeu_2(matrice); break;
		case 5 : Menu_Jeu(matrice); break;
	}
	Menu_Jeu(matrice);
}

void Option_jeu_2(int matrice[N][N]){
	int verif = 0;
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                        ______________________________________________        |||   \n");
	printf("        |||                                       //                                            \\\\       ||| \n");
	printf("        |||                   |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printf("        |||                   |I           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printf("        |||                   | pour taper |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printf("        |||                   |     en haut|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printf("        |||                   |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printf("        |||   |J           |  | K          |  |L           |        |    -4-     |    |    -5-     |     |||   \n");
	printf("        |||   | pour taper |  | pour taper |  | pour tapper|        |page        |    |Retour      |     |||   \n");
	printf("        |||   |    a Gauche|  |      en bas|  |    a Droite|        |  precedente|    |    au  Menu|     |||   \n");
	printf("        |||   |============|  |============|  |============|        |============|    |============|     |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |            VEUILLEZ            |                               |||   \n");
	printf("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printf("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");

	scanf("%i", &verif);
	switch(verif){
		case 4 : Option_jeu(matrice); break;
		case 5 : Menu_Jeu(matrice); break;
	}
	Menu_Jeu(matrice);
}

void Menu_Jeu(int matrice[N][N]){
	int verif=-1;
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||   |============|    |============|    |============|    |============|    |============|     |||   \n");
	printf("        |||   |    -1-     |    |    -2-     |    |    -3-     |    |    -4-     |    |    -5-     |     |||   \n");
	printf("        |||   |Nouvelle    |    |Charger     |    |Cheat       |    |Option      |    |Quitter     |     |||   \n");
	printf("        |||   |      Partie|    |      Partie|    |        Code|    |      de jeu|    |     le jeu |     |||   \n");
	printf("        |||   |============|    |============|    |============|    |============|    |============|     |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |            VEUILLEZ            |                               |||   \n");
	printf("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printf("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");
	
	while(verif<=0 || verif>5){
		scanf(" %i", &verif);
	}
	switch(verif){
		case 1 : nouvelle_partie(matrice); break;
		case 4 : Option_jeu(matrice); break ;
		case 5 : Quitter_Jeu(); break;
	}
}

void Quitter_Jeu(){
	char verif='a';
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                         O|=====================================|O                            |||   \n");
	printf("        |||                            \\        MERCI                   /                                |||  \n");
	printf("        |||                             \\                              /                                 |||  \n");
	printf("        |||                              \\          D'AVOIR           /                                  |||  \n");
	printf("        |||                               \\                          /                                   |||  \n");
	printf("        |||                                \\              JOUE      /                                    |||  \n");
	printf("        |||                                 \\                      /                                     |||  \n");
	printf("        |||                                  \\____________________/                                      |||  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |      NOUS ESPERONS VOUS        |                               |||   \n");
	printf("        |||                             |             REVOIR             |                               |||   \n");
	printf("        \\|/                             |        PROCHAINEMENT           |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");
	printf("                                          Press Enter to leave the game                                        \n");
	while(verif != '\n'){
		scanf("%c", &verif);
	}
	quitter = 1;
}

void defeat(int matrice[N][N]){
	char verif='a';
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                          IIII    IIIIII IIIIII IIIIII  IIII  IIIIII                          |||   \n");
	printf("        |||                          II  II  II     II     II     II  II   II                            |||   \n");
	printf("        |||                          II   II IIII   IIII   IIII   IIIIII   II                            |||   \n");
	printf("        |||                          II  II  II     II     II     II  II   II                            |||   \n");
	printf("        |||                          IIII    IIIIII II     IIIIII II  II   II                            |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |      RETOUR                    |                               |||   \n");
	printf("        |||                             |             SUR LE             |                               |||   \n");
	printf("        \\|/                             |                   MENU         |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");
	printf("                                             Press Enter to continue                                           \n");

	while(verif != '\n'){
		scanf("%c", &verif);
	}
	Menu_Jeu(matrice);
}

void victory(int matrice[N][N]){
	char verif='a';
	system("clear");
	printf("\n");
	printf("\n");
	printf("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printf("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printf("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printf("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printf("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                 H    \n");
	printf("        /H\\                                                                                              /H\\ \n");
	printf("       <HUH>            _______TOULMONDE_Joris-THIEULART_Godefroy-GUEDOUAR_Wajdi________                <HUH>  \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                       II     II IIII  IIII  IIIIII  IIII  IIII  II  II                       |||   \n");
	printf("        |||                       II     II  II  II  II   II   II  II II II  IIII                        |||   \n");
	printf("        |||                        II   II   II  II       II   II  II IIII    II                         |||   \n");
	printf("        |||                         II II    II  II  II   II   II  II III     II                         |||   \n");
	printf("        |||                           I     IIII  IIII    II    IIII  II II   II                         |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                                                                                              |||   \n");
	printf("        |||                             |================================|                               |||   \n");
	printf("        |||                             |      RETOUR                    |                               |||   \n");
	printf("        |||                             |             SUR LE             |                               |||   \n");
	printf("        \\|/                             |                   MENU         |                               \\|/ \n");
	printf("         V                        ______|================================|______                          V    \n");
	printf("                                  \\______________|====O    O====|______________/                              \n");
	printf("\n");
	printf("                                             Press Enter to continue                                           \n");

	while(verif != '\n'){
		scanf("%c", &verif);
	}
	//Menu_Jeu(matrice);
}

void continuer(int matrice[N][N]){
	int pvJoueur=joueur.vie.sante;
	int manaJoueur=joueur.vie.mana;
	int enduJoueur=joueur.vie.endu;
	int pvMob=30;
	int cptx, cpty;
	
	rechercheJoueur(matrice);
	sorti=ma_position;
	affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob);
		
	while(matrice[ma_position.x][ma_position.y] != OBJECTIF && quitter != 1){
		
		if(pvMob>0){
				IA(matrice, &pvJoueur);
				affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob);
		}
		else if(pvMob<=0){
			for(cptx=0 ; cptx<N ; cptx++){
				for(cpty=0 ; cpty<N ; cpty++){
					if(matrice[cptx][cpty]==MOB){
						matrice[cptx][cpty]=CHEMIN;
						break;
					}
				}
			}
			printf("\n               ==> Vous avez tue le mob <==               \n");
		}
		deplacement_perso(matrice, &pvMob, &enduJoueur, &joueur);
		affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob);
		
		if(coffre(matrice) && pvMob<=0){
			printf("\n         ==> La porte de sortie est deverouillée <==         \n");
			matrice[sorti.x][sorti.y] = OBJECTIF;
		}
		if(enduJoueur<100){
			enduJoueur+=3;
		}
		if(enduJoueur<0){
			enduJoueur=0;
		}
		if(pvJoueur<=0){
			defeat(matrice);
			statcombat.defaite++;
			break;
		}

	}
	victory(matrice);
	statcombat.victoire++;
	cpt_laby++;
	
	if((cpt_laby%2)==0){
		attribution_points(&joueur, 0, 1);
	}
	else if((cpt_laby%5)==0){
		attribution_points(&joueur, 1, 0);
	}
}
