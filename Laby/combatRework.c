/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris Toulmonde, Godefroy Thieulart
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "accueil.h"
#include "IA.h"
#include "region.h"

#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5

extern int quitter;
extern char region[N][N];

t_coordonees mes_choix[4];
t_coordonees ma_position;
t_coordonees sorti;

void degatHaut(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat=(*joueur).comp.force;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	if(*enduJoueur>=10){
		*enduJoueur-=15;
		if(matrice[x-1][y]==MOB){
			if(critique>=100){
				degat*=2;
				printf("\n==> CRITIQUE <==\n");
			}
			printf("\n Vous infligez %i points de degat\n", degat);
			*pvMob-=degat;
			if(*pvMob<=0){	*pvMob=0;	}
		}
		else{
			printf("\n frapper dans le vide \n");
		}
	}
	else{
		printf("\n Vous ètes trop fatiguer pour frapper\n");
	}
}

void degatGauche(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat=(*joueur).comp.force;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	if(*enduJoueur>=10){
		*enduJoueur-=15;
		if(matrice[x][y-1]==MOB){
			if(critique>=100){
				degat*=2;
				printf("\n==> CRITIQUE <==\n");
			}
			printf("\n Vous infligez %i points de degat\n", degat);
			*pvMob-=degat;
			if(*pvMob<=0){	*pvMob=0;	}
		}
		else{
			printf("\n frapper dans le vide \n");
		}
	}
	else{
		printf("\n Vous ètes trop fatiguer pour frapper\n");
	}
}

void degatBas(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat=(*joueur).comp.force;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	if(*enduJoueur>=10){
		*enduJoueur-=15;
		if(matrice[x+1][y]==MOB){
			if(critique>=100){
				degat*=2;
				printf("\n==> CRITIQUE <==\n");
			}
			printf("\n Vous infligez %i points de degat\n", degat);
			*pvMob-=degat;
			if(*pvMob<=0){	*pvMob=0;	}
		}
		else{
			printf("\n frapper dans le vide \n");
		}
	}
	else{
		printf("\n Vous ètes trop fatiguer pour frapper\n");
	}
}

void degatDroite(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat=(*joueur).comp.force;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	if(*enduJoueur>=10){
		*enduJoueur-=15;
		if(matrice[x][y+1]==MOB){
			if(critique>=100){
				degat*=2;
				printf("\n==> CRITIQUE <==\n");
			}
			printf("\n Vous infligez %i points de degat\n", degat);
			*pvMob-=degat;
			if(*pvMob<=0){	*pvMob=0;	}
		}
		else{
			printf("\n frapper dans le vide \n");
		}
	}
	else{
		printf("\n Vous ètes trop fatiguer pour frapper\n");
	}
}
