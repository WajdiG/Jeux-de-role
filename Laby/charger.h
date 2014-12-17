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
 *\fn charger_struct(t_joueur *,t_coord *,FILE*)
 *\brief fonction permettant de charger toutes les données contenue dans le fichier de sauvegarde dans la structure t_joueur jouer
 *\param joueur pointeur sur la structure t_joueur joueur
 *\param fichier fichier contenant les données sauvegardées
 *\param coord ponture sur la structure t_coord contenant les coordonnées du joueur dans le monde
 */
void charger_jeu(t_joueur *joueur,t_coord *coord,char ** monde[X][Y],FILE*fichier);

/**
 *\fn void charger_partie(char*)
 *\brief fonction permettant de charger une partie
 *\param charger tableau contenant le pseudo du joueur
 *\return int renvoie 1 si le fichier charger est valide, 0 si non
 */
int charger_partie(char* charger,t_joueur* joueur,t_coord *coord, char ** monde[X][Y]);

#endif
