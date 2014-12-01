/**
*\file crea_avatar.h
*\brief regroupe tous les prototypes de fonctions nécessaires à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/

#define P 16 /**<constante définissant la taille maximale du pseudo*/
int principale; /**<nombre de points de compétence principale distribuable */
int secondaire; /**<nombre de points de compétence secondaire distribuable*/

/**
 *\enum t_sexe
 *\brief type énuméré contenant le sexe de l'avatar  
 */
typedef enum{homme=1,femme,sans}t_sexe;

/**
 *\enum t_race
 *\brief type énumeré contenant la race du joueur parmis cinq races possibles 
 */
typedef enum{elfe=1,humain,nain,orc,troll}t_race;

/**
 *\enum t_poids
 *\brief type énuméré contenant la corpulence du joueur parmis 6 possibilitées 
 */
typedef enum{anorexique=1,mince,moyen,surpoids,obese,obesemo}t_poids;

/**
 *\struct t_physique
 *\brief stucture liée aux caractéristiques physiques du joueur, elle contient tout les types énumérés liés au physique ainsi que l'entier taille
 */
typedef struct{t_sexe sexe;t_race race;t_poids poids; int taille;}t_physique;	

/**
 *\struct t_comp1
 *\brief structure contenant les compétences principales du joueur
 */
typedef struct{int rapidite,agilite,force,puissance,intelligence,perception,chance;}t_comp1;	

/**
 *\struct t_combat
 *\brief structure contenant les compétences secondaires liées au combat
 */
typedef struct{int archerie,precision,unemain,deuxmains,lance,contondant,parade,armureleg,armurelou,corpscorps;}t_combat;	

/**
 *\struct t_furtif
 *\brief structure contenant les compétences secondaires liées à la furtivité
 */
typedef struct{int discretion,crochetage,dague,acrobatie;}t_furtif;	

/**
 *\struct t_dial
 *\brief structure contenant les compétences secondaires liées au dialogue
 */
typedef struct{int persuasion,charisme,marchandage;}t_dial;	

/**
 *\struct t_vie
 *\brief structure contenant les valeurs des points de vie, mana et endurance
 */
typedef struct{int sante,mana,endu;}t_vie;

/**
 *\struct t_magie
 *\brief structure contenant les compétences secondaires liées à la magie
 */
typedef struct{int destruction,guerison,invocation;}t_magie;	

/**
 *\struct t_joueur
 *\brief structure contenant toutes les structures et tableaux de données de joueur
 */
typedef struct{char pseudo[P];t_physique physique;t_vie vie;t_comp1 comp;t_combat combat;t_furtif furtif;t_dial dial;t_magie magie;}t_joueur; //structure regroupant toutes les structures précédentes

/**
 *\fn void initstruct(t_joueur*)
 *\brief fonction permettant d'initialiser toutes les valeurs contenue dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void initstruct(t_joueur *joueur);
/**
 *\fn void creer_pseudo(t_joueur*)
 *\brief fonction permettant au joueur de créer un pseudo et de le stocké dans le tableau char nom[] de la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void creer_pseudo(t_joueur *joueur);
/**
 *\fn void race(t_joueur*)
 *\brief fonction permettant au joueur de choisir une race parmis les choix du type énuméré t_race, son choix sera alors sauvegardé dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void race(t_joueur *joueur);
/**
 *\fn void sexe(t_joueur*)
 *\brief fonction permettant au joueur de choisir le sexe de son avatar, son choix sera sauvegardé dans le type énuméré t_sexe de la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void sexe(t_joueur *joueur);
/**
 *\fn void taille(t_joueur*)
 *\brief fonction permettant au joueur de choisir sa taille (en centimètre) parmis des choix proposés dépendant de sa race. Une fois valider, son choix sera sauvegardé dans l'entier int taille de la structure t_joueur 
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void taille(t_joueur *joueur);
/**
 *\fn void poids(t_joueur*)
 *\brief fonction permettant au joueur de choisir le poids de son avatar (en kg) en fonction de sa race, une fois choisit, la fonction calcule l'IMC de l'avatar et en fonction du résultat, associe une des valeurs du type énuméré t_poids dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void poids(t_joueur *joueur);
/**
 *\fn void initCaract(t_joueur*)
 *\brief fonction mettant à jour les compétences secondaires et principales du joueur en fonctions de l'IMC et de la race du joueur.
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void initCaract(t_joueur *joueur);
/**
 *\fn void attribution_points(t_joueur*,int,int)
 *\brief fonction permettant au joueur de répartir un nombre donné de points de compétences principales et secondaires.
 *\param *joueur pointeur sur la structure t_joueur joueur
 *\param principale nombre de points de compétences principales à répartir
 *\param secondaire nombre de points de compétences secondaires à répartir
 */
void attribution_points(t_joueur *joueur, int principale, int secondaire);
/**
 *\fn void config(t_joueur*)
 *\brief fonction permettant au joueur de voir un récapitulatif du contenu de la fonction t_joueur et lui permet de revenir sur la race, la taille, le poids, le sexe et le pseudo. Si non, il peut lancer l'aventure.
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void config(t_joueur *joueur);
/**
 *\fn void crea_ava(t_joueur*,int,int)
 *\brief fonction permettant d'appeler toutes les fonctions du fichier crea_avatar.c dans l'ordre voulu
 *\param *joueur pointeur sur la structure t_joueur joueur
 *\param principale nombre de points de compétences principales à répartir
 *\param secondaire nombre de points de compétences secondaires à répartir
 */
void crea_ava(t_joueur *joueur,int principale,int secondaire);


