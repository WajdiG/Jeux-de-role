/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris Toulmonde, Godefroy Thieulart
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
#include "combatRework.h"
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5

extern int quitter;
typedef struct{int x, y;}t_coordonees;
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
		printf("\r\n");
	}
}

/**
* \fn void rechercheJoueur(int matrice[N][N])
* \brief Fonction qui recherche les coordonnées du joueur sur la carte
* \param matrice[N][N] matrice ou chaque case contient soir un mur, un chemin, un joueur, un coffre ou un monstre
**/
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

/*void initialisation(int matrice[N][N]){

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
}*/

/**
* \fn void deplacement_perso(int matrice[N][N])
* \brief Fonction permettant de deplacer le joueur a chaque tour.
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/

void deplacement_perso(int matrice[N][N]){
		int x;
        t_coordonees tampon;
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;
        raw();
        keypad(stdscr, TRUE);
		x = getch();
		switch(x){
void deplacement_perso(int matrice[N][N], int*pvMob){
		
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
			case 'h' : creer_region() ; tradRandom(matrice, region) ; break;
			case 'i' : degatHaut(matrice, ma_position, pvMob) ; break;
			/*case 'j' : degatGauche() ; break;
			case 'k' : degatBas() ; break;
			case 'l' :degatDroite() ; break;*/
		}	
		if(matrice[ma_position.x][ma_position.y] == MUR){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else{
			matrice[tampon.x][tampon.y] = CHEMIN;

		}
		refresh();
		endwin();
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

/**
* \fn int nb_coffre_map(int matrice[N][N])
* \brief Fonction permettant de compter le nombre coffre present sur la carte au debut du jeu
* \param matrice[N][N]
* \return Retourne le nombre de coffre sur la carte
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
	int compteur = 0;
	int nb_coffre;
    raw();
	initialisation(matrice);
	printf("\n\n");
	nb_coffre = nb_coffre_map(matrice);
	
	matrice[3][17]=COFFRE;
	initscr();
   	while(matrice[ma_position.x][ma_position.y] != OBJECTIF){
   		matrice[ma_position.x][ma_position.y] = JOUEUR; // position initiale du joueur
       		if(compteur < nb_coffre){
				affichage(matrice);
				deplacement_perso(matrice);
				comptage_coffre(matrice, &compteur); 	          	    
       	 	}
       	 	else{
				matrice[2][17] = OBJECTIF; //la porte est visible maintenant
				affichage(matrice); 
				deplacement_perso(matrice);
				comptage_coffre(matrice, &compteur);  
			}       	             
    }    
	printf("WELL PLAYED NOOB !!!!\n");
}
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
		int pvMob=100;
		Menu_Jeu();
		rechercheJoueur(matrice);
		sorti=ma_position;
		while(matrice[ma_position.x][ma_position.y] != OBJECTIF && quitter != 1){
			
			rechercheJoueur(matrice);

			affichage(matrice);
			deplacement_perso(matrice, &pvMob);
			VD=IA(matrice);
			
			scanf("%c", &temp); //pour absorber le caractère resté dans le buffer
			
			if(VD==1){
				defeat();
				quitter=0;
				break;
			}
			if(coffre(matrice)){
				matrice[sorti.x][sorti.y] = OBJECTIF;
			}
			
			affichage(matrice);
		}
		if(VD==0){
			victory();
			quitter=0;
		}
	}  	
		
	return EXIT_SUCCESS;
	
}
