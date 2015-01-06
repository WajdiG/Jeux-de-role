/**
*\file deplacement.h
*\brief Regroupe les prototypes pour le deplacement des entités et le démarage du jeu
*\author Joris Toulmonde, Godefroy THIEULART
*\version 0.1
*\date 25 Novembre 2014
*/
#ifndef __DEPLACEMENT_H__
#define __DEPLACEMENT_H__

#include "crea_avatar.h"

#define N 20 /**< Taille de la matrice region*/
#define MUR 0 /**< Entier modélisant un mur*/
#define CHEMIN 1 /**< Entier modélisant le chemin à emprunter disponible pour le joueur et le monstre*/
#define COFFRE 2 /**< Entier modélisant un coffre*/
#define JOUEUR 3 /**< Entier modélisant le joueur*/
#define OBJECTIF 4 /**< Entier modélisant un objectif*/
#define MOB 5 /**< Entier modélisant un monstre*/

/**
 *\struct t_coordonees
 *\brief Structure comportant les coordonnées de la case correspondante
 */
typedef struct {int x,y;}t_coordonees;

/**
* \fn void affichage(int matrice[N][N])
* \brief Fonction permettant l'affichage de la carte a chaque tour.
* \param matrice[N][N] matrice ou chaque case contient soir un mur, un chemin, un joueur, un coffre ou un monstre
**/
void affichage(int matrice[N][N], int pvJoueur, int manaJoueur, int enduJoueur, int pvMob, int cpt_laby, int*parade, int*distance);

/**
* \fn void rechercheJoueur(int matrice[N][N])
* \brief Fonction qui recherche les coordonnées du joueur sur la carte
* \param matrice[N][N] matrice ou chaque case contient soir un mur, un chemin, un joueur, un coffre ou un monstre
**/
void rechercheJoueur(int matrice[N][N]);

/**
* \fn void deplacement_perso(int matrice[N][N])
* \brief Fonction permettant de deplacer le joueur a chaque tour ou le faire agir
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void deplacement_perso(int*parade, int*distance,int matrice[N][N], int*pvMob, int*enduJoueur, int*pvJoueur, int*manaJoueur, t_joueur*joueur, int pvMax);

/**
* \fn int coffre()
* \brief Fonction permettant de voir s'il y a des coffres sur la carte
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemain, un coffre ou un monstre
* \return Renvoi 1 s'il n'y a plus de coffre sur la carte
**/
int coffre(int matrice[N][N]);

/**
* \fn void jouer()
* \brief Fonction permettant d'afficher le menu du jeu
**/
void jouer();

#endif
