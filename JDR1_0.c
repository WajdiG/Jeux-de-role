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
#include "crea_avatar.h"
#include "sauvegarde.h"
#define N 16

t_joueur joueur;

/**
 *\fn crea_file 
 *\brief fonction permettant de sauvegarder la structure t_joueur dans le fichier de sauvegarde
 *\param fichier 
 */
void crea_file(FILE*fichier){
	
	fprintf(fichier,"%i",joueur.physique.sexe);
	fprintf(fichier,"%i",joueur.physique.race);
	fprintf(fichier,"%i",joueur.physique.poids);
	fprintf(fichier,"%i",joueur.physique.taille);
	
	fprintf(fichier,"%i",joueur.vie.sante);
	fprintf(fichier,"%i",joueur.vie.mana);
	fprintf(fichier,"%i",joueur.vie.endu);
	
	fprintf(fichier,"%i",joueur.comp.rapidite);
	fprintf(fichier,"%i",joueur.comp.agilite);
	fprintf(fichier,"%i",joueur.comp.force);
	fprintf(fichier,"%i",joueur.comp.puissance);
	fprintf(fichier,"%i",joueur.comp.intelligence);
	fprintf(fichier,"%i",joueur.comp.perception);
	fprintf(fichier,"%i",joueur.comp.chance);
	
	fprintf(fichier,"%i",joueur.combat.archerie);
	fprintf(fichier,"%i",joueur.combat.precision);
	fprintf(fichier,"%i",joueur.combat.unemain);
	fprintf(fichier,"%i",joueur.combat.deuxmains);
	fprintf(fichier,"%i",joueur.combat.lance);
	fprintf(fichier,"%i",joueur.combat.contondant);
	fprintf(fichier,"%i",joueur.combat.parade);
	fprintf(fichier,"%i",joueur.combat.armureleg);
	fprintf(fichier,"%i",joueur.combat.armurelou);
	//fprintf(fichier,"%i",joueur.combat.corpscorps);
	
	fprintf(fichier,"%i",joueur.furtif.discretion);
	fprintf(fichier,"%i",joueur.furtif.crochetage);
	fprintf(fichier,"%i",joueur.furtif.dague);
	fprintf(fichier,"%i",joueur.furtif.acrobatie);
	
	fprintf(fichier,"%i",joueur.dial.persuasion);
	fprintf(fichier,"%i",joueur.dial.charisme);
	fprintf(fichier,"%i",joueur.dial.marchandage);
	
	fprintf(fichier,"%i",joueur.magie.destruction);
	fprintf(fichier,"%i",joueur.magie.guerison);
	fprintf(fichier,"%i",joueur.magie.invocation);
	
	fclose(fichier);
}


/**
 *\struct t_statcombat
 *\brief structure contenant toutes les statistiques liées au combat
 */
typedef struct{int victoire,defaite,total; float pourvic,pourdef;}t_statcombat;		

int main(){
	FILE*fichier;
	fichier=fopen(pseudo,"w");
	
    principale=5;
    secondaire=10;

	crea_ava(&joueur,principale,secondaire);
	crea_file(fichier);
	
	return EXIT_SUCCESS;
}
