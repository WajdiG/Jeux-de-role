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

void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob);
void rechercheJoueur(int matrice[N][N]);
void deplacement_perso(int matrice[N][N], int*pvMob, int*enduJoueur, t_joueur*joueur);
int coffre(int matrice[N][N]);
void jouer();

#endif
