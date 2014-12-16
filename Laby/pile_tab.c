/**
*\file pile_tab.c
*\brief regroupe toutes les primitives de pile par tableau
*\author Wajdi Guedouar, Godefroy Thieulart, Joris Toulmonde
*\version 0.1
*\date 25 Novembre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile_tab.h"
#include "deplacement.h"

#define tmax 20
#define M 100

static t_coordonees pileStruct[M];
extern int pile[tmax];

extern int sommet;
static int sommetStruct;

int tete;
int queue;
int nb_valeur;
int nouv;


//primitive pile
void initpile(void){
	sommet=-1;
}

void empiler(int c){
	if(sommet<tmax-1){
		sommet++;
		pile[sommet]=c;
	}
}

void depiler(int*v){
	if(sommet>-1){
		*v=pile[sommet];
		sommet--;
	}
}

int pilevide(void){
	return (sommet==-1);
}

int pilepleine(void){
	return(sommet==tmax);
}

void initpileStruct(void){
	sommetStruct=-1;
}

void empilerStruct(t_coordonees coord){
	if(sommetStruct<M-1){
		sommetStruct++;
		pileStruct[sommetStruct].x=coord.x;
		pileStruct[sommetStruct].y=coord.y;
	}
}

void depilerStruct(t_coordonees *coord){
	if(sommetStruct>-1){
		coord->x=pileStruct[sommetStruct].x;
		coord->y=pileStruct[sommetStruct].y;
		sommetStruct--;
	}
}

int sommet_pile(t_coordonees *coord){
	if(sommetStruct>-1){
		coord->x=pileStruct[sommetStruct].x;
		coord->y=pileStruct[sommetStruct].y;
		return 1;
	}
	return 0;
}

int pilevideStruct(void){
	return (sommetStruct==-1);
}
