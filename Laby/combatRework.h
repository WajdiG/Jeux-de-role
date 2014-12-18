#ifndef __COMBATREWORK_H__
#define __COMBATREWORK_H__

#include "IA.h"
#define N 20

void guerison(t_joueur*joueur, int*pvJoueur, int*manaJoueur,int pvMax);
void destruction(int matrice[N][N], t_coordonees ma_position,int*pvMob,t_joueur*joueur, int*manaJoueur);
void degatHaut(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatGauche(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatBas(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);
void degatDroite(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur,int*distance);

#endif
