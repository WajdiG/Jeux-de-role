#ifndef __DEPLACEMENT_H__
#define __DEPLACEMENT_H__

#include "crea_avatar.h"

#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5

typedef struct {int x,y;}t_coordonees;

void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob, int cpt_laby, int*parade, int*distance);
void rechercheJoueur(int matrice[N][N]);
void deplacement_perso(int*parade, int*distance,int matrice[N][N], int*pvMob, int*enduJoueur, int*pvJoueur, int*manaJoueur, t_joueur*joueur, int pvMax);
int coffre(int matrice[N][N]);
void jouer();

#endif
