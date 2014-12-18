/**
 *\file IA.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris Toulmonde, Godefroy Thieulart
 *\version 0.2
 *\date 22 Octobre 2014
*/
#ifndef __IA_H__
#define __IA_H__

#include "deplacement.h"

#define N 20

void tradRandom(int matrice[N][N], char region[N][N]);
void tradVision(int matrice[N][N]);
void affVision2(int matrice[N][N]);
void affVision(int matrice[N][N]);
void trouverMob(int *mobx, int *moby);
void trouvercible(int *Jx, int *Jy);
void resetMob();
t_coordonees ecrireChemin();
int MobNextToJoueur();
void lireChemin(t_coordonees cheminRetour, int cptx, int cpty);
void IA(int vision[N][N], int*pvJoueur);

#endif
