/**
*\file charger.c
*\brief fonction permttant de charger les paramètres du jeu, les caractéristique du joueur et l'avancement dans le jeu
*\author Wajdi Guedouar
*\version 0.1
*\date 19 Novembre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crea_avatar.h"
extern t_joueur joueur;

char charger[16];


/**
 *\fn charger_struct(t_joueur *)
 *\brief fonction permettant de charger toutes les données contenue dans le fichier de sauvegarde dans la structure t_joueur jouer
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void charger_struct(t_joueur *joueur,FILE*fichier){
	int i=0;
	
	if(fichier == NULL){
			fprintf(stderr, "fichier non ouvert \n");
			return;
	}
	
	fscanf(fichier,"%i",&i);
	if(i==1){
		(*joueur).physique.sexe=homme; // equivalent joueur-> sexe = homme
	}
	else if(i==2){
		(*joueur).physique.sexe=femme;
	}
	else{
		(*joueur).physique.sexe=sans;
	}
	
	fscanf(fichier,"%i",&i);
	if(i==1){
		(*joueur).physique.race=elfe;
	}
	else if(i==2){
		(*joueur).physique.race=humain;
	}
	else if(i==3){
		(*joueur).physique.race=nain;
	}
	else if(i==4){
		(*joueur).physique.race=orc;
	}
	else{
		(*joueur).physique.race=troll;
	}
	
	fscanf(fichier,"%i",&i);
	if(i==1){
		(*joueur).physique.poids=anorexique;
	}
	else if(i==2){
		(*joueur).physique.poids=mince;
	}
	else if(i==3){
		(*joueur).physique.poids=moyen;
	}
	else if(i==4){
		(*joueur).physique.poids=surpoids;
	}
	else if(i==5){
		(*joueur).physique.poids=obese;
	}
	else{
		(*joueur).physique.poids=obesemo;
	}
	
	fscanf(fichier,"%i",&i);
	(*joueur).physique.taille=i;	
	
	fscanf(fichier,"%i",&i);
	(*joueur).vie.sante=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).vie.mana=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).vie.endu=i;
	
	fscanf(fichier,"%i",&i);
	(*joueur).comp.rapidite=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).comp.agilite=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).comp.force=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).comp.puissance=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).comp.intelligence=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).comp.perception=i;
	fscanf(fichier,"%i",&i);
	(*joueur).comp.chance=i;
	
	fscanf(fichier,"%i",&i);
	(*joueur).combat.archerie=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).combat.precision=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).combat.unemain=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).combat.deuxmains=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).combat.lance=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).combat.contondant=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).combat.parade=i;
	fscanf(fichier,"%i",&i);
	(*joueur).combat.armureleg=i;
	fscanf(fichier,"%i",&i);
	(*joueur).combat.armurelou=i;
	fscanf(fichier,"%i",&i);
	(*joueur).combat.corpscorps=i;
		
	fscanf(fichier,"%i",&i);
	(*joueur).furtif.discretion=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).furtif.crochetage=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).furtif.dague=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).furtif.acrobatie=i;	
	
	fscanf(fichier,"%i",&i);
	(*joueur).dial.persuasion=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).dial.charisme=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).dial.marchandage=i;
	
	fscanf(fichier,"%i",&i);
	(*joueur).magie.destruction=i;	
	fscanf(fichier,"%i",&i);
	(*joueur).magie.guerison=i;
	fscanf(fichier,"%i",&i);	
	(*joueur).magie.invocation=i;
}

/**
 *\fn void charger_partie(char)
 *\brief fonction permettant de charger une partie
 *\param charger tableau contenant le pseudo du joueur
 */
void charger_partie(char* charger,FILE*fichier){
	
	printf("Quel est votre pseudo dans la partie que vous souhaitez charger ? : ");
	scanf("%s",charger); 
	
	fichier=fopen(charger,"r");
	
	if(fichier!=NULL){
		charger_struct(&joueur,fichier);
	}
	/*while(i!=1){
		printf("Votre fichier n'existe pas ! Souhaitez-vous réessayer ? 0 si oui, 1 si non :");
		scanf("%i",&i);
		if(i==0){
			fichier=fopen(charger,"r");
			if(fichier!=NULL){
				charger_struct(&joueur,fichier);
			}
		}
		else{
			i=1;
		}
	}*/
	
	printf("Aucun ficher de sauvegarder existant pour ce pseudo. Vous pouvez commencer une nouvelle partie. \n");
}
