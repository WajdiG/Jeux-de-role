/**
*\file JR1_0.c
*\brief regroupe toutes les fonctions nécessaire à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>
#include "crea_avatar.h"
#include "sauvegarde.h"
#include "charger.h"
#include "pile_tab.h"
#include "region.h"
#include "monde.h"

t_joueur joueur;
extern char charger[16];


/**
 *\struct t_statcombat
 *\brief structure contenant toutes les statistiques liées au combat
 */
typedef struct{int victoire,defaite,total; float pourvic,pourdef;}t_statcombat;		

/**
 *\struct afficher_joueur(void)
 *\brief fonction permettant d'afficher les caractéristiques du joueur
 */
void afficher_joueur(){
	printf("\nVoici vos niveaux de compétences principales actuels : \n");
	printf("	Rapidité : %i \n", joueur.comp.rapidite);
	printf("	Agilité : %i \n", joueur.comp.agilite);
	printf("	Force : %i \n", joueur.comp.force);
	printf("	Puissance : %i \n", joueur.comp.puissance);
	printf("	Intelligence : %i \n", joueur.comp.intelligence);
	printf("	Perception : %i \n", joueur.comp.perception);				printf("	Chance : %i \n", joueur.comp.chance);
			
	printf("Compétences de combat : \n");
	printf("	Archerie : %i \n", joueur.combat.archerie);
	printf("	Précision : %i \n", joueur.combat.precision);
	printf("	Une main : %i \n", joueur.combat.unemain);
	printf("	Deux mains : %i \n", joueur.combat.deuxmains);
	printf("	Lance : %i \n", joueur.combat.lance);
	printf("	Contondant : %i \n", joueur.combat.contondant);
	printf("	Parade : %i \n", joueur.combat.parade);
	printf("	Armure légère : %i \n", joueur.combat.armureleg);
	printf("	Armure lourde : %i \n", joueur.combat.armurelou);
	printf("\nCompétences de furtivité : \n");
	printf("    Crochetage : %i \n", joueur.furtif.crochetage);
	printf("	Discretion : %i \n", joueur.furtif.discretion);
	printf("	Dague : %i \n", joueur.furtif.dague);
	printf("	Acrobatie : %i \n", joueur.furtif.acrobatie);
	printf("\nCompétences de dialogue : \n");
	printf("	Charisme : %i \n", joueur.dial.charisme);
	printf("	Persuasion : %i \n", joueur.dial.persuasion);
	printf("	Marchandage : %i \n", joueur.dial.marchandage);
	printf("\nCompétences de magie : \n");
	printf("	Destruction : %i \n", joueur.magie.destruction);
	printf("	Guérison : %i \n", joueur.magie.guerison);
	printf("	Invocation : %i \n", joueur.magie.invocation);
			
	printf("Pseudo : %s \n", joueur.pseudo);
	if(joueur.physique.race==1){
		printf("Race : elfe \n");
	}
	else if(joueur.physique.race==2){
		printf("Race : humain \n");
	}
	else if(joueur.physique.race==3){
		printf("Race : nain \n");
	}
	else if(joueur.physique.race==4){
		printf("Race : orc \n");
	}
	else{
		printf("Race : troll \n");
	}
       
	int m=joueur.physique.taille/100;
	int c=joueur.physique.taille%100;
        
	if(c==0){
		printf("Taille : %i m \n", m);
	}
	else{
		printf("Taille : %i m %i \n", m,c);
	}
        
	if(joueur.physique.poids==1){
		printf("Corpulence : anorexique \n");
	}
	else if(joueur.physique.poids==2){
		printf("Corpulence : mince \n");
	}
	else if(joueur.physique.poids==3){
		printf("Corpulence : moyenne \n");
	}
	else if(joueur.physique.poids==4){
		printf("Corpulence : surpoids \n");
	}
	else if(joueur.physique.poids==5){
		printf("Corpulence : obèse \n");
	}
	else{
		printf("Corpulence : obèsité morbide \n");
	}	
}


int main(){
	int choix;
	int i=0;
	int k=0;
	
    principale=5;
    secondaire=5;
    
    init_monde();
    
    printf("Bienvenue : \n");
    printf("1 : Nouvelle partie \n");
    printf("2 : Charger partie \n");
    printf("3 : Afficher monde \n");
    printf("Votre choix : ");
    scanf("%i",&choix);
    
    switch(choix){
		case 1 : crea_ava(&joueur,principale,secondaire); crea_file(); creer_region(); break;
		case 2 : 
			i=charger_partie(charger);
			if(i==1){
				afficher_joueur();
			}
			else{
				break;
			}
			while(k!=1){
				creer_region();
				printf("Souhaitez générer une autre map ? 0 si oui, 1 si non : ");
				scanf("%i",&k);
			}
			break;
		case 3 : aff_monde(0,0); break;
		}
 
	return EXIT_SUCCESS;
}
