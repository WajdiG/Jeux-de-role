/**
 *\file pile.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

#define M 100

//typedef struct {int x, y;}t_coordonees;

static t_coordonees pile[M];
static int sommet;

void initpile(void){
	sommet=-1;
}

void empiler(t_coordonees coord){
	if(sommet<M-1){
		sommet++;
		pile[sommet].x=coord.x;
		pile[sommet].y=coord.y;
	}
}

void depiler(t_coordonees *coord){
	if(sommet>-1){
		coord->x=pile[sommet].x;
		coord->y=pile[sommet].y;
		sommet--;
	}
}

int sommet_pile(t_coordonees *coord){
	if(sommet>-1){
		coord->x=pile[sommet].x;
		coord->y=pile[sommet].y;
		return 1;
	}
	return 0;
}

int pilevide(void){
	return(sommet==-1);
}
