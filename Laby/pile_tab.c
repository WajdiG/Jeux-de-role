/**
*\file pile_tab.c
*\brief regroupe toutes les primitives de pile par tableau
*\author Wajdi Guedouar 
*\author Godefroy Thieulart
*\author Joris Toulmonde
*\version 0.1
*\date 25 Novembre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile_tab.h"
#include "deplacement.h"

#define tmax 20 /**< Taille de la pile */
#define M 100 /**< Taille de la pile de Structure */

static t_coordonees pileStruct[M];
extern int pile[tmax];

extern int sommet;
static int sommetStruct;

int tete; /**< constante définissant la tete de la liste */
int queue; /**< constante définissant la queue de la liste */
int nb_valeur; /**< constante définissant le nombre de valeur dans la liste */
int nouv; /**< constante définissant l'éklément nouveau de la liste */

/**
 *\fn initpile(void)
 *\brief initialise la pile
 */
//primitive pile
void initpile(void){
	sommet=-1;
}

/**
 *\fn empiler(t_coordonees coord)
 *\brief Empile une strcuture dans la pile
 *\param t_coordonees coord 
 */
void empiler(int c){
	if(sommet<tmax-1){
		sommet++;
		pile[sommet]=c;
	}
}

/**
 *\fn depiler(t_coordonees *coord)
 *\brief Depile une strcuture de la pile
 *\param t_coordonees *coord 
 */
void depiler(int*v){
	if(sommet>-1){
		*v=pile[sommet];
		sommet--;
	}
}

/**
 *\fn pilevide(void)
 *\brief Retourne vrai si la pile est vide
 */
int pilevide(void){
	return (sommet==-1);
}

/**
 *\fn pilepleine(void)
 *\brief Retourne vrai si la pile est pleine
*/
int pilepleine(void){
	return(sommet==tmax);
}

/**
 *\fn initpileStruct(void)
 *\brief initialise la pile
 */
void initpileStruct(void){
	sommetStruct=-1;
}

/**
 *\fn empilerStruct(t_coordonees coord)
 *\brief Empile une strcuture dans la pile
 *\param t_coordonees coord 
 */
void empilerStruct(t_coordonees coord){
	if(sommetStruct<M-1){
		sommetStruct++;
		pileStruct[sommetStruct].x=coord.x;
		pileStruct[sommetStruct].y=coord.y;
	}
}

/**
 *\fn depilerStruct(t_coordonees *coord)
 *\brief Depile une strcuture de la pile
 *\param t_coordonees *coord 
 */
void depilerStruct(t_coordonees *coord){
	if(sommetStruct>-1){
		coord->x=pileStruct[sommetStruct].x;
		coord->y=pileStruct[sommetStruct].y;
		sommetStruct--;
	}
}

/**
 *\fn sommet_pile(t_coordonees *coord)
 *\brief Place les coordonnées du sommet de la pile dans la structure coord
 *\param t_coordonees *coord 
 */
int sommet_pile(t_coordonees *coord){
	if(sommetStruct>-1){
		coord->x=pileStruct[sommetStruct].x;
		coord->y=pileStruct[sommetStruct].y;
		return 1;
	}
	return 0;
}

/**
 *\fn pilevideStruct(void)
 *\brief Retourne vrai si la pile est vide
 */
int pilevideStruct(void){
	return (sommetStruct==-1);
}
