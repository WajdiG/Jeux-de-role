/**
*\file pile_tab.c
*\brief regroupe toutes les primitives de pile par tableau
*\author Wajdi Guedouar
*\version 0.1
*\date 25 Novembre 2014
*/

#include <stdio.h>
#include <stdlib.h>

#define tmax 20

extern int pile[tmax];
extern int sommet;
int tete;
int queue;
int nb_valeur;
int nouv;


//primitive pile
void initpile(){
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

int pilevide(){
	return (sommet==-1);
}

int pilepleine(){
	return(sommet==tmax);
}

