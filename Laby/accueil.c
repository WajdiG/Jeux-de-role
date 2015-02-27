/**
 *\file accueil.c
 *\brief fonctions gérant l'interface du jeu
 *\author Godefroy THIEULART
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

int quitter = 0; /**< variable permettant de quitter le jeu */
int cpt_laby=0; /**< compteur du nombre de labyrinthe réalisé par le joueur */
extern t_joueur joueur;
extern t_coordonees ma_position;
extern t_coordonees sorti;
extern t_statcombat statcombat;

/**
* \fn void ecran_accueil()
* \brief Fonction d'affichage de l'écran d'accueil du jeu.
**/
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

/**
* \fn void Option_jeu(int matrice[N][N])
* \brief Fonction d'affichage du premier ecran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu(int matrice[N][N]){
	int verif = -1;
	
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                        ______________________________________________        |||   \n");
	printw("        |||                                       //                                            \\\\       ||| \n");
	printw("        |||                   |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printw("        |||                   |Z           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printw("        |||                   |   pour     |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printw("        |||                   |      monter|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printw("        |||                   |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|  |============|  |============|              |======|    |============|     |||   \n");
	printw("        |||   |Q           |  | S          |  |D           |              | -4-  |    |    -5-     |     |||   \n");
	printw("        |||   |   pour     |  |   pour     |  |   pour     |              |      |    |Retour      |     |||   \n");
	printw("        |||   |   la gauche|  |   descendre|  |   la droite|              |Next  |    |    au  menu|     |||   \n");
	printw("        |||   |============|  |============|  |============|              |======|    |============|     |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |            VEUILLEZ            |                               |||   \n");
	printw("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printw("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");
	refresh();
	
	while(verif < '4' || verif > '5'){
		verif=getch();
	}
	printw("\n");
	switch(verif){
		case '4' : Option_jeu_2(matrice); break;
		case '5' : Menu_Jeu(matrice); break;
	}
}

/**
* \fn void Option_jeu_2(int matrice[N][N])
* \brief Fonction d'affichage du second écran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu_2(int matrice[N][N]){
	int verif = -1;
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                        ______________________________________________        |||   \n");
	printw("        |||                                       //                                            \\\\       ||| \n");
	printw("        |||                   |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printw("        |||                   |I           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printw("        |||                   | pour taper |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printw("        |||                   |     en haut|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printw("        |||                   |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|  |============|  |============|    |======|  |======|    |============|     |||   \n");
	printw("        |||   |J           |  | K          |  |L           |    | -3-  |  | -4-  |    |    -5-     |     |||   \n");
	printw("        |||   | pour taper |  | pour taper |  | pour tapper|    |      |  |      |    |Retour      |     |||   \n");
	printw("        |||   |    à gauche|  |      en bas|  |    à droite|    |Prev  |  |Next  |    |    au  Menu|     |||   \n");
	printw("        |||   |============|  |============|  |============|    |======|  |======|    |============|     |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |            VEUILLEZ            |                               |||   \n");
	printw("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printw("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");

	while(verif < '3' || verif > '5'){
		verif=getch();
	}
	printw("\n");
	switch(verif){
		case '3' : Option_jeu(matrice); break;
		case '4' : Option_jeu_3(matrice); break;
		case '5' : Menu_Jeu(matrice); break;
	}
}

/**
* \fn void Option_jeu_3(int matrice[N][N])
* \brief Fonction d'affichage du troisième écran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu_3(int matrice[N][N]){
	int verif = -1;
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                        ______________________________________________        |||   \n");
	printw("        |||                                       //                                            \\\\       ||| \n");
	printw("        |||   |============|  |============|      H    IIII  IIII  IIIIII IIII  IIII  III   II   H       |||   \n");
	printw("        |||   |U           |  |O           |      H   II  II II II   II    II  II  II IIII  II   H       |||   \n");
	printw("        |||   |Sortilege   |  |Sortilege   |      H   II  II IIII    II    II  II  II II II II   H       |||   \n");
	printw("        |||   |     de Soin|  |   d'Attaque|      H   II  II II      II    II  II  II II  IIII   H       |||   \n");
	printw("        |||   |============|  |============|      U    IIII  II      II   IIII  IIII  II   III   U       |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|   |==========================|     |======|              |============|     |||   \n");
	printw("        |||   |N           |   |         SPACEBAR         |     | -3-  |              |    -5-     |     |||   \n");
	printw("        |||   |Distance    |   |  Parade de la prochaine  |     |      |              |Retour      |     |||   \n");
	printw("        |||   |      ON/OFF|   |      attaque ennemi      |     |Prev  |              |    au  Menu|     |||   \n");
	printw("        |||   |============|   |==========================|     |======|              |============|     |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                             |================================|                               |||   \n");
	printw("        |||                             |            VEUILLEZ            |                               |||   \n");
	printw("        |||                             |          FAIRE  VOTRE          |                               |||   \n");
	printw("        \\|/                             |             CHOIX              |                               \\|/ \n");
	printw("         V                        ______|================================|______                          V    \n");
	printw("                                  \\______________|====O    O====|______________/                              \n");
	printw("\n");

	while(verif < '3' || verif > '5'){
		verif=getch();
	}
	printw("\n");
	switch(verif){
		case '3' : Option_jeu_2(matrice); break;
		case '5' : Menu_Jeu(matrice); break;
	}
}

/**
* \fn void Menu_Jeu(int matrice[N][N])
* \brief Fonction d'affichage du menu de jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Menu_Jeu(int matrice[N][N]){
	int verif=-1;
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||                                                                                              |||   \n");
	printw("        |||   |============|    |============|                      |============|    |============|     |||   \n");
	printw("        |||   |    -1-     |    |    -2-     |                      |    -4-     |    |    -5-     |     |||   \n");
	printw("        |||   |Nouvelle    |    |Charger     |                      |Commande    |    |Quitter     |     |||   \n");
	printw("        |||   |      Partie|    |      Partie|                      |      du jeu|    |     le jeu |     |||   \n");
	printw("        |||   |============|    |============|                      |============|    |============|     |||   \n");
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
		verif=getch();
	}
	printw("\n");
	switch(verif){
		case '1' : nouvelle_partie(matrice); Menu_Jeu(matrice); break;
		case '2' : charger_par(matrice); Menu_Jeu(matrice); break;
		case '4' : Option_jeu(matrice); break ;
		case '5' : Quitter_Jeu(); break;
	}
}

/**
* \fn void Quitter_Jeu()
* \brief Fonction de l'écran de fermeture du jeu.
**/
void Quitter_Jeu(){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
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

/**
* \fn void defeat(int matrice[N][N])
* \brief Fonction d'affichage de l'écran de jeu en cas de défaite du joueur.
* \return void
**/
void defeat(){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
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

/**
* \fn void victory(int matrice[N][N])
* \brief Fonction d'affichage de l'écran du jeu en cas de victoire du joueur.
* \return void
**/
void victory(){
	char verif='a';
	clear();
	printw("\n");
	printw("\n");
	printw("         O                   IIII   IIII   IIII   II  II IIIIII II   IIII II  II IIIIII                   O    \n");
	printw("         H                   II II II  II II  II  II  II II     II    II  II II  II                       H    \n");
	printw("         H                   IIII  II  II II      II  II IIII   II    II  III    IIII                     H    \n");
	printw("         H                   III   II  II II  III II  II II     II    II  II II  II                       H    \n"); 
	printw("         H                   II II  IIII   IIII I  IIII  IIIIII IIII IIII II  II IIIIII ©                H     \n");
	printw("        /H\\                                                                                              /H\\ \n");
	printw("       <HUH>            _______GUEDOUAR_Wajdi-THIEULART_Godefroy-TOULMONDE_Joris________                <HUH>  \n");
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

/**
* \fn int continuer(int matrice[N][N])
* \brief Fonction faisant tourner le labyrinthe du programme
* \param matrice[N][N] est la matrice contenant le labyrinthe
* \return renvoie 1 si le joueur meurt, renvoie 0 sinon
**/
int continuer(int matrice[N][N]){
	
	//initialisation des statistiques du joueur
	int pvJoueur=joueur.vie.sante+joueur.comp.force;
	int pvMax=pvJoueur;
	int manaJoueur=joueur.vie.mana+joueur.comp.intelligence;
	int enduJoueur=joueur.vie.endu+joueur.comp.agilite;
	int enduMax=enduJoueur;
	
	//initialisation des statistiques du mob
	int pvMob=30+(2*cpt_laby);
	
	int cptx, cpty;
	int parade=0;
	int distance=0;
	
	rechercheJoueur(matrice);
	sorti=ma_position;
	affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob, cpt_laby, &parade, &distance);
		
	while(matrice[ma_position.x][ma_position.y] != OBJECTIF && quitter != 1){
		
		//tour du joueur
		deplacement_perso(&parade, &distance, matrice, &pvMob, &enduJoueur, &pvJoueur, &manaJoueur, &joueur, pvMax);
		
		//tour du mob si celui-ci est vivant (plus de 0 PV)
		if(pvMob>0){
				IA(matrice, &pvJoueur, &parade, &enduJoueur,cpt_laby);
				affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob, cpt_laby, &parade, &distance);
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
			printf("\r\n               ==> Vous avez tué le mob <==               \r\n");
		}
		
		//affiche l'écran de défaite dans le cas ou le joueur perd toute sa vie
		if(pvJoueur<=0){
			defeat(matrice);
			statcombat.defaite++;
			return 1;
		}
		affichage(matrice, pvJoueur, manaJoueur, enduJoueur, pvMob, cpt_laby, &parade, &distance);
		
		//vérifie si des coffres sont toujours présents dans le niveau, affiche la sortie si non
		if(coffre(matrice) && pvMob<=0){
			printf("\r\n         ==> La porte de sortie est deverouillée <==         \r\n");
			
			matrice[sorti.x][sorti.y] = OBJECTIF;
		}
		//réactualise l'endurance du joueur
		if(enduJoueur<100){	enduJoueur+=3;	}
		if(enduJoueur>enduMax){	enduJoueur=enduMax;	}
		if(enduJoueur<=	0){	enduJoueur=0;	}
		
	}
	
	//affiche l'écran de victoire si le joueur est vivant et a récuperé tout les coffres/tué le mob/pris la sortie
	if(quitter!=1){
		if(pvJoueur>0){
			victory(matrice);
			statcombat.victoire++;
		}
	
		//permet d'augmenter le niveau du joueur (et de son adversaire)
		cpt_laby++;
		if((cpt_laby%1)==0){
			clear();
			attribution_points(&joueur, 0, 1);
		}
		else if((cpt_laby%2)==0){
			clear();
			attribution_points(&joueur, 1, 0);
		}	
	}
	return 0;
}
