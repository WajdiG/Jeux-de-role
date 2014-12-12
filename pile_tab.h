/**
*\file pile_tab.h
*\brief regroupe toutes les déclarations des primitives de pile par tableau
*\author Wajdi Guedouar
*\version 0.1
*\date 25 Novembre 2014
*/

#ifndef __PILE_TAB_H__
#define __PILE_TAB_H__

int tete;
int queue;
int nb_valeur;
int nouv;

void initpile();
void empiler(int c);
void depiler(int*v);
int pilevide();
int pilepleine();

#endif