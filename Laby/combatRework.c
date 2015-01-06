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
extern int matrice[N][N];

t_coordonees mes_choix[4];
t_coordonees ma_position;
t_coordonees sorti;

/**
* \fn void guerison(t_joueur*joueur, int*pvJoueur, int*manaJoueur, int pvMax)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande de guerison
**/
void guerison(t_joueur*joueur, int*pvJoueur, int*manaJoueur, int pvMax){
	int cptSoin=(*joueur).magie.guerison;
	int puisMag=(*joueur).comp.puissance;
	int Soin = (1.5*cptSoin)+(0.10*puisMag);
	
	if(*manaJoueur>15){
		*manaJoueur-=15;
		if(*manaJoueur<=0){	*manaJoueur=0;	}
	
		*pvJoueur+=Soin;
		if(*pvJoueur>=pvMax){	*pvJoueur=pvMax;	}
		printf("\r\n      ==> Vous regagnez %i points de vie <==\r\n", Soin);
	}
	else {
		printf("\r\n      ==> Vous n'avez aps assez de mana <== \r\n");
	}
}

/**
* \fn void destruction(int matrice[N][N], t_coordonees ma_position, int*pvMob,t_joueur*joueur, int*manaJoueur)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande de destruction
**/
void destruction(int matrice[N][N], t_coordonees ma_position, int*pvMob,t_joueur*joueur, int*manaJoueur){
	int cptdest=(*joueur).magie.destruction;
	int puisMag=(*joueur).comp.puissance;
	int Destruction=cptdest+(0.5*puisMag);
	int x = ma_position.x;
	int y = ma_position.y;
	
	if(*manaJoueur>20){
		
		*manaJoueur-=20;
		if(*manaJoueur<=0){	*manaJoueur=0;	}
		if(matrice[x-1][y]==MOB||matrice[x+1][y]==MOB||matrice[x][y-1]==MOB||matrice[x][y+1]==MOB){
			*pvMob-=Destruction;
			if(*pvMob<=0){	*pvMob=0;	}
			printf("\r\n      ==> Vous infligez %i points de degat <==\r\n", Destruction);
		}
		else{
			printf("\r\n      ==> Vous infligez %i points de degat <==\r\n", Destruction);
			printf("\r\n                 ==> Dans le vide <==\r\n");
		}
	}
	else{
		printf("\r\n    ==> Vous n'avez pas assez de mana <== \r\n");
	}
}

/**
* \fn void degatHaut(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande d'attaque vers le haut, elle influt aussi sur les données du monstre
**/
void degatHaut(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	//si le joueur est en mode CaC ses degat changent et peut critique
	if(*distance==0){
		degat=(*joueur).comp.force;
		if((*enduJoueur-15)>=0){
			*enduJoueur-=15;
			if(matrice[x-1][y]==MOB){
				if(critique>=100){
					degat*=2;
					printf("\r\n            ==> CRITIQUE <==            \r\n");
				}
				printf("\r\n    Vous infligez %i points de degat\r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    frapper dans le vide \r\n");
			}
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour frapper\r\n");
		}
	}
	
	//si le joueur est en mode distance ses degats changent et ne peut pas critique
	else if(*distance==1){
		degat=(*joueur).combat.archerie;
		if((*enduJoueur-25)>=0){
			*enduJoueur-=25;
			
			if(matrice[x-1][y]==MOB||matrice[x-2][y]==MOB||matrice[x-3][y]==MOB||matrice[x+4][y]==MOB){
				printf("\r\n    Vous infligez %i points de degat    \r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    tirer dans le vide    \r\n");
			}
	
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour tirer    \r\n");
		}
	}
}

/**
* \fn void degatGauche(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande d'attaque vers la gauche, elle influt aussi sur les données du monstre
**/
void degatGauche(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	//si le joueur est en mode CaC ses degat changent et peut critique
	if(*distance==0){
		degat=(*joueur).comp.force;
		if((*enduJoueur-15)>=0){
			*enduJoueur-=15;
			if(matrice[x][y-1]==MOB){
				if(critique>=100){
					degat*=2;
					printf("\r\n            ==> CRITIQUE <==            \r\n");
				}
				printf("\r\n    Vous infligez %i points de degat\r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    frapper dans le vide \r\n");
			}
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour frapper\r\n");
		}
	}
	
	//si le joueur est en mode distance ses degats changent et ne peut pas critique
	else if(*distance==1){
		degat=(*joueur).combat.archerie;
		if((*enduJoueur-25)>=0){
			*enduJoueur-=25;
			
			if(matrice[x][y-1]==MOB||matrice[x][y-2]==MOB||matrice[x][y-3]==MOB||matrice[x+4][y]==MOB){
				printf("\r\n    Vous infligez %i points de degat    \r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    tirer dans le vide    \r\n");
			}
	
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour tirer    \r\n");
		}
	}
	
}

/**
* \fn void degatBas(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande d'attaque vers le bas, elle influt aussi sur les données du monstre
**/
void degatBas(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	//si le joueur est en mode CaC ses degat changent et peut critique
	if(*distance==0){
		degat=(*joueur).comp.force;
		if((*enduJoueur-15)>=0){
			*enduJoueur-=15;
			if(matrice[x+1][y]==MOB){
				if(critique>=100){
					degat*=2;
					printf("\r\n            ==> CRITIQUE <==            \r\n");
				}
				printf("\r\n    Vous infligez %i points de degat\r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    frapper dans le vide \r\n");
			}
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour frapper\r\n");
		}
	}
	
	//si le joueur est en mode distance ses degats changent et ne peut pas critique
	else if(*distance==1){
		degat=(*joueur).combat.archerie;
		if((*enduJoueur-25)>=0){
			*enduJoueur-=25;
			
			if(matrice[x+1][y]==MOB||matrice[x+2][y]==MOB||matrice[x+3][y]==MOB||matrice[x+4][y]==MOB){
				printf("\r\n    Vous infligez %i points de degat    \r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    tirer dans le vide    \r\n");
			}
	
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour tirer    \r\n");
		}
	}
}

/**
* \fn void degatDroite(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance)
* \brief Fonction modifiant les données du joueur dans le cas ou celui-ci utilise la commande d'attaque vers la droite, elle influt aussi sur les données du monstre
**/
void degatDroite(int matrice[N][N], t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance){
	int x = ma_position.x;
	int y = ma_position.y;
	int degat;
	srand(time(NULL));
	int critique = (rand()%(100-1)+1)+(*joueur).combat.unemain;
	
	//si le joueur est en mode CaC ses degat changent et peut critique
	if(*distance==0){
		degat=(*joueur).comp.force;
		if((*enduJoueur-15)>=0){
			*enduJoueur-=15;
			if(matrice[x][y+1]==MOB){
				if(critique>=100){
					degat*=2;
					printf("\r\n            ==> CRITIQUE <==            \r\n");
				}
				printf("\r\n    Vous infligez %i points de degat    \r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    frapper dans le vide    \r\n");
			}
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour frapper    \r\n");
		}
	}
	
	//si le joueur est en mode distance ses degats changent et ne peut pas critique
	else if(*distance==1){
		degat=(*joueur).combat.archerie;
		if((*enduJoueur-25)>=0){
			*enduJoueur-=25;
			
			if(matrice[x][y+1]==MOB||matrice[x][y+2]==MOB||matrice[x][y+3]==MOB||matrice[x+4][y]==MOB){
				printf("\r\n    Vous infligez %i points de degat    \r\n", degat);
				*pvMob-=degat;
				if(*pvMob<=0){	*pvMob=0;	}
			}
			else{
				printf("\r\n    tirer dans le vide    \r\n");
			}
	
		}
		else{
			printf("\r\n    Vous ètes trop fatiguer pour tirer    \r\n");
		}
	}
}
