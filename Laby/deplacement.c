/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4

typedef struct {int x, y;}t_coordonees;

t_coordonees mes_choix[4];
t_coordonees ma_position = {17, 2};

void affichage(int matrice[N][N]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
                switch(matrice[i][j]){
                    case(MUR) : printf("|-|"); break;
                    case(CHEMIN) : printf("   "); break;
                    case(JOUEUR) : printf("*_*"); break;
                    case(COFFRE) : printf("ICI"); break;
                    case(OBJECTIF) : printf(" X "); break;
                }
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
		int i;
		t_coordonees chemin_voulu;
        	t_coordonees tampon;

		mes_choix[0].x = ma_position.x + 1;
		mes_choix[0].y = ma_position.y;
		mes_choix[1].x = ma_position.x;
		mes_choix[1].y = ma_position.y + 1;
		mes_choix[2].x = ma_position.x - 1;
		mes_choix[2].y = ma_position.y;
		mes_choix[3].x = ma_position.x;
		mes_choix[3].y = ma_position.y - 1;
        	printf("\nVous pouvez aller sur les cases suivantes : ");
		for(i=0; i<4; i++){
			if(matrice[mes_choix[i].x][mes_choix[i].y] == 1 || matrice[mes_choix[i].x]

[mes_choix[i].y] == 2){
				printf("(%i;%i)", mes_choix[i].x, mes_choix[i].y);
			}
		}
		printf("Ou souhaitez-vous vous deplacer ?\n\n");
		scanf("%i %i", &chemin_voulu.x, &chemin_voulu.y);
		for(i=0; i<4; i++){
			if(((mes_choix[i].x == chemin_voulu.x) && (mes_choix[i].y == chemin_voulu.y)) &&

(matrice[chemin_voulu.x][chemin_voulu.y] != 0)){
				printf("Deplacement accepte !\n");
                tampon.x = ma_position.x;
                tampon.y = ma_position.y;
				ma_position.x = chemin_voulu.x;
				ma_position.y = chemin_voulu.y;
                matrice[tampon.x][tampon.y] = 1;
				break;
			}
		}
}


void placement_perso(int matrice[N][N], int *compteur){
	matrice[ma_position.x][ma_position.y] = JOUEUR;
	affichage(matrice);
	coordonnees(matrice);
	if(matrice[ma_position.x][ma_position.y] == COFFRE){
        *compteur = *compteur + 1;
	}
}

int nb_coffre_map(int matrice[N][N]){
    int i, j;
    int cpt = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(matrice[i][j] == COFFRE){
                cpt++;
            }
        }
    }
    return cpt;
}

int main(){
    int matrice[N][N];
    int compteur = 0;
    int nb_coffre;
	initialisation(matrice);
	printf("\n\n");
	nb_coffre = nb_coffre_map(matrice);
    while(matrice[ma_position.x][ma_position.y] != OBJECTIF){
        while(compteur < nb_coffre){
            placement_perso(matrice, &compteur);
            printf("\n%i\n", compteur);
        }
        matrice[2][17] = OBJECTIF;
        placement_perso(matrice, &compteur);
    }
        printf("IIIIIII   IIIIII IIIIIII II     II IIIIIIII\n");
        printf("II    I   I    I II   II II     II II    II\n");
        printf("II     I  I   I  II   II II     II II    II\n");
        printf("II    I   IIII   II   II II     II II    II\n");
        printf("IIIIIII   II     IIIIIII II     II II    II\n");
        printf("II    I   I I    II   II II     II II    II\n");
        printf("II     I  I  I   II   II  II   II  II    II\n");
        printf("II    I   I   I  II   II   II II   II    II\n");
        printf("IIIIIII   I    I II   II    II     IIIIIIII\n");
        return 0;
}
