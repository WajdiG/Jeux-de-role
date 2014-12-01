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
#define MOB_gauche 6
#define MOB_droite 7
#define MOB_haut 8
#define MOB_bas 9

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
                    case(MOB) : printf("X_X"); break;
                    case(MOB_gauche) : printf("<_<"); break;
                    case(MOB_droite) : printf(">_>"); break;
                    case(MOB_haut) : printf("^_^"); break;
                    case(MOB_bas) : printf("v_v"); break;
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


void IA(int matrice[N][N]){
		srand(time(NULL));
		char direction;
		t_coordonees tampon;
		char deplac_mob[4]={'z','q','s','d'};
		int dir=rand()%(4-0)+0;
		

		printf("\n %i \n", dir);
        
		direction=deplac_mob[dir];
		tampon.x = mob_position.x;
        	tampon.y = mob_position.y;
        

		int cpt ;	
        
		direction=deplac_mob[dir];
		tampon.x = mob_position.x;
        	tampon.y = mob_position.y;
		
		switch(direction){
			case 'z' : mob_position.x-- ; break;
			case 'q' : mob_position.y-- ; break;
			case 's' : mob_position.x++ ; break;
			case 'd' : mob_position.y++ ; break;
		}
	
		if(matrice[mob_position.x][mob_position.y] == MUR || matrice[mob_position.x][mob_position.y] == COFFRE){
			mob_position.x = tampon.x;
			mob_position.y = tampon.y;
		}
			
		else{
			switch(direction){
				case 'z' : matrice[mob_position.x][mob_position.y] = MOB_haut; ; break;
				case 'q' : matrice[mob_position.x][mob_position.y] = MOB_gauche; ; break;
				case 's' : matrice[mob_position.x][mob_position.y] = MOB_bas; ; break;
				case 'd' : matrice[mob_position.x][mob_position.y] = MOB_droite; ; break;
			}
			matrice[tampon.x][tampon.y] = CHEMIN;
		}       
			matrice[mob_position.x][mob_position.y] = MOB;
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
	
	matrice[3][17]=COFFRE;
	
    while(matrice[ma_position.x][ma_position.y] != OBJECTIF){
        while(compteur < nb_coffre){
			system("clear");
			placement_mob(matrice);
            placement_perso(matrice, &compteur);
            affichage(matrice);
            
        }
        system("clear");
        matrice[2][17] = OBJECTIF;
        placement_mob(matrice);
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
