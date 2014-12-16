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
typedef struct{int x, y;}t_coordonees;
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
		printf("\r\n");
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
		int x;
        t_coordonees tampon;
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;
        raw();
        keypad(stdscr, TRUE);
		x = getch();
		switch(x){
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