/**
 *\file accueil.h
 *\brief prototypes des fonctions gérants l'interface du jeu
 *\author Godefroy THIEULART
 *\version 0.2
 *\date 22 Octobre 2014
*/
#ifndef __ACCUEIL_H__
#define __ACCUEIL_H__

#include "region.h"

/**
* \fn void ecran_accueil()
* \brief Fonction d'affichage de l'écran d'accueil du jeu.
**/
void ecran_accueil();

/**
* \fn void Option_jeu(int matrice[N][N])
* \brief Fonction d'affichage du premier ecran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu(int matrice[N][N]);

/**
* \fn void Option_jeu_2(int matrice[N][N])
* \brief Fonction d'affichage du second écran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu_2(int matrice[N][N]);

/**
* \fn void Option_jeu_3(int matrice[N][N])
* \brief Fonction d'affichage du troisième écran d'option du jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Option_jeu_3(int matrice[N][N]);

/**
* \fn void Menu_Jeu(int matrice[N][N])
* \brief Fonction d'affichage du menu de jeu.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void Menu_Jeu(int matrice[N][N]);

/**
* \fn void Quitter_Jeu()
* \brief Fonction de l'écran de fermeture du jeu.
**/
void Quitter_Jeu();

/**
* \fn void defeat(int matrice[N][N])
* \brief Fonction d'affichage de l'écran de jeu en cas de défaite du joueur.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void defeat(int matrice[N][N]);

/**
* \fn void victory(int matrice[N][N])
* \brief Fonction d'affichage de l'écran du jeu en cas de victoire du joueur.
* \param matrice[N][N] est la matrice contenant le labyrinthe
**/
void victory(int matrice[N][N]);

/**
* \fn int continuer(int matrice[N][N])
* \brief Fonction faisant tourner le labyrinthe du programme
* \param matrice[N][N] est la matrice contenant le labyrinthe
* \return renvoie 1 si le joueur meurt, renvoie 0 sinon
**/
int continuer(int matrice[N][N]);

#endif
