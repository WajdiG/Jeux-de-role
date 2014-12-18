#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "accueil.h"
#include "IA.h"
#include "region.h"
#include "combatRework.h"
#include "JDR1_0.h"
#include "deplacement.h"

extern int quitter;
extern char region[N][N];

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

/**
* \fn void deplacement_perso(int matrice[N][N])
* \brief Fonction permettant de deplacer le joueur a chaque tour.
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void deplacement_perso(int matrice[N][N], int*pvMob){
		
        t_coordonees tampon;
		int x;
		
		x = getch();
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;
		switch(x){
			case 'z' : ma_position.x-- ; break;
			case 'q' : ma_position.y-- ; break;
			case 's' : ma_position.x++ ; break;
			case 'd' : ma_position.y++ ; break;
			case 'h' : creer_region() ; tradRandom(matrice, region) ; break;
		}	
		if(matrice[ma_position.x][ma_position.y] == MUR){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else{
			matrice[tampon.x][tampon.y] = CHEMIN;
			matrice[ma_position.x][ma_position.y]=JOUEUR;
		}	
		refresh();        
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

void jouer(){
	int matrice[N][N];
	
	ecran_accueil();
	Menu_Jeu(matrice); 		
}

int main(){
	srand(time(NULL));
	initscr();
	raw();
	keypad(stdscr,TRUE);
	noecho();
	init_monde();
	jouer();
	endwin();
	return EXIT_SUCCESS;
	
}
