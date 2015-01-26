/**
 *\file IA.h
 *\brief fichier contenant les prototypes des fonctions liées à l'intelligence artificielle des mobs
 *\author Godefroy THIEULART
 *\version 0.2
 *\date 01 Novembre 2014
*/
#ifndef __IA_H__
#define __IA_H__

#include "deplacement.h"

#define N 20 /**< Taille de la matrice region*/

/**
* \fn void tradRandom(int matrice[N][N], char region[N][N])
* \brief Fonction permettant de traduire la matrice générer aléatoirement en matrice lisible par le programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemain, un coffre ou un monstre
* \param region[N][N] Matrice de caractère ou chaque case contient soit un mur, un coffre ou un monstre
**/
void tradRandom(int matrice[N][N], char region[N][N]);

/**
* \fn void tradVision(int matrice[N][N])
* \brief Fonction permettant de traduire la carte du jeu en carte lisible par l'IA du jeu dans une nouvelle matrice
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void tradVision(int matrice[N][N]);

/**
* \fn void affVision2(int matrice[N][N])
* \brief Fonction permettant d'afficher la matrice contenant la vision de l'IA, mais en plus simplifié, celle-ci n'a été utilisé que durant la conception du programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void affVision2(int matrice[N][N]);

/**
* \fn void affVision(int matrice[N][N])
* \brief Fonction permettant d'afficher la matrice contenant la vision de l'IA, à l'état brute, celle-ci n'a été utilisé que durant la conception du programme
* \param matrice[N][N] Matrice ou chaque case contient soit un mur, un joueur, un chemin, un coffre ou un monstre
**/
void affVision(int matrice[N][N]);


/**
* \fn void trouverMob(int*mobx, int*moby)
* \brief Fonction permettant de chercher les coordonnées de l'IA sur la matrice de jeu
* \param *mobx qui contiendra la coordonnées x de l'IA dans la matrice
* \param *moby qui contiendra la coordonnée y de l'IA
**/
void trouverMob(int *mobx, int *moby);

/**
* \fn void resetMob()
* \brief Fonction permettant de réinitialiser la vision de l'IA, nous permettant par la suite de la mettre à jour
**/
void resetMob();

/**
* \fn t_coordonees ecrireChemin()
* \brief Fonction qui génèrera les chemin que l'IA pourra emprunter pour rejoindre le joueur sur la carte
* \return renvoi un structure contenant les coordonnées de la case adjacente au joueur
**/
t_coordonees ecrireChemin();


/**
* \fn int MobNextToJoueur(int mobx, int moby)
* \brief Fonction permettant de savoir si l'IA est en contact avec le joueur afin de décider de l'action à faire
* \return renvoie 1 si l'IA se trouve sur une case adjacente au joueur, renvoie 0 autrement
**/
int MobNextToJoueur(int mobx, int moby);

/**
* \fn void lireChemin(t_coordonees cheminRetour)
* \brief Fonction permettant de chercher le chemin le plus rapide pour que l'IA puisse rejoindre le joueur
* \param cheminRetour contient les coordonnées de la case se trouvant à coté du joueur
**/
void lireChemin(t_coordonees cheminRetour);

/**
* \fn void IA(int matrice[N][N], int*pvJoueur, int*parade, int*enduJoueur, int cpt_laby)
* \brief Fonction responsable de la totalité de l'IA, de ses choix et de ses actions
* \param matrice[N][N] est la matrice contenant le jeu
* \param *pvJoueur est un pointeur contenant les PV du joueur et nous permettant de les modifiés
* \param parade contient une valeur booléenne afin de savoir si le joueur s'est mis en parade, modifiera le calcul des dégats subis
* \param *enduJoueur est la variable pointeur contenant l'endurance du joueur permettant de les modifié
* \param cpt_laby est une variable contenant le nombre de labyrinthe réussi par le joueur, celle-ci permettra de determiner la difficulté de l'IA
**/
void IA(int vision[N][N], int*pvJoueur, int*parade, int*enduJoueur, int cpt_laby);

#endif
