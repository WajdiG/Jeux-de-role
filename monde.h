/**
*\file monde.c
*\brief regroupe toutes les fonctions nécessaires à la gestion du monde
*\author Wajdi Guedouar
*\version 0.1
*\date 27 Novembre 2014
*/
#ifndef __MONDE_H__
#define __MONDE_H__

#include "region.h"

#define X 3
#define Y 3

typedef struct{int x,y;}t_coord;

/**
 *\fn init_monde(void)
 *\brief initialise le contenu de la matrice monde 
 */
void init_monde();

/**
 *\fn inclure_region(t_coord)
 *\brief permet d'inclure une region dans le monde
 *\param coord contient les coordonnées courantes du joueur dans la matrice monde
 */
void inclure_region(t_coord coord);

/**
 *\fn deplacement_case_monde(t_coord)
 *\brief permet de deplacer le joueur d'une case dans le monde
 *\param *coord coordonnées correspondants à la poisition actuelles du joueur
 */
void deplacement_case_monde(t_coord *coord);

/**
 *\fn deplacement_monde(void)
 *\brief permet au joueur de se déplacer dans le monde
 */
void deplacement_monde();

/**
 *\fn aff_monde(void)
 *\brief permet d'afficher le monde
 */
void aff_monde();

/**
 *\fn aff_region_monde(void)
 *\brief permet d'afficher la région dans laquelle vous vous trouvez
 */
void aff_region_monde();

#endif