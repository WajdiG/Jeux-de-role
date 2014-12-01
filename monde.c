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
#include "pile_tab.h"

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
	char mat[N][M];
	
	for(i=0;i<N;i++){	//initialise la matrice avec des X
		for(j=0;j<M;j++){
			mat[i][j]='X';
		}
	}
	
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){	//alloue dynamiquement une matrice de taille N M aux coordonnées i j du monde
			monde[i][j]=(char **)malloc(sizeof(mat[N][M]));
			monde[i][j]=mat;
		}
	}
}

/**
 *\fn inclure_region(int, int)
 *\brief permet d'inclure une region dans le monde
 *\param i abscisse correspondant aux coordonnées de la region à inclure
 *\param j ordonnée correspondant aux coordonnées de la region à inclure
 */
void inclure_region(int i, int j){
	
	int a,b;
	char mat[N][M];
	
	for(a=0;a<N;a++){
		for(b=0;b<M;b++){	//copie la "topologie" de la region dans mat
			mat[a][b]=region[a][b];
		}
	}
	
	monde[i][j]=mat;	

}

/**
 *\fn deplacement_case_monde(int*, int*)
 *\brief permet de deplacer le joueur d'une case dans le monde
 *\param *i abscisse correspondant aux coordonnées actuelles du joueur
 *\param *j ordonnée correspondant aux coordonnées actuelles du joueur
 */
void deplacement_case_monde(int* i, int* j){
	
	int choix,a,b;	
	int cpt=1;
	int verif=0;
	
	initpile();
	
	/*Traitement dans un premier temps de tout les cas particuliers : dans les angles ou en bordure de matrice. Puis traitement des autres cas.
	 *cpt est égale aux choix possible allant de 1 à cpt (cpt étant mis à jour à chaques itération.
	 *on empile les coordonées de destination possible préalablement stocké dans a.
	 */
	
	do{	
		printf("Saisissez le chiffre correspondant au choix de votre prochaine destination : \n");
		if(*i==0&&*j==0){
			printf("%i : %i %i \n", cpt, *i, *j+1);
			a=*i;
			empiler(a);
			a=*j+1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i \n", cpt, *i+1, *j);
			a=*i+1;
			empiler(a);
			a=*j;
			empiler(a);
			cpt++;
			verif=2;
		}
		else if(*i==0&&*j==Y-1){
			printf("%i : %i %i \n", cpt, *i, *j-1);
			a=*i;
			empiler(a);
			a=*j-1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i \n", cpt, *i+1, *j);
			a=*i+1;
			empiler(a);
			a=*j;
			empiler(a);
			cpt++;
			verif=2;
		}
		else if(*j==0&&*i==X-1){
			printf("%i : %i %i\n", cpt, *i-1, *j);
			a=*i-1;
			empiler(a);
			a=*j;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, *i, *j+1);
			a=*i;
			empiler(a);
			a=*j+1;
			empiler(a);
			cpt++;
			verif=2;
		}
		else if(*j==Y-1&&*i==X-1){
			printf("%i : %i %i\n", cpt, *i-1, *j);
			a=*i-1;
			empiler(a);
			a=*j;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, *i, *j-1);
			a=*i;
			empiler(a);
			a=*j-1;
			empiler(a);
			cpt++;
			verif=2;
		}
		else{
			if(*i==0){
				printf("%i : %i %i\n", cpt, *i, *j+1);
				a=*i;
				empiler(a);
				a=*j+1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j-1);
				a=*i;
				empiler(a);
				a=*j-1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i+1, *j);
				a=*i+1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				verif=3;
			}
			else if(*j==0){
				printf("%i : %i %i\n", cpt, *i-1, *j);
				a=*i-1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j+1);
				a=*i;
				empiler(a);
				a=*j+1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i+1, *j);
				a=*i+1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				verif=3;
			}
			else if(*i==X-1){
				printf("%i : %i %i\n", cpt, *i, *j+1);
				a=*i;
				empiler(a);
				a=*j+1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j-1);
				a=*i;
				empiler(a);
				a=*j-1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i-1, *j);
				a=*i-1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				verif=3;
			}
			else if(*j==Y-1){
				printf("%i : %i %i\n", cpt, *i-1, *j);
				a=*i-1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j-1);
				a=*i;
				empiler(a);
				a=*j-1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i+1, *j);
				a=*i+1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				verif=3;
			}
			else{
				printf("%i : %i %i\n", cpt, *i-1, *j);
				a=*i-1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j-1);
				a=*i;
				empiler(a);
				a=*j-1;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i+1, *j);
				a=*i+1;
				empiler(a);
				a=*j;
				empiler(a);
				cpt++;
				
				printf("%i : %i %i\n", cpt, *i, *j+1);
				a=*i;
				empiler(a);
				a=*j+1;
				empiler(a);
				cpt++;
				
				verif=4;
			}
		}
		
		printf("Voter choix : ");
		scanf("%i", &choix);
		
	}while(choix<1||choix>verif);
	
	for(b=verif;b>=choix;b--){ //recupération des coordonnées choisit par le joueur
		depiler(j);
		depiler(i);
	}
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
			printf("%c ", mat[a][b]);
		}
		printf("\n");
	}
}

/**
 *\fn deplacement_monde(int, int)
 *\brief permet au joueur de se déplacer dans le monde
 *\param i abscisse correspondant aux coordonnées du joueur
 *\param j ordonnée correspondant aux coordonnées du joueur
 */
void deplacement_monde(int x, int y){
	int k=0;
	
	do{
		aff_monde(x,y); 
		deplacement_case_monde(&x,&y);
		aff_monde(x,y); 
		printf("Souhaitez-vous déplacer à nouveau ? : 1 pour oui, 0 pour non.");
		printf("Votre choix : ");
		scanf("%i", &k);
	}while(k!=0);
}
