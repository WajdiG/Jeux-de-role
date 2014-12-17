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

#include "monde.h"
#include "pile_tab.h"

extern char region[N][N]; //une region du monde
char ** monde[X][Y]; //le monde

t_coord coord={0,0};

/**
 *\fn init_monde(void)
 *\brief initialise le contenu de la matrice monde 
 */
void init_monde(){
	
	int i,j,k,l;
	
	char **region;
	
	
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){	//alloue dynamiquement une matrice de taille N M aux coordonnées i j du monde
			region = malloc(N * sizeof(*region));
			for(k=0;k<N;k++){	//initialise la matrice avec des X
				region[k] = malloc(N*sizeof(*region[k]));
				for(l=0;l<N;l++){
					region[k][l]='X';
				}
			}
			monde[i][j]=region;
		}
	}
}

/**
 *\fn inclure_region(t_coord)
 *\brief permet d'inclure une region dans le monde
 *\param coord contient les coordonnées courantes du joueur dans la matrice monde
 */
void inclure_region(t_coord coord){
	
	int a,b;
	
	for(a=0;a<N;a++){
		for(b=0;b<N;b++){	//copie la "topologie" de la region dans monde
			monde[coord.x][coord.y][a][b]=region[a][b];
		}
	}
}


/**
 *\fn deplacement_case_monde(t_coord)
 *\brief permet de deplacer le joueur d'une case dans le monde
 *\param *coord coordonnées correspondants à la poisition actuelles du joueur
 */
void deplacement_case_monde(t_coord *coord){
	
	int choix,a,b;	
	int cpt=1;
	int verif=0;
	
	initpile();
	
	/*Traitement dans un premier temps de tout les cas particuliers : dans les angles ou en bordure de matrice. Puis traitement des autres cas.
	 *cpt est égale aux choix possible allant de 1 à cpt (cpt étant mis à jour à chaques itération.
	 *on empile les coordonées de destination possible préalablement stocké dans a.
	 */
	
	
	printf("Saisissez le chiffre correspondant au choix de votre prochaine destination : \n");
	if(coord->x==0&&coord->y==0){
		printf("%i : %i %i \n", cpt, coord->x, (coord->y)+1);
		a=coord->x;
		empiler(a);
		a=(coord->x)+1;
		empiler(a);
		cpt++;
			
		printf("%i : %i %i \n", cpt, (coord->x)+1, (coord->y));
		a=(coord->x)+1;
		empiler(a);
		a=(coord->y);
		empiler(a);
		cpt++;
		verif=2;
	}
	else if((coord->x)==0&&(coord->y)==Y-1){
		printf("%i : %i %i \n", cpt, (coord->x), (coord->y)-1);
		a=(coord->x);
		empiler(a);
		a=(coord->y)-1;
		empiler(a);
		cpt++;
			
		printf("%i : %i %i \n", cpt, (coord->x)+1, (coord->y));
		a=(coord->x)+1;
		empiler(a);
		a=(coord->y);
		empiler(a);
		cpt++;
		verif=2;
	}
	else if((coord->y)==0&&(coord->x)==X-1){
		printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
		a=(coord->x)-1;
		empiler(a);
		a=(coord->y);
		empiler(a);
		cpt++;
			
		printf("%i : %i %i\n", cpt, (coord->x), (coord->y)+1);
		a=(coord->x);
		empiler(a);
		a=(coord->y)+1;
		empiler(a);
		cpt++;
		verif=2;
	}
	else if((coord->y)==Y-1&&(coord->x)==X-1){
		printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
		a=(coord->x)-1;
		empiler(a);
		a=(coord->y);
		empiler(a);
		cpt++;
			
		printf("%i : %i %i\n", cpt, (coord->x), (coord->y)-1);
		a=(coord->x);
		empiler(a);
		a=(coord->x)-1;
		empiler(a);
		cpt++;
		verif=2;
	}
	else{
		if((coord->x)==0){
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)+1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)+1;
			empiler(a);
			cpt++;
				
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)-1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)-1;
			empiler(a);
			cpt++;
				
			printf("%i : %i %i\n", cpt, (coord->x)+1, (coord->y));
			a=(coord->x)+1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			verif=3;
		}
		else if((coord->y)==0){
			printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
			a=(coord->x)-1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
				
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)+1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)+1;
			empiler(a);
			cpt++;
				
			printf("%i : %i %i\n", cpt, (coord->x)+1, (coord->y));
			a=(coord->x)+1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			verif=3;
		}
		else if((coord->x)==X-1){
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)+1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)+1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)-1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)-1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
			a=(coord->x)-1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			verif=3;
		}
		else if((coord->y)==Y-1){
			printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
			a=(coord->x)-1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
				
			printf("%i : %i %i\n", cpt, (coord->x),  (coord->y)-1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)-1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x)+1, (coord->y));
			a=(coord->x)+1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			verif=3;
		}
		else{
			printf("%i : %i %i\n", cpt, (coord->x)-1, (coord->y));
			a=(coord->x)-1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)-1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)-1;
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x)+1, (coord->y));
			a=(coord->x)+1;
			empiler(a);
			a=(coord->y);
			empiler(a);
			cpt++;
			
			printf("%i : %i %i\n", cpt, (coord->x), (coord->y)+1);
			a=(coord->x);
			empiler(a);
			a=(coord->y)+1;
			empiler(a);
			cpt++;
			
			verif=4;
		}
	}
		
	while(choix<1||choix>verif){
		printf("Votre choix : ");
		scanf("%i", &choix);
	}
	
	
	for(b=verif;b>=choix;b--){ //recupération des coordonnées choisit par le joueur
		depiler(&b);
		coord->y=b;
		depiler(&a);
		coord->x=a;
	}
}

/**
 *\fn aff_monde(void)
 *\brief permet d'afficher le monde
 */
void aff_monde(){
	
	int a,b;
	char mat[X][Y];
	
	for(a=0;a<X;a++){
		for(b=0;b<Y;b++){
			mat[a][b]='X';
		}
	}
	mat[coord.x][coord.y]='P';
	
	printf("Vous êtes représenté par la lettre P, voici votre position dans la monde : \n");
	
	for(a=0;a<X;a++){
		for(b=0;b<Y;b++){
			printf("%c ", mat[a][b]);
		}
		printf("\n");
	}
}

/**
 *\fn aff_region_monde(void)
 *\brief permet d'afficher la région dans laquelle vous vous trouvez
 */
void aff_region_monde(){
	int a,b;
	
	for(a=0;a<N;a++){
		for(b=0;b<N;b++){
			printf("%c ",monde[coord.x][coord.y][a][b]);
		}
		printf("\n");
	}
}

/**
 *\fn deplacement_monde(void)
 *\brief permet au joueur de se déplacer dans le monde
 */
void deplacement_monde(){
	
	aff_monde(); 
	deplacement_case_monde(&coord);
	aff_monde();
}
