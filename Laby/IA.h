/**
 *\file IA.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author Joris Toulmonde, Godefroy Thieulart
 *\version 0.2
 *\date 22 Octobre 2014
*/

#define N 20
typedef struct {int x, y;}t_coordonees;

void affichage(int matrice[N][N]);
void tradVision(int matrice[N][N]);
void tradRandom(int matrice[N][N], char region[N][N]);
void affVision2(int matrice[N][N]);
void affVision(int matrice[N][N]);
void trouverMob(int *mobx, int *moby);
void trouvercible(int *Jx, int *Jy);
void resetMob();
t_coordonees ecrireChemin(t_coordonees cheminRetour);
void lireChemin(t_coordonees cheminRetour, int cptx, int cpty);
int IA(int vision[N][N]);
