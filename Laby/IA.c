/**
 *\file IA.c
 *\brief fichier contenant les fonctions liées à l'intelligence artificielle des mobs
 *\author Godefroy THIEULART
 *\version 0.2
 *\date 01 Novembre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <assert.h>
#include "accueil.h"
#include "pile_tab.h"
#include "deplacement.h"
#define N 20 /**< Taille de la matrice region*/
#define MUR 0 /**< Entier modélisant un mur*/
#define CHEMIN 1 /**< Entier modélisant le chemin à emprunter disponible pour le joueur et le monstre*/
#define COFFRE 2 /**< Entier modélisant un coffre*/
#define JOUEUR 3 /**< Entier modélisant le joueur*/
#define OBJECTIF 4 /**< Entier modélisant un objectif*/
#define MOB 5 /**< Entier modélisant un monstre*/


int vision[N][N]; /**< matrice contenant la matrice tel qu'elle est vue par l'IA */
extern t_joueur joueur; /**< variable de type t_joueur contenant toutes les données de l'avatar du joueur */

/**
* \fn void tradRandom(int matrice[N][N], char region[N][N])
* \brief Fonction permettant de traduire la matrice générer aléatoirement en matrice lisible par le programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemain, un coffre ou un monstre
* \param region[N][N] Matrice de caractère ou chaque case contient soit un mur, un coffre ou un monstre
**/
void tradRandom(int matrice[N][N], char region[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		for(cpty=0;cpty<N;cpty++){
		        switch(region[cptx][cpty]){
		            case('X') : matrice[cptx][cpty]=MUR ; break;
		            case(' ') : matrice[cptx][cpty]=CHEMIN; break;
		            case('P') : matrice[cptx][cpty]=JOUEUR; break;
		            case('C') : matrice[cptx][cpty]=COFFRE; break;
		            case('M') : matrice[cptx][cpty]=MOB; break;
		        }
		}
	}
}

/**
* \fn void tradVision(int matrice[N][N])
* \brief Fonction permettant de traduire la carte du jeu en carte lisible par l'IA du jeu dans une nouvelle matrice
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void tradVision(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		for(cpty=0;cpty<N;cpty++){
		        switch(matrice[cptx][cpty]){
		            case(MUR) : vision[cptx][cpty]=-8; break;
		            case(CHEMIN) : vision[cptx][cpty]=-1; break;
		            case(JOUEUR) : vision[cptx][cpty]=-2; break;
		            case(COFFRE) : vision[cptx][cpty]=-3; break;
		            case(OBJECTIF) : vision[cptx][cpty]=-4; break;
		            case(MOB) : vision[cptx][cpty]=0; break;
		        }
		}
	}
}

/**
* \fn void affVision2(int matrice[N][N])
* \brief Fonction permettant d'afficher la matrice contenant la vision de l'IA, mais en plus simplifié, celle-ci n'a été utilisé que durant la conception du programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void affVision2(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	clear();
	
	for(cptx=0;cptx<N;cptx++){
		printw("\n");
		for(cpty=0;cpty<N;cpty++){
		        switch(matrice[cptx][cpty]){
		            case(-8) : printw("|-|"); break;
		            case(-1) : printw("   "); break;
		            case(-2) : printw("*_*"); break;
		            case(-3) : printw("[C]"); break;
		            case(-4) : printw(" X "); break;
		            case(0) : printw(">_<"); break;
		        }
            		if(matrice[cptx][cpty]>0 && matrice[cptx][cpty]<=9){
				printw(" %i ", matrice[cptx][cpty]);
			}
			else if(matrice[cptx][cpty]>9){
				printw(" %i", matrice[cptx][cpty]);
			}
		}
	}
	printw("\n");
}

/**
* \fn void affVision(int matrice[N][N])
* \brief Fonction permettant d'afficher la matrice contenant la vision de l'IA, à l'état brute, celle-ci n'a été utilisé que durant la conception du programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void affVision(int matrice[N][N]){
	int cptx=0;
	int cpty=0;

	for(cptx=0;cptx<N;cptx++){
		printw("\n");
		for(cpty=0;cpty<N;cpty++){
			if(matrice[cptx][cpty]>=0 && matrice[cptx][cpty]<=9){
				printw(" %i ", matrice[cptx][cpty]);
			}
			else if(matrice[cptx][cpty]>9){
				printw(" %i", matrice[cptx][cpty]);
			}
			else{
				printw("%i ", matrice[cptx][cpty]);
			}
		}
	}

	printf("\n");
}

/**
* \fn void trouverMob(int*mobx, int*moby)
* \brief Fonction permettant de chercher les coordonnées de l'IA sur la matrice de jeu
* \param *mobx qui contiendra la coordonnées x de l'IA dans la matrice 
* \param *moby qui contiendra la coordonnée y de l'IA
**/
void trouverMob(int *mobx, int *moby){
	int cptx;
	int cpty;
	int sorti=0;
	int mob=0;
	
	for(cptx=0 ; cptx<N && !sorti ; cptx++){
		for(cpty=0 ; cpty<N && !sorti ; cpty++){	
					
			if(vision[cptx][cpty]==mob){
				*mobx=cptx;
				*moby=cpty;
			}
			
		}
	}
}

/**
* \fn void resetMob()
* \brief Fonction permettant de réinitialiser la vision de l'IA, nous permettant par la suite de la mettre à jour
**/
void resetMob(){
	int cptx, cpty;
	int sorti=0;
	
	for(cptx=0;cptx<N && !sorti;cptx++){
		for(cpty=0;cpty<N && !sorti;cpty++){
			if(vision[cptx][cpty]>0){
				vision[cptx][cpty]=-1;
			}
		}
	}
}

/**
* \fn t_coordonees ecrireChemin()
* \brief Fonction qui génèrera les chemin que l'IA pourra emprunter pour rejoindre le joueur sur la carte
* \return renvoi un structure contenant les coordonnées de la case adjacente au joueur
**/
t_coordonees ecrireChemin(){
	t_coordonees cheminRetour;
	int cptx,cpty;
	int chemin=0;
	
	while(1){
		for(cptx=0;cptx<N;cptx++){
			for(cpty=0;cpty<N;cpty++){
				
				if(vision[cptx][cpty]==chemin){
					
					// le joueur est à coté de notre case -> on arrète
					if((vision[cptx][cpty-1]==-2) || (vision[cptx][cpty+1]==-2) || (vision[cptx-1][cpty]==-2) || (vision[cptx+1][cpty]==-2)){
						cheminRetour.x=cptx;
						cheminRetour.y=cpty;
						return cheminRetour;
					}
					else {
						if(vision[cptx][cpty-1]==-1){
							vision[cptx][cpty-1]=chemin+1;
						}
						if(vision[cptx][cpty+1]==-1){
							vision[cptx][cpty+1]=chemin+1;
						}
						if(vision[cptx-1][cpty]==-1){
							vision[cptx-1][cpty]=chemin+1;
						}
						if(vision[cptx+1][cpty]==-1){
							vision[cptx+1][cpty]=chemin+1;
						}
					}	
						
				}				
			}
		}
		chemin++;	
	}
}

/**
* \fn int MobNextToJoueur(int mobx, int moby)
* \brief Fonction permettant de savoir si l'IA est en contact avec le joueur afin de décider de l'action à faire
* \return renvoie 1 si l'IA se trouve sur une case adjacente au joueur, renvoie 0 autrement
**/
int MobNextToJoueur(int mobx, int moby){
	int cptx;
	int cpty;
	int sortis=0;
	int joueur=-2;
	int mob=0;
	
	for(cptx=0 ; cptx<N && !sortis ; cptx++){
		for(cpty=0 ; cpty<N && !sortis ; cpty++){	
			if(vision[cptx][cpty]==mob){
				mobx=cptx;
				moby=cpty;
				break;
			}
		}
	}
	
	if(vision[mobx+1][moby]==joueur){return 1;}
	else if(vision[mobx-1][moby]==joueur){return 1;}
	else if(vision[mobx][moby+1]==joueur){return 1;}
	else if(vision[mobx][moby-1]==joueur){return 1;}
	else {return 0;}
}

// empile les cases à suivre par le monstre pour arriver au joueur
// cheminRetour = case cible (juste à coté du joueur)
/**
* \fn void lireChemin(t_coordonees cheminRetour)
* \brief Fonction permettant de chercher le chemin le plus rapide pour que l'IA puisse rejoindre le joueur
* \param cheminRetour contient les coordonnées de la case se trouvant à coté du joueur
**/
void lireChemin(t_coordonees cheminRetour){
	int arrive=0;
	initpileStruct();
	empilerStruct(cheminRetour);
	
	
	while(arrive!=1){

		if((vision[cheminRetour.x][cheminRetour.y-1]==0) || (vision[cheminRetour.x][cheminRetour.y+1]==0) || (vision[cheminRetour.x-1][cheminRetour.y]==0) || (vision[cheminRetour.x+1][cheminRetour.y]==0)){ //on est à coté du monstre
			arrive=1;
		}
		else {
			if(vision[cheminRetour.x][cheminRetour.y-1]==vision[cheminRetour.x][cheminRetour.y]-1){
				cheminRetour.y--;
				
			}
			else if(vision[cheminRetour.x][cheminRetour.y+1]==vision[cheminRetour.x][cheminRetour.y]-1){
				cheminRetour.y++;
			}
			else if(vision[cheminRetour.x-1][cheminRetour.y]==vision[cheminRetour.x][cheminRetour.y]-1){
				cheminRetour.x--;
			}
			else if(vision[cheminRetour.x+1][cheminRetour.y]==vision[cheminRetour.x][cheminRetour.y]-1){
				cheminRetour.x++;
			}
			empilerStruct(cheminRetour);
		}
	}
}

//déplace le mob sur une case en direction du joueur
/**
* \fn void IA(int matrice[N][N], int*pvJoueur, int*parade, int*enduJoueur, int cpt_laby)
* \brief Fonction responsable de la totalité de l'IA, de ses choix et de ses actions
* \param matrice[N][N] est la matrice contenant le jeu
* \param *pvJoueur est un pointeur contenant les PV du joueur et nous permettant de les modifiés
* \param parade contient une valeur booléenne afin de savoir si le joueur s'est mis en parade, modifiera le calcul des dégats subis
* \param *enduJoueur est la variable pointeur contenant l'endurance du joueur permettant de les modifié
* \param cpt_laby est une variable contenant le nombre de labyrinthe réussi par le joueur, celle-ci permettra de determiner la difficulté de l'IA
**/
void IA(int matrice[N][N], int*pvJoueur, int*parade, int*enduJoueur, int cpt_laby){
	int mobx;
	int moby;
	int attaque=0;
	int degat=10+(2*cpt_laby);
	int degatBrut=degat;
	
	t_coordonees cheminRetour;
	t_coordonees resultat;
	
	srand(time(NULL));
	
	int critique = (rand()%(100-1)+1)+(2.5*cpt_laby);
	int reducDegat;
	int paradeJoueur = joueur.combat.parade;
	int degatBloquer=degatBrut-paradeJoueur;
	
	//choisi la statistique la plus élever entre armureleg et armurelou pour determiner la reduction des dégats
	if(joueur.combat.armureleg>=joueur.combat.armurelou){
		reducDegat = joueur.combat.armureleg;
	}
	else{
		reducDegat = joueur.combat.armurelou;
	}
	
	tradVision(matrice);
	resetMob();
	trouverMob(&mobx, &moby);
	
	attaque=MobNextToJoueur(mobx, moby);						//détermine si le joueur et le mob sont côte à côte et savoir par la suite l'action de l'IA

	//fait deplacer le mob si celui-ci n'est pas à coté du joueur
	if(attaque==0){
		cheminRetour=ecrireChemin();
		lireChemin(cheminRetour);
		depilerStruct(&resultat);
		matrice[resultat.x][resultat.y]=MOB; 		//déplacer le MOB sur la case en direction du joueur
		matrice[mobx][moby]=CHEMIN; 				//libérer le chemin derrière le MOB
	}
	
	//inflige des dégats au joueur en fonction de ses compétences si le mob est à coté de celui-ci
	else if(attaque==1){
		degat=degat-(0.25*reducDegat);
		if(critique>=100){
			degat*=2;
			printw("\r\n            ==> CRITIQUE <==            \r\n");
		}
		if(*parade==0){
			*pvJoueur-=degat;
			printw("\r\n     /!\\ Vous perdez %i PV /!\\\r\n", degat);
		}
		else if(*parade==1 && degatBrut<*enduJoueur){
			
			if(degatBloquer<=0){	
				*pvJoueur-=0;
				*enduJoueur-=degatBrut;
			}
			
			else{
				*enduJoueur-=degatBrut;
				*pvJoueur-=degatBloquer;
			}
			printw("\r\n      /!\\ Vous parez le prochain coup /!\\ \r\n");
		}
	}

	
	
}


