/**
 *\file pile.h
 *\brief Regroupe les prototypes de fonction pour les piles
 *\author Joris TOULMONDE, Godefroy THIEULART
 *\version 0.2
 *\date 22 Octobre 2014
*/

/**
 *\struct t_coordonees
 *\brief structure contenant les coordonnées du joueur dans la matrice monde
 */
typedef struct {int x, y;}t_coordonees;

/**
 *\fn initpile(void)
 *\brief initialise la pile
 */
void initpile(void);

/**
 *\fn empiler(t_coordonees coord)
 *\brief Empile une strcuture dans la pile
 *\param t_coordonees coord 
 */
void empiler(t_coordonees coord);

/**
 *\fn depiler(t_coordonees *coord)
 *\brief Depile une strcuture de la pile
 *\param t_coordonees *coord 
 */
void depiler(t_coordonees *coord);

/**
 *\fn pilevide(void)
 *\brief Retourne vrai si la pile est vide
 */
int pilevide(void);

/**
 *\fn sommet_pile(t_coordonees *coord)
 *\brief Place les coordonnées du sommet de la pile dans la structure coord
 *\param t_coordonees *coord 
 */
int sommet_pile(t_coordonees *coord);
