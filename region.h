/**
*\file region.h
*\brief regroupe tout les prototypes de fonctions nécessaires à la création d'une région : génération aléatoire d'un labyrinthe
*\author Wajdi Guedouar
*\version 0.1
*\date 27 Novembre 2014
*/

#define N 20
#define M 20
#define tmax N+M
#define NB_COFFRE 4


int tab[12];
int pile[tmax];
int sommet;

/**
 *\fn initregion
 *\brief initialise la region où toutes les cases valent X, ainsi que le tableau tab où tout vaut 1
 */
void initregion();

/**
 *\fn aff_region
 *\brief affiche la region à l'écran
 */
void aff_region();

/**
 *\fn verif_coffre(int , int)
 *\brief initialise la matrice, toutes les cases valent X
 *\param i entier représentant l'absisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre) et 1 si non
 */
int verif_coffre(int i, int j);

/**
 *\fn verif_cour(int , int)
 *\brief verifie que la case dans laquelle on se trouve soit différente de C (un coffre) ou P (le joueur) 
 *\param i entier représentant l'absisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre) ou P (le joueur) et 1 si non
 */
int verif_cour(int i, int j);

/**
 *\fn place_coffre
 *\brief permet de placer des coffres C aléatoirement dans la matrice
 */
void place_coffre();

/**
 *\fn place_joueur
 *\brief permet de placer le joueur aleatoirement sur la map
 */
void place_joueur();

/**
 *\fn place_monstre
 *\brief permet de placer le monstre aleatoirement sur la map
 */
void place_monstre();

/**
 *\fn chemin
 *\brief permet de générer un chemin depuis P (le joueur) vers les bord de la matrice, depuis C (un coffre) vers un chemin existant
 */
void chemin();

/**
 *\fn carre
 *\brief créer un espace autour des coffres et du joueur
 */
void carre();

 /**
 *\fn region
 *\brief creer une region : labyrinthe aléatoire
 */
void creer_region();
