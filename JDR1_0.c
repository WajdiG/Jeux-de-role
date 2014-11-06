/**
*\file JR1_0.c
*\brief regroupe toutes les fonctions nécessaire à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crea_avatar.h"

#define N 16

/**
 *\struct t_statcombat
 *\brief structure contenant toutes les statistiques liées au combat
 */
typedef struct{int victoire,defaite,total; float pourvic,pourdef;}t_statcombat;		

int main(){
    principale=5;
    secondaire=10;
    
	t_joueur joueur;

	crea_ava(&joueur,principale,secondaire);

	return EXIT_SUCCESS;
}
