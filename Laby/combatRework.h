#ifndef __COMBATREWORK_H__
#define __COMBATREWORK_H__

#include "IA.h"
#define N 20

void degatHaut(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur);
void degatGauche(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur);
void degatBas(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur);
void degatDroite(int matrice[N][N],t_coordonees ma_position, int*pvMob, int*enduJoueur,t_joueur*joueur);

#endif
