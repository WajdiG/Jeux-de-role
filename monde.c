/**
*\file monde.c
*\brief regroupe toutes les fonctions nécessaires à la gestion du monde
*\author Wajdi Guedouar
*\version 0.1
*\date 27 Novembre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "region.h"

#define X 3
#define Y 3

extern char region[N][M]; //une region du monde
char ** monde[X][Y]; //le monde

/**
 *\fn init_monde(void)
 *\brief initialise le contenu de la matrice monde 
 */
void init_monde(){
	int i,j;
	char mat1[5][5];
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			mat1[i][j]='X';
		}
	}
	
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			monde[i][j]=mat1;
		}
	}
	
}

/**
 *\fn inclure_region(int, int)
 *\brief permet d'inclure une region dans le monde
 *\param i abscisse correspondant aux coordonnées de la region
 *\param j ordonnée correspondant aux coordonnées de la region
 */
void inclure_region(int i, int j){
	
	monde[i][j]=region;

}


/**
 *\fn aff_monde(int, int)
 *\brief permet d'inclure une region dans le monde
 *\param i abscisse correspondant aux coordonnées du joueur
 *\param j ordonnée correspondant aux coordonnées du joueur
 */
void aff_monde(int i, int j){
	
	int a,b;
	char mat[X][Y];
	
	for(a=0;a<X;a++){
		for(b=0;b<Y;b++){
			mat[a][b]='X';
		}
	}
	mat[i][j]='P';
	
	printf("Vous êtes représentez par la lettre P, voici votre position dans la monde : \n");
	
	for(a=0;a<X;a++){
		for(b=0;b<Y;b++){
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
}
