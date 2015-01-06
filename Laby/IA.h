/**
 *\file IA.h
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Godefroy THIEULART
 *\version 0.2
 *\date 01 Novembre 2014
*/
#ifndef __IA_H__
#define __IA_H__

#include "deplacement.h"

#define N 20 /**< Taille de la matrice region*/

void tradRandom(int matrice[N][N], char region[N][N]);
void tradVision(int matrice[N][N]);
void affVision2(int matrice[N][N]);
void affVision(int matrice[N][N]);
void trouverMob(int *mobx, int *moby);
void resetMob();
t_coordonees ecrireChemin();
int MobNextToJoueur(int mobx, int moby);
void lireChemin(t_coordonees cheminRetour);
void IA(int vision[N][N], int*pvJoueur, int*parade, int*enduJoueur, int cpt_laby);

#endif
