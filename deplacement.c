/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois 
 *\author TOULMONDE Joris
 *\version 0.1
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct {int x, y;}t_coordonees;

t_coordonees mes_choix[4];
t_coordonees ma_position = {5, 3};

void affichage(int matrice[N][N]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%i ", matrice[i][j]);
		}
		printf("\n");
	}
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
    fclose(fichier);
}

void coordonnees(int matrice[N][N]){
		int x, y;
		int i;
		int compteur = 0;
		t_coordonees temporaire;
		t_coordonees chemin_voulu;
		printf("\nVous pouvez aller sur les cases suivantes : ");
		mes_choix[0].x = ma_position.x + 1; 
		mes_choix[0].y = ma_position.y; 
		mes_choix[1].x = ma_position.x; 
		mes_choix[1].y = ma_position.y + 1; 
		mes_choix[2].x = ma_position.x - 1; 
		mes_choix[2].y = ma_position.y; 
		mes_choix[3].x = ma_position.x; 
		mes_choix[3].y = ma_position.y - 1;
		
		for(i=0; i<4; i++){
			if(matrice[mes_choix[i].x][mes_choix[i].y] == 1){
				printf("(%i;%i)", mes_choix[i].x, mes_choix[i].y);
			}
		}
		printf("Ou souhaitez-vous vous deplacer ?\n\n");
		scanf("%i %i", &chemin_voulu.x, &chemin_voulu.y);
		for(i=0; i<4; i++){
			if((mes_choix[i].x == chemin_voulu.x) && (mes_choix[i].y == chemin_voulu.y)){
				printf("Deplacement accepte !\n");
				temporaire.x = ma_position.x;
				temporaire.y = ma_position.y;
				ma_position.x = chemin_voulu.x;
				ma_position.y = chemin_voulu.y;
				break;
			}
		}
		matrice[temporaire.x][temporaire.y] = 1;	
}



void placement_perso(int matrice[N][N]){
	matrice[ma_position.x][ma_position.y] = 5;
	affichage(matrice);
	coordonnees(matrice);
}


int main(){
    	int matrice[N][N];
	initialisation(matrice);
	printf("\n\n");
	while(1){
		placement_perso(matrice);
	}
	return 0;
}	
