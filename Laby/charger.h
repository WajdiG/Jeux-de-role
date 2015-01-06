/**
*\file charger.h
*\brief regroupe les prototypes des fonctions nécéssaires pour charger une partie
*\author Wajdi Guedouar
*\version 0.1
*\date 19 Novembre 2014
*/

#ifndef __CHARGER_H__
#define __CHARGER_H__

#include "monde.h"
#include "crea_avatar.h"

/**
*\fn charger_jeu(t_joueur*joueur,t_coord*coord, char**monde [X][Y],FILE*fichier)
*\brief fonction permettant de charger toutes les données contenue dans le fichier de sauvegarde dans la structure t_joueur jouer
*\param *joueur pointeur sur la structure t_joueur joueur
*\param coord coordonnées du joueur dans la matrice monde
*\param monde[X][Y] matrice monde représentant le monde dans lequel le joueur évolue
*\param fichier fichier contenant les données sauvegardées
*/
void charger_jeu(t_joueur *joueur,t_coord *coord,char ** monde[X][Y],FILE*fichier);

/**
*\fn charger_partie(char*charger, t_joueur*joueur,t_coord*coord, char**monde[X][Y])
*\brief fonction permettant de charger une partie
*\param charger tableau contenant le pseudo du joueur
*\param joueur pointeur sur la structure t_joueur joueur
*\param coord coordonnées du joueur dans la matrice monde
*\param monde[X][Y] matrice monde représentant le monde dans lequel le joueur évolue
*\return int renvoie 1 si le fichier charger est valide, 0 si non
*/
int charger_partie(char* charger,t_joueur* joueur,t_coord *coord, char ** monde[X][Y]);

#endif
