/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
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
#define MOB_gauche 6
#define MOB_droite 7
#define MOB_haut 8
#define MOB_bas 9

extern int quitter;
extern char region[N][N];

t_coordonees mes_choix[4];
t_coordonees ma_position;
t_coordonees sorti;

/**
* \fn void affichage(int matrice[N][N])
* \brief Fonction permettant l'affichage de la carte a chaque tour.
* \param matrice[N][N] matrice ou chaque case contient soir un mur, un chemin, un joueur, un coffre ou un monstre
**/
void affichage(int matrice[N][N]){
	int i, j;
	system("clear");
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
                switch(matrice[i][j]){
                    case(MUR) : printf("|-|"); break;
                    case(CHEMIN) : printf("   "); break;
                    case(JOUEUR) : printf("*_*"); break;
                    case(COFFRE) : printf("[C]"); break;
                    case(OBJECTIF) : printf(" X "); break;
                    case(MOB) : printf("X_X"); break;
                }
		}
		printf("\n");
	}
}

void rechercheJoueur(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0 ; cptx<N ; cptx++){
		for(cpty=0 ; cpty<N ; cpty++){
			if(matrice[cptx][cpty]==JOUEUR){
				ma_position.x=cptx;
				ma_position.y=cpty;
			}
		}
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

/**
* \fn void deplacement_perso(int matrice[N][N])
* \brief Fonction permettant de deplacer le joueur a chaque tour.
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void deplacement_perso(int matrice[N][N]){
		
		char direction;
        t_coordonees tampon;
		printf("\n Ou souhaitez-vous vous deplacer ?\n\n");
		scanf(" %c", &direction);	
			
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;
        
		switch(direction){
			case 'z' : ma_position.x-- ; break;
			case 'q' : ma_position.y-- ; break;
			case 's' : ma_position.x++ ; break;
			case 'd' : ma_position.y++ ; break;
		}	
		if(matrice[ma_position.x][ma_position.y] == MUR){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else{
			matrice[tampon.x][tampon.y] = CHEMIN;
			matrice[ma_position.x][ma_position.y]=JOUEUR;
		} 		        
}

/**
* \fn int coffre()
* \brief Fonction permettant de voir s'il y a des coffres sur la carte
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemain, un coffre ou un monstre
* \return Renvoi 1 s'il n'y a plus de coffre sur la carte
**/
int coffre(int matrice[N][N]){
	int cptx=0;
	int cpty=0;
	
	for(cptx=0;cptx<N;cptx++){
		for(cpty=0;cpty<N;cpty++){
			if(matrice[cptx][cpty]==COFFRE){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	
	int matrice[N][N];
	int VD=-1;
	char temp;
    	
	//initialisation(matrice);
	printf("\n\n");
	
	ecran_accueil();
	//Menu_Jeu();	
		
	creer_region();
	tradRandom(matrice, region);
	affichage(matrice);
	
	//matrice[ma_position.x][ma_position.y] = JOUEUR; // position initiale du joueur
	//matrice[mob_position.x][mob_position.y] = MOB; //position initiale du perso
   
	while(quitter != 1){
		VD=-1;
		Menu_Jeu();
		rechercheJoueur(matrice);
		sorti=ma_position;
		while(matrice[ma_position.x][ma_position.y] != OBJECTIF && quitter != 1){
			
			rechercheJoueur(matrice);

			affichage(matrice);
			deplacement_perso(matrice);
			VD=IA(matrice);
			scanf("%c", &temp); //pour absorber le caractère resté dans le buffer
			if(VD==1){
				defeat();
				break;
			}
			if(coffre(matrice)){
				matrice[sorti.x][sorti.y] = OBJECTIF;
			}
			
			affichage(matrice);
		}
		if(VD==0){
			victory();
		}
	}  	
		
	return EXIT_SUCCESS;
	
}
