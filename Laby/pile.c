/**
 *\file pile.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris TOULMONDE, Godefroy THIEULART
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

#define M 100 /**< constante entière définissant la taille de la pile de structure */

//typedef struct {int x, y;}t_coordonees;

static t_coordonees pile[M]; /**< Pile de structure */
static int sommet; /**< constante définissant le sommet de la pile */

/**
 *\fn initpile(void)
 *\brief initialise la pile
 */
void initpile(void){
	sommet=-1;
}

/**
 *\fn empiler(t_coordonees coord)
 *\brief Empile une strcuture dans la pile
 *\param t_coordonees coord 
 */
void empiler(t_coordonees coord){
	if(sommet<M-1){
		sommet++;
		pile[sommet].x=coord.x;
		pile[sommet].y=coord.y;
		//pile[sommet] = coord;
	}
}

/**
 *\fn depiler(t_coordonees *coord)
 *\brief Depile une strcuture de la pile
 *\param t_coordonees *coord 
 */
void depiler(t_coordonees *coord){
	if(sommet>-1){
		coord->x=pile[sommet].x;
		coord->y=pile[sommet].y;
		sommet--;
	}
}

/**
 *\fn sommet_pile(t_coordonees *coord)
 *\brief Place les coordonnées du sommet de la pile dans la structure coord
 *\param t_coordonees *coord 
 */
int sommet_pile(t_coordonees *coord){
	if(sommet>-1){
		coord->x=pile[sommet].x;
		coord->y=pile[sommet].y;
		return 1;
	}
	return 0;
}

/**
 *\fn pilevide(void)
 *\brief Retourne vrai si la pile est vide
 */
int pilevide(void){
	return(sommet==-1);
}
