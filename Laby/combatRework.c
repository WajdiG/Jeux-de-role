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

#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5

extern int quitter;
extern char region[N][N];

t_coordonees mes_choix[4];
t_coordonees ma_position;
t_coordonees sorti;

void degatHaut(int matrice[N][N], t_coordonees ma_position, int*pvMob){
	int x = ma_position.x;
	int y = ma_position.y;
	
	if(matrice[x][y+1]==MOB){
		pvMob-=10;
		int PV=*pvMob;
		printf("\n Vous infligez 10 points de degat ! \n PV Mob = %i \n",PV);
	}
	else{
		printf("\n frapper dans le vide \n");
	}
}