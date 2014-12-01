/**
 *\file IA.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <assert.h>
#include "accueil.h"
#include "pile.h"
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5
#define MOB_gauche 6
#define MOB_droite 7
#define MOB_haut 8
#define MOB_bas 9

t_coordonees mes_choix[4];
t_coordonees ma_position = {17, 2};
t_coordonees mob_position = {2, 17};
t_coordonees mob = {8,8};

int matrice[N][N];
int vision[N][N];

void affichage(int matrice[N][N]){
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
                switch(matrice[i][j]){
                    case(MUR) : printf("|-|"); break;
                    case(CHEMIN) : printf("   "); break;
                    case(JOUEUR) : printf("*_*"); break;
                    case(COFFRE) : printf("[C]"); break;
                    case(OBJECTIF) : printf(" X "); break;
                    case(MOB) : printf(">_<"); break;
                    case(MOB_gauche) : printf("<_<"); break;
                    case(MOB_droite) : printf(">_>"); break;
                    case(MOB_haut) : printf("^_^"); break;
                    case(MOB_bas) : printf("v_v"); break;
                }
		}
		printf("\n");
	}
	printf("\n");
}

void initialisation(int matrice[N][N]){

	int entier;
	int i, j;
	FILE * fichier;

    fichier = fopen("maptest.txt","r");

    while(!feof(fichier)){

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                fscanf(fichier,"%i", &entier);
                matrice[i][j] = entier;
            }
        }
    }
    matrice[17][2]=JOUEUR;
    matrice[2][10]=MOB;
    fclose(fichier);
}

void tradVision(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		printf("\n");
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
	printf("\n");
}

void affVision2(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		printf("\n");
		for(cpty=0;cpty<N;cpty++){
                switch(matrice[cptx][cpty]){
                    case(-8) : printf("|-|"); break;
                    case(-1) : printf("   "); break;
                    case(-2) : printf("*_*"); break;
                    case(-3) : printf("[C]"); break;
                    case(-4) : printf(" X "); break;
                    case(0) : printf(">_<"); break;
                }
            if(matrice[cptx][cpty]>0 && matrice[cptx][cpty]<=9){
				printf(" %i ", matrice[cptx][cpty]);
			}
			else if(matrice[cptx][cpty]>9){
				printf(" %i", matrice[cptx][cpty]);
			}
		}
	}
	printf("\n");

}

void affVision(int matrice[N][N]){
	int cptx=0;
	int cpty=0;

	for(cptx=0;cptx<N;cptx++){
		printf("\n");
		for(cpty=0;cpty<N;cpty++){
			if(matrice[cptx][cpty]>=0 && matrice[cptx][cpty]<=9){
				printf(" %i ", matrice[cptx][cpty]);
			}
			else if(matrice[cptx][cpty]>9){
				printf(" %i", matrice[cptx][cpty]);
			}
			else{
				printf("%i ", matrice[cptx][cpty]);
			}
		}
	}
	printf("\n");
}

void trouverMob(int *mobx, int *moby){
	int cptx;
	int cpty;
	int mob=0;
	int sorti=0;
	
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

t_coordonees ecrireChemin(t_coordonees cheminRetour){
	int cptx,cpty;
	//int sorti=0;
	int chemin=0;
	
	while(1){
		for(cptx=0;cptx<N;cptx++){
			for(cpty=0;cpty<N;cpty++){
				
				if(vision[cptx][cpty]==chemin){
					
					if((vision[cptx][cpty-1]==-1)){
						vision[cptx][cpty-1]=chemin+1;
					}
					if((vision[cptx][cpty+1]==-1)){
						vision[cptx][cpty+1]=chemin+1;
					}
					if((vision[cptx-1][cpty]==-1)){
						vision[cptx-1][cpty]=chemin+1;
					}
					if((vision[cptx+1][cpty]==-1)){
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

void lireChemin(t_coordonees cheminRetour, int cptx, int cpty){
	int arrive=0;
	initpile();
	
	while(arrive!=1){

		empiler(cheminRetour);
		
		if((vision[cptx][cpty-1]==vision[cptx][cpty]-1)){
			cheminRetour.x=cptx;
			cheminRetour.y=cpty-1;
			cpty--;
		}
		else if((vision[cptx][cpty+1]==vision[cptx][cpty]-1)){
			cheminRetour.x=cptx;
			cheminRetour.y=cpty+1;
			cpty++;
		}
		else if((vision[cptx-1][cpty]==vision[cptx][cpty]-1)){
			cheminRetour.x=cptx-1;
			cheminRetour.y=cpty;
			cptx--;
		}
		else if((vision[cptx+1][cpty]==vision[cptx][cpty]-1)){
			cheminRetour.x=cptx+1;
			cheminRetour.y=cpty;
			cptx++;
		}
		
		if((vision[cptx][cpty-1]==0) || (vision[cptx][cpty+1]==0) || (vision[cptx-1][cpty]==0) || (vision[cptx+1][cpty]==0)){
			arrive=1;
		}
	}
	empiler(cheminRetour);
}

void IA(){
	int mobx;
	int moby;
	char suivant;
	int cpt=0;
	int cptx=0;
	int cpty=0;
	t_coordonees cheminRetour;
	t_coordonees resultat;

	initialisation(matrice);
	tradVision(matrice);
	
	
	while(cpt<=25){
		
		
		resetMob();
		
		trouverMob(&mobx, &moby);
		
		cheminRetour=ecrireChemin(cheminRetour);

		cptx=cheminRetour.x;
		cpty=cheminRetour.y;
		lireChemin(cheminRetour, cptx, cpty);
		
		affVision2(vision);
		affVision(vision);

		depiler(&resultat);
		vision[resultat.x][resultat.y]=0;
		vision[mobx][moby]=-1;
		
		printf("\n#############################################\n");
		scanf("%c",&suivant);
		if(cpt==10){
			vision[17][2]=-1;
			vision[2][17]=-2;
		}
		cpt++;
	}
	
	affVision2(vision);
	affVision(vision);

}


