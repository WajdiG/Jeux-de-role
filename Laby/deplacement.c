/**
*\file deplacement.c
*\brief Regroupe les fonctions nécéssaires aux deplacements des entités et au démarrage du jeu
*\author Joris Toulmonde, Godefroy THIEULART 
*\version 0.1
*\date 25 Novembre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "accueil.h"
#include "IA.h"
#include "region.h"
#include "combatRework.h"
#include "JDR1_0.h"
#include "deplacement.h"

extern int quitter; /**< Variable pour savoir si on quitte le jeu */
extern char region[N][N]; /**< matrice représentant une région */


t_coordonees ma_position; /**< Structure modélisant les coordonnées de la case courante du joueur*/
t_coordonees sorti; /**< Structure modélisant les coordonnées de la sortie*/

/**
* \fn void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob, int cpt_laby, int*parade, int*distance)
* \brief Fonction permettant l'affichage de la carte à chaque tour.
* \param matrice[N][N] matrice où chaque case contient soit un mur, un chemin, un joueur, un coffre ou un monstre
* \param pvJoueur les points de vie du joueur
* \param manaJoueur représentant le mana du joueur
* \param enduJoueur représentant l'endurance du joueur
* \param pvMob représentant les points de vie du monstre
* \param cpt_laby représente le niveau du labyrinthe
* \param *parade represente les points de parade du joueur
* \param *distance est fait pour gérer le mode distance (archerie)
**/
void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob, int cpt_laby, int*parade, int*distance){
	int i, j;
	system("clear");
	
	if(cpt_laby<10){
		printf("\r\nO=============Le=niveau=du=Labyrinthe=est=de=%i==============O\r\n\n", cpt_laby);
	}
	else{
		printf("\r\nO=============Le=niveau=du=Labyrinthe=est=de=%i==============O\r\n\n", cpt_laby);
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
                switch(matrice[i][j]){
                    case(MUR) : printf("|-|"); break;
                    case(CHEMIN) : printf("   "); break;
                    case(JOUEUR) : printf("*_*"); break;
                    case(COFFRE) : printf("[C]"); break;
                    case(OBJECTIF) : printf(" X "); break;
                    case(MOB) : printf("X_X"); break;
                }
		}
		printf("\r\n");
	}

		if(pvJoueur>=100){printf("\nPV : %i                                         PV Mob = %i \r\n", pvJoueur, pvMob);}
		else if(pvJoueur>9 && pvJoueur<100){printf("\nPV : %i                                           PV Mob = %i \r\n", pvJoueur, pvMob);}
		else if(pvJoueur<10){printf("\nPV : %i                                             PV Mob = %i \r\n", pvJoueur, pvMob);}
		printf("Mana : %i \r\n", manaJoueur);
		printf("Endurance : %i \r\n", enduJoueur);
		if(*distance==1){
			printf("distance activée");
		}
		else if(*distance==0){
			printf("distance désactivée");
		}
		printf("\r\n\nO=====================Boite=A=Dialogue========================O\r\n");
		
		if(*parade==1){
			printf("\r\n         ==> Vous parez le prochain coup <== \r\n");
		}
}

/**
* \fn void rechercheJoueur(int matrice[N][N])
* \brief Fonction qui recherche les coordonnées du joueur sur la carte
* \param matrice[N][N] matrice où chaque case contient soit un mur, un chemin, un joueur, un coffre ou un monstre
**/
void rechercheJoueur(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0 ; cptx<N ; cptx++){
		for(cpty=0 ; cpty<N ; cpty++){
			if(matrice[cptx][cpty]==JOUEUR){
				ma_position.x=cptx;
				ma_position.y=cpty;
			}
		}
	}
}

/**
* \fn void deplacement_perso(int*parade, int*distance,int matrice[N][N], int*pvMob, int*enduJoueur, int*pvJoueur, int*manaJoueur, t_joueur*joueur,int pvMax)
* \brief Fonction permettant de deplacer le joueur a chaque tour ou le faire agir
* \param matrice[N][N] Matrice où chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void deplacement_perso(int*parade, int*distance,int matrice[N][N], int*pvMob, int*enduJoueur, int*pvJoueur, int*manaJoueur, t_joueur*joueur,int pvMax){
	
        t_coordonees tampon;
		int x;
		
		x = getch();
		tampon.x = ma_position.x;
        	tampon.y = ma_position.y;

		switch(x){
			
			//fait bouger le joueur dans la direction voulue
			case 'z' : *parade=0 ; ma_position.x-- ; break;
			case 'q' : *parade=0 ; ma_position.y-- ; break;
			case 's' : *parade=0 ; ma_position.x++ ; break;
			case 'd' : *parade=0 ; ma_position.y++ ; break;
			
			//fait attaquer le joueur dans la direction voulue
			case 'i' : *parade=0 ; degatHaut(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'j' : *parade=0 ; degatGauche(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'k' : *parade=0 ; degatBas(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'l' : *parade=0 ; degatDroite(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			
			//permet au joueur d'utiliser sa magie
			case 'u' : *parade=0 ; guerison(joueur, pvJoueur, manaJoueur,pvMax) ; break;
			case 'o' : *parade=0 ; destruction(matrice, ma_position,pvMob, joueur, manaJoueur) ; break;
			
			//commande secondaire du joueur
			case ' ' : *parade=1 ; *distance=0 ; break;
			case 'n' : *parade=0 ;
						if(*distance==1){	*distance=0 ;	}
						else if(*distance==0){	*distance=1 ;	} break;
		}
		
		//empèche le joueur de marcher sur les murs ou sur le mob et libère le chemin derrière lui
		if(matrice[ma_position.x][ma_position.y] == MUR){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else if(matrice[ma_position.x][ma_position.y] == MOB){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else{
			matrice[tampon.x][tampon.y] = CHEMIN;
			matrice[ma_position.x][ma_position.y]=JOUEUR;
		}	
		refresh();      
}

/**
* \fn int coffre(int matrice[N][N])
* \brief Fonction permettant de voir s'il y a des coffres sur la carte
* \param matrice[N][N] Matrice où chaque case contient soit un mur, un joueur, un chemain, un coffre ou un monstre
* \return Renvoi 1 s'il n'y a plus de coffre sur la carte
**/
int coffre(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		for(cpty=0;cpty<N;cpty++){
			if(matrice[cptx][cpty]==COFFRE){
				return 0;
			}
		}
	}
	return 1;
}

/**
* \fn void jouer()
* \brief Fonction permettant d'afficher le menu du jeu
**/
void jouer(){
	int matrice[N][N];
	
	ecran_accueil();
	Menu_Jeu(matrice); 		
}

int main(){
	srand(time(NULL));
	initscr();
	raw();
	keypad(stdscr,TRUE);
	init_monde();
	jouer();
	endwin();
	return EXIT_SUCCESS;
	
}
