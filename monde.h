/**
*\file monde.c
*\brief regroupe toutes les fonctions nécessaires à la gestion du monde
*\author Wajdi Guedouar
*\version 0.1
*\date 27 Novembre 2014
*/

/**
 *\fn init_monde(void)
 *\brief initialise le contenu de la matrice monde 
 */
void init_monde();

/**
 *\fn inclure_region(int, int)
 *\brief permet d'inclure une region dans le monde
 *\param i abscisse correspondant aux coordonnées de la region
 *\param j ordonnée correspondant aux coordonnées de la region
 */
void inclure_region(int i, int j);

/**
 *\fn aff_monde(int, int)
 *\brief permet d'inclure une region dans le monde
 *\param i abscisse correspondant aux coordonnées du joueur
 *\param j ordonnée correspondant aux coordonnées du joueur
 */
void aff_monde(int i, int j);
