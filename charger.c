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

#include "charger.h"


/**
*\fn charger_struct(t_joueur *,t_coord *,FILE *)
*\brief fonction permettant de charger toutes les données contenue dans le fichier de sauvegarde dans la structure t_joueur jouer
*\param *joueur pointeur sur la structure t_joueur joueur
*\param fichier fichier contenant les données sauvegardéess
*/
void charger_jeu(t_joueur *joueur,t_coord *coord,char ** monde[X][Y],FILE*fichier){
	int i=0;
	char a;
	int h,j,k,l;
	
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
	
	fscanf(fichier,"%i",&i);
	(*coord).x=i;
	fscanf(fichier,"%i",&i);
	(*coord).y=i;
	
	for(h=0;h<X;h++){
		for(j=0;j<Y;j++){
			for(k=0;k<N;k++){
				for(l=0;l<M;l++){
					fscanf(fichier,"%c ",&a);
					monde[h][j][k][l]=a;
				}
			}	
		}
	}
}


/**
*\fn void charger_partie(char)
*\brief fonction permettant de charger une partie
*\param charger tableau contenant le pseudo du joueur
*\return int renvoie 1 si le fichier charger est valide, 0 si non
*/
int charger_partie(char* charger,t_joueur* joueur,t_coord *coord, char ** monde[X][Y]){
	FILE*fichier;
	
	printf("Quel est votre pseudo dans la partie que vous souhaitez charger ? : ");
	scanf("%s",charger);
	
	fichier=fopen(charger,"r");
	
	if(fichier!=NULL){
		charger_jeu(joueur, coord, monde, fichier);
		strcpy(joueur->pseudo,charger);
		return 1;
	}
	printf("Aucun ficher de sauvegarder existant pour ce pseudo. Vous pouvez commencer une nouvelle partie ou réessayer. \n");
	return 0;
}
