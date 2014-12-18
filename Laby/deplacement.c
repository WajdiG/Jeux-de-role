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
void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob, int cpt_laby, int*parade, int*distance){
	int i, j;
	system("clear");
	
	if(cpt_laby<10){
		printf("\r\nO=============Le=niveau=du=Labyrinthe=est=de=%i==============O\r\n", cpt_laby);
	}
	else{
		printf("\r\nO=============Le=niveau=du=Labyrinthe=est=de=%i==============O\r\n", cpt_laby);
	}
	
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

		if(pvJoueur==100){	printf("PV : %i                                         PV Mob = %i \r\n", pvJoueur, pvMob);	}
		else if(pvJoueur>9 && pvJoueur<100){	 printf("PV : %i                                           PV Mob = %i \r\n", pvJoueur, pvMob);	}
		else if(pvJoueur<10){	 printf("PV : %i                                             PV Mob = %i \r\n", pvJoueur, pvMob);	}
		printf("Mana : %i \r\n", manaJoueur);
		printf("Endurance : %i \r\n", enduJoueur);
		if(*distance==1){
			printf("distance activé");
		}
		else{
			printf("distance desactivé");
		}
		printf("\r\nO=====================Boite=A=Dialogue========================O\r\n");
		
		if(*parade==1){
			printf("\r\n         ==> Vous parez le prochain coup <== \r\n");
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
void deplacement_perso(int*parade, int*distance,int matrice[N][N], int*pvMob, int*enduJoueur, int*pvJoueur, int*manaJoueur, t_joueur*joueur,int pvMax){
	
        t_coordonees tampon;
		int x;
		
		x = getch();
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;

		switch(x){
			
			//fait bouger le joueur dans la direction voulu
			case 'z' : ma_position.x-- ; break;
			case 'q' : ma_position.y-- ; break;
			case 's' : ma_position.x++ ; break;
			case 'd' : ma_position.y++ ; break;
			
			//fait attaquer le joueur dans la direction voulu
			case 'i' : degatHaut(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'j' : degatGauche(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'k' : degatBas(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			case 'l' : degatDroite(matrice, ma_position, pvMob, enduJoueur,joueur,distance) ; break;
			
			//permet au joueur d'utiliser sa magie
			case 'u' : guerison(joueur, pvJoueur, manaJoueur,pvMax) ; break;
			case 'o' : destruction(matrice, ma_position,pvMob, joueur, manaJoueur) ; break;
			
			//commande secondaire du joueur
			case ' ' : *parade=1 ; *distance=0 ; break;
			case 'n' : *parade=0 ; *distance=1 ; break;
		}
		
		//empeche le joueur de marcher sur les murs ou sur le mob, et libère le chemin derrière lui
		if(matrice[ma_position.x][ma_position.y] == MUR){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
		}
		else if(matrice[ma_position.x][ma_position.y] == MOB){
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
	init_monde();
	jouer();
	endwin();
	return EXIT_SUCCESS;
	
}
