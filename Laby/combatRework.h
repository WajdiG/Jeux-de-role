/**
 *\file combatRework.h
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Godefroy THIEULART
 *\version 0.2
 *\date 01 Decembre 2014
*/

#ifndef __COMBATREWORK_H__
#define __COMBATREWORK_H__

#include "IA.h"
#define N 20 /**< Taille de la matrice region*/

void guerison(t_joueur*joueur, int*pvJoueur, int*manaJoueur,int pvMax);
void destruction(int matrice[N][N], t_coordonees ma_position,int*pvMob,t_joueur*joueur, int*manaJoueur);
void degatHaut(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatGauche(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatBas(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatDroite(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);

#endif
