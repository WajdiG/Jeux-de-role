/**
*\file sauvegarde.c
*\brief fonction permttant de sauvegarder les paramètres du jeu, les caractéristique du joueur et l'avancement dans le jeu
*\author Wajdi Guedouar
*\version 0.1
*\date 7 Novembre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crea_avatar.h"
#include "monde.h"
#include "region.h"

/**
 *\fn crea_file(void) 
 *\brief fonction permettant de sauvegarder la structure t_joueur, la matrice monde et les coordonnées du joueur dans cette matrice dans le fichier de sauvegarde
 */
void crea_file(t_joueur joueur, t_coord coord, char pseudo[P], char ** monde[X][Y]){
	int i,j,k,l;
	
	FILE*fichier=fopen(pseudo,"w");
	
	fprintf(fichier,"%i ",joueur.physique.sexe);
	fprintf(fichier,"%i ",joueur.physique.race);
	fprintf(fichier,"%i ",joueur.physique.poids);
	fprintf(fichier,"%i ",joueur.physique.taille);
	
	fprintf(fichier,"%i ",joueur.vie.sante);
	fprintf(fichier,"%i ",joueur.vie.mana);
	fprintf(fichier,"%i ",joueur.vie.endu);
	
	fprintf(fichier,"%i ",joueur.comp.rapidite);
	fprintf(fichier,"%i ",joueur.comp.agilite);
	fprintf(fichier,"%i ",joueur.comp.force);
	fprintf(fichier,"%i ",joueur.comp.puissance);
	fprintf(fichier,"%i ",joueur.comp.intelligence);
	fprintf(fichier,"%i ",joueur.comp.perception);
	fprintf(fichier,"%i ",joueur.comp.chance);
	
	fprintf(fichier,"%i ",joueur.combat.archerie);
	fprintf(fichier,"%i ",joueur.combat.precision);
	fprintf(fichier,"%i ",joueur.combat.unemain);
	fprintf(fichier,"%i ",joueur.combat.deuxmains);
	fprintf(fichier,"%i ",joueur.combat.lance);
	fprintf(fichier,"%i ",joueur.combat.contondant);
	fprintf(fichier,"%i ",joueur.combat.parade);
	fprintf(fichier,"%i ",joueur.combat.armureleg);
	fprintf(fichier,"%i ",joueur.combat.armurelou);
	fprintf(fichier,"%i ",joueur.combat.corpscorps);
	
	fprintf(fichier,"%i ",joueur.furtif.discretion);
	fprintf(fichier,"%i ",joueur.furtif.crochetage);
	fprintf(fichier,"%i ",joueur.furtif.dague);
	fprintf(fichier,"%i ",joueur.furtif.acrobatie);
	
	fprintf(fichier,"%i ",joueur.dial.persuasion);
	fprintf(fichier,"%i ",joueur.dial.charisme);
	fprintf(fichier,"%i ",joueur.dial.marchandage);
	
	fprintf(fichier,"%i ",joueur.magie.destruction);
	fprintf(fichier,"%i ",joueur.magie.guerison);
	fprintf(fichier,"%i ",joueur.magie.invocation);
	
	fprintf(fichier,"%i ",coord.x);
	fprintf(fichier,"%i ",coord.y);
	
	fprintf(fichier,"\n");	
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			for(k=0;k<N;k++){
				for(l=0;l<N;l++){
					fprintf(fichier,"%c",monde[i][j][k][l]);
				}
			}
			fprintf(fichier,"\n");		
		}
	}
	
	
	
	fclose(fichier);
}


