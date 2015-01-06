/**
*\file JDR1_0.h
*\brief regroupe tout les prototypes des fonctions nécessaire à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/
#ifndef __JDR1_0_H__
#define __JDR1_0_H__


#include "crea_avatar.h"
#include "sauvegarde.h"
#include "charger.h"
#include "pile_tab.h"
#include "region.h"
#include "monde.h"
#include "deplacement.h"

/**
*\struct t_statcombat
*\brief structure contenant toutes les statistiques liées au combat
*/
typedef struct{int victoire,defaite,total; float pourvic,pourdef;}t_statcombat;

/**
*\fn afficher_joueur(void)
*\brief fonction permettant d'afficher les caractéristiques du joueur
*/
void afficher_joueur();

/**
 *\fn nouvelle_partie(int **) 
 *\brief fonction permettant au joueur de démarrer une nouvelle partie
 *\param matrice prend en paramètre une matrice de taille NxN
 */
void nouvelle_partie(int matrice[N][N]);

/**
 *\fn charger_par(int **) 
 *\brief fonction permettant au joueur de charger une partie et de la continuer
 *\param matrice prend en paramètre une matrice de taille NxN
 */
void charger_par(int matrice[N][N]);

#endif
