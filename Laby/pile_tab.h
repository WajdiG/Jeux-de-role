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
int tete;
int queue;
int nb_valeur;
int nouv;

void initpile();
void empiler(int c);
void depiler(int*v);
int pilevide();
int pilepleine();

void initpileStruct();
void empilerStruct(t_coordonees coord);
void depilerStruct(t_coordonees *coord);
int sommet_pile(t_coordonees *coord);
int pilevideStruct();

#endif
