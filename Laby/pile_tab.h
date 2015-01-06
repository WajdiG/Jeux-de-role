/**
*\file pile_tab.h
*\brief regroupe toutes les déclarations des primitives de pile par tableau
*\author Wajdi Guedouar, Joris Toulmonde, Godefroy Thieulart
*\version 0.1
*\date 25 Novembre 2014
*/
#ifndef __PILE_TAB_H__
#define __PILE_TAB_H__

#include "deplacement.h"
int tete; /**< constante définissant la tete de la liste */
int queue; /**< constante définissant la queue de la liste */
int nb_valeur; /**< constante définissant le nombre de valeur dans la liste */
int nouv; /**< constante définissant l'éklément nouveau de la liste */

/**
 *\fn initpile(void)
 *\brief initialise la pile
 */
void initpile();

/**
 *\fn empiler(int c)
 *\brief Empile une strcuture dans la pile
 *\param t_coordonees coord 
 */
void empiler(int c);

/**
 *\fn depiler(int*v)
 *\brief Depile une strcuture de la pile
 *\param t_coordonees *coord 
 */
void depiler(int*v);

/**
 *\fn pilevide(void)
 *\brief Retourne vrai si la pile est vide
 */
int pilevide();

/**
 *\fn pilepleine(void)
 *\brief Retourne vrai si la pile est pleine
 */
int pilepleine();

void initpileStruct();
void empilerStruct(t_coordonees coord);
void depilerStruct(t_coordonees *coord);
int sommet_pile(t_coordonees *coord);
int pilevideStruct();

#endif
