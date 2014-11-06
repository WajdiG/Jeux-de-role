#define N 16
int principale;
int secondaire;
char pseudo[N];
typedef enum{homme=1,femme,sans}t_sexe;
typedef enum{elfe=1,humain,nain,orc,troll}t_race;
typedef enum{anorexique=1,mince,moyen,surpoids,obese,obesemo}t_poids;
typedef struct{t_sexe sexe;t_race race;t_poids poids;}t_physique;
typedef struct{int rapidite,agilite,force,puissance,intelligence,perception,chance;}t_comp1;
typedef struct{int archerie,precision,unemain,deuxmains,lance,contondant,parade,armureleg,armurelou;}t_combat;
typedef struct{int discretion,crochetage,dague,acrobatie;}t_furtif;
typedef struct{int persuasion,charisme,marchandage;}t_dial;
typedef struct{int sante,mana,endu;}t_vie;
typedef struct{int destruction,guerison,invocation;}t_magie;
typedef struct{char pseudo[N];t_physique physique;t_vie vie;t_comp1 comp;t_combat combat;t_furtif furtif;t_dial dial;t_magie magie;}t_joueur;
void initstruct(t_joueur *joueur);
void creer_pseudo(t_joueur *joueur);
void race(t_joueur *joueur);
void sexe(t_joueur *joueur);
void taille(t_joueur *joueur);
void poids(t_joueur *joueur);
void initCaract(t_joueur *joueur);
void attribution_points(t_joueur *joueur, int principale, int secondaire);
void config(t_joueur *joueur);
void crea_ava(t_joueur *joueur,int principale,int secondaire);


