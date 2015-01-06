/**
 *\file accueil.h
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author THIEULART Godefroy
 *\version 0.2
 *\date 22 Octobre 2014
*/
#ifndef __ACCUEIL_H__
#define __ACCUEIL_H__

#include "region.h"

void ecran_accueil();
void Option_jeu(int matrice[N][N]);
void Option_jeu_2(int matrice[N][N]);
void Option_jeu_3(int matrice[N][N]);
void Menu_Jeu(int matrice[N][N]);
void Quitter_Jeu();
void Nouvelle_Partie(int matrice[N][N]);
void defeat(int matrice[N][N]);
void victory(int matrice[N][N]);
int continuer(int matrice[N][N]);

#endif
