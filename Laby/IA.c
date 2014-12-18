/**
 *\file IA.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris Toulmonde, Godefroy Thieulart
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <assert.h>
#include "accueil.h"
#include "pile_tab.h"
#include "deplacement.h"
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5
//typedef enum { MUR, CHEMIN, COFFRE, JOUEUR, OBJECTIF, MOB } t_case;
//typedef enum { JOUEUR=-2, , MOB=0, MUR, CHEMIN, COFFRE, OBJECTIF } t_case_vision;

int vision[N][N];
extern t_joueur joueur;

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

/*void affVision(int matrice[N][N]){
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
}*/

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

//calcule le chemin du monstre jusqu'au joueur
t_coordonees ecrireChemin(){
	t_coordonees cheminRetour;
	int cptx,cpty;
	int chemin=0;
	
	while(1){
		for(cptx=0;cptx<N;cptx++){
			for(cpty=0;cpty<N;cpty++){
				
				if(vision[cptx][cpty]==chemin){
					
					// le joueur est à coté de notre case -> on arrete
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

int MobNextToJoueur(){
	int cptx;
	int cpty;
	int mobx, moby;
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
	return 0;
}

// empile les cases à suivre par le monstre pour arriver au joueur
// cheminRetour = case cible (juste à coté du joueur)
void lireChemin(t_coordonees cheminRetour){
	int arrive=0;
	initpileStruct();
	empilerStruct(cheminRetour);
	
	
	while(arrive!=1){

		if((vision[cheminRetour.x][cheminRetour.y-1]==0) || (vision[cheminRetour.x][cheminRetour.y+1]==0) || (vision[cheminRetour.x-1][cheminRetour.y]==0) || (vision[cheminRetour.x+1][cheminRetour.y]==0)){ //on est a coté du monstre
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

//deplace le mob sur une case en direction du joueur
void IA(int matrice[N][N], int*pvJoueur, int parade, int*enduJoueur, int cpt_laby){
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
	
	//choisi la statistique la plus élever entre armureleg et armurelou pour determiner la reduction des degats
	if(joueur.combat.armureleg>=joueur.combat.armurelou){
		reducDegat = joueur.combat.armureleg;
	}
	else{
		reducDegat = joueur.combat.armurelou;
	}
	
	tradVision(matrice);
	resetMob();
	trouverMob(&mobx, &moby);
	
	attaque=MobNextToJoueur();						//determine si le joueur et le mob sont cote à cote et savoir par la suite l'action de l'IA
	
	//fait deplacer le mob si celui-ci n'est pas a coter du joueur
	if(attaque==0){
		cheminRetour=ecrireChemin();
		lireChemin(cheminRetour);
		depilerStruct(&resultat);
		matrice[resultat.x][resultat.y]=MOB; 		//déplacer le MOB sur la case en direction du joueur
		matrice[mobx][moby]=CHEMIN; 				//liberer le chemin derriere le MOB
	}
	
	//inflige des degats au joueur en fonction de ses compétences si le mob est a coter de celui-ci
	else{
		degat=degat-(0.25*reducDegat);
		if(critique>=100){
			degat*=2;
			printf("\r\n            ==> CRITIQUE <==            \r\n");
		}
		if(parade==0){
			*pvJoueur-=degat;
			printf("\r\n     /!\\ Vous perdez %i PV /!\\\r\n", degat);
		}
		else if(parade==1 && degatBrut<*enduJoueur){
			
			if(degatBloquer<=0){	
				*pvJoueur-=0;
				*enduJoueur-=degatBrut;
			}
			
			else{
				*enduJoueur-=degatBrut;
				*pvJoueur-=degatBloquer;
			}
			printf("\r\n      /!\\ Vous parez le prochain coup /!\\ \r\n");
		}
	}

	
	
}


