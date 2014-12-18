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


//int matrice[N][N];
int vision[N][N];

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
	printw("\n");
}

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

void trouverCible(int *Jx, int *Jy){
	int cptx;
	int cpty;
	int sorti=0;
	int joueur=-2;
	
	for(cptx=0 ; cptx<N && !sorti ; cptx++){
		for(cpty=0 ; cpty<N && !sorti ; cpty++){	
					
			if(vision[cptx][cpty]==joueur){
				*Jx=cptx;
				*Jy=cpty;
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

t_coordonees ecrireChemin(t_coordonees cheminRetour){
	int cptx,cpty;
	int chemin=0;
	
	while(1){
		for(cptx=0;cptx<N;cptx++){
			for(cpty=0;cpty<N;cpty++){
				
				if(vision[cptx][cpty]==chemin){
					
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
					if((vision[cptx][cpty-1]==-2) || (vision[cptx][cpty+1]==-2) || (vision[cptx-1][cpty]==-2) || (vision[cptx+1][cpty]==-2)){
						cheminRetour.x=cptx;
						cheminRetour.y=cpty;
						return cheminRetour;
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
	int mobx, moby, Jx, Jy;
	int sortis=0;
	int joueur=-2;
	int mob=0;
	
	for(cptx=0 ; cptx<N && !sortis ; cptx++){
		for(cpty=0 ; cpty<N && !sortis ; cpty++){	
			if(vision[cptx][cpty]==mob){
				mobx=cptx;
				moby=cpty;
			}
			if(vision[cptx][cpty]==joueur){
				Jx=cptx;
				Jy=cpty;
			}
		}
	}
	//printw("joueur : %i %i \n", Jx, Jy);
	//printw("mob : %i %i \n", mobx, moby);

	if(moby==Jy+1 && mobx==Jx){
		return 1;
	}
	if(moby==Jy-1 && mobx==Jx){
		return 1;
	}
	if(moby==Jy && mobx==Jx+1){
		return 1;
	}
	if(moby==Jy && mobx==Jx-1){
		return 1;
	}
	return 0;
}

void lireChemin(t_coordonees cheminRetour, int cptx, int cpty){
	int arrive=0;
	int mobJoueur;
	initpileStruct();
	
	empilerStruct(cheminRetour);
	
	mobJoueur=MobNextToJoueur();
	
	while(arrive!=1 && mobJoueur!=1){
		if(vision[cptx][cpty-1]==vision[cptx][cpty]-1){
			cheminRetour.x=cptx;
			cheminRetour.y=cpty-1;
			cpty--;
		}
		else if(vision[cptx][cpty+1]==vision[cptx][cpty]-1){
			cheminRetour.x=cptx;
			cheminRetour.y=cpty+1;
			cpty++;
		}
		else if(vision[cptx-1][cpty]==vision[cptx][cpty]-1){
			cheminRetour.x=cptx-1;
			cheminRetour.y=cpty;
			cptx--;
		}
		else if(vision[cptx+1][cpty]==vision[cptx][cpty]-1){
			cheminRetour.x=cptx+1;
			cheminRetour.y=cpty;
			cptx++;
		}
	
		if((vision[cptx][cpty-1]==0) || (vision[cptx][cpty+1]==0) || (vision[cptx-1][cpty]==0) || (vision[cptx+1][cpty]==0)){
			arrive=1;
		}
		empilerStruct(cheminRetour);
	}
}

int IA(int matrice[N][N]){
	int mobx;
	int moby;
	int cptx=0;
	int cpty=0;
	t_coordonees cheminRetour;
	t_coordonees resultat;

	tradVision(matrice);

	resetMob();
		
	trouverMob(&mobx, &moby);

	cheminRetour=ecrireChemin(cheminRetour);
	
	cptx=cheminRetour.x;
	cpty=cheminRetour.y;
	
	if(cptx==mobx && cpty==moby){
		return 1;
	}
	
	lireChemin(cheminRetour, cptx, cpty);

	depilerStruct(&resultat);
	vision[resultat.x][resultat.y]=0;
	matrice[resultat.x][resultat.y]=MOB;
	vision[mobx][moby]=-1;
	matrice[mobx][moby]=CHEMIN;

	return 0;
}
