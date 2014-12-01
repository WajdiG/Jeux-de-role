/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "accueil.h"
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5
extern int quitter;
typedef struct {int x, y;}t_coordonees;

t_coordonees mes_choix[4];
t_coordonees ma_position = {17, 2};
t_coordonees mob_position = {2, 17};

/**
* \fn void affichage(int matrice[N][N])
* \brief Fonction permettant l'affichage de la carte a chaque tour.
* \param matrice[N][N] matrice ou chaque case contient soir un mur, un chemin, un joueur, un coffre ou un monstre
**/
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
		} 		        
}

/**
* \fn void comptage_coffre(int matrice[N][N], int * compteur)
* \brief Fonction permettant d'actualiser le nombre de coffre que possede la joueur.
* \param *compteur s'incremente a chaque fios qu'un coffre est ramassé
**/
void comptage_coffre(int matrice[N][N], int *compteur){	
	if(matrice[ma_position.x][ma_position.y] == COFFRE){
        	*compteur = *compteur + 1;
	}  
}

void placement_mob(int matrice[N][N]){
	matrice[mob_position.x][mob_position.y] = MOB;
	
}

/**
* \fn int nb_coffre_map(int matrice[N][N])
* \brief Fonction permettant de compter le nombre coffre present sur la carte au debut du jeu
* \param matrice[N][N]
* \return Retourne le nombre de coffre sur la carte
**/
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

	ecran_accueil();
	
	Menu_Jeu();
	
	if(quitter == 1){
		return 0;
	}	
	
   	while(matrice[ma_position.x][ma_position.y] != OBJECTIF){
   		matrice[ma_position.x][ma_position.y] = JOUEUR; // position initiale du joueur
       		matrice[mob_position.x][mob_position.y] = MOB; //position initiale du perso
       		if(compteur < nb_coffre){
			affichage(matrice);
			deplacement_perso(matrice);
			comptage_coffre(matrice, &compteur);
			placement_mob(matrice);  	          	    
       	 	}
       	 	else{
			matrice[2][17] = OBJECTIF; //la porte est visible maintenant
       			affichage(matrice); 
			placement_mob(matrice);
			deplacement_perso(matrice);
			comptage_coffre(matrice, &compteur);  
		}       	             
    	}
    	printf("WELL PLAYED NOOB !!!!\n");
}
