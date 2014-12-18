
/**
*\file JR1_0.c
*\brief regroupe toutes les fonctions nécessaire à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "IA.h"
#include "region.h"
#include "JDR1_0.h"
#include "accueil.h"


extern char ** monde[X][Y];
extern t_coord coord;
extern  char region[N][N];
t_joueur joueur;
t_statcombat statcombat;


/**
*\struct afficher_joueur(void)
*\brief fonction permettant d'afficher les caractéristiques du joueur
*/
void afficher_joueur(){
	
	printf("\n	Voici vos niveaux de compétences principales actuels : \n");
	printf("		Rapidité : %i \n", joueur.comp.rapidite);
	printf("		Agilité : %i \n", joueur.comp.agilite);
	printf("		Force : %i \n", joueur.comp.force);
	printf("		Puissance : %i \n", joueur.comp.puissance);
	printf("		Intelligence : %i \n", joueur.comp.intelligence);
	printf("		Perception : %i \n", joueur.comp.perception);
	printf("		Chance : %i \n", joueur.comp.chance);
	printf("	Compétences de combat : \n");
	printf("		Archerie : %i \n", joueur.combat.archerie);
	printf("		Précision : %i \n", joueur.combat.precision);
	printf("		Une main : %i \n", joueur.combat.unemain);
	printf("		Deux mains : %i \n", joueur.combat.deuxmains);
	printf("		Lance : %i \n", joueur.combat.lance);
	printf("		Contondant : %i \n", joueur.combat.contondant);
	printf("		Parade : %i \n", joueur.combat.parade);
	printf("		Armure légère : %i \n", joueur.combat.armureleg);
	printf("		Armure lourde : %i \n", joueur.combat.armurelou);
	printf("\n	Compétences de furtivité : \n");
	printf(" 		Crochetage : %i \n", joueur.furtif.crochetage);
	printf("		Discretion : %i \n", joueur.furtif.discretion);
	printf("		Dague : %i \n", joueur.furtif.dague);
	printf("		Acrobatie : %i \n", joueur.furtif.acrobatie);
	printf("\n	Compétences de dialogue : \n");
	printf("		Charisme : %i \n", joueur.dial.charisme);
	printf("		Persuasion : %i \n", joueur.dial.persuasion);
	printf("		Marchandage : %i \n", joueur.dial.marchandage);
	printf("\n	Compétences de magie : \n");
	printf("		Destruction : %i \n", joueur.magie.destruction);
	printf("		Guérison : %i \n", joueur.magie.guerison);
	printf("		Invocation : %i \n", joueur.magie.invocation);
			
	printf("	Pseudo : %s \n", joueur.pseudo);
	
	if(joueur.physique.race==1){
		printf("	Race : elfe \n");
	}
	else if(joueur.physique.race==2){
		printf("	Race : humain \n");
	}
	else if(joueur.physique.race==3){
		printf("	Race : nain \n");
	}
	else if(joueur.physique.race==4){
		printf("	Race : orc \n");
	}
	else{
		printf("	Race : troll \n");
	}
	
	int m=joueur.physique.taille/100;
	int c=joueur.physique.taille%100;
	
	if(c==0){
		printf("	Taille : %i m \n", m);
	}
	else{
		printf("	Taille : %i m %i \n", m,c);
	}
	
	if(joueur.physique.poids==1){
		printf("	Corpulence : anorexique \n");
	}
	else if(joueur.physique.poids==2){
		printf("	Corpulence : mince \n");
	}
	else if(joueur.physique.poids==3){
		printf("	Corpulence : moyenne \n");
	}
	else if(joueur.physique.poids==4){
		printf("	Corpulence : surpoids \n");
	}
	else if(joueur.physique.poids==5){
		printf("	Corpulence : obèse \n");
	}
	else{
		printf("	Corpulence : obèsité morbide \n");
	}
}

void nouvelle_partie(int matrice[N][N]){
	int choix=0;
	int principale=1;
    int secondaire=1;
	
	crea_ava(&joueur,principale,secondaire);
	printf("1\n");
	creer_region();
	printf("2\n");
	tradRandom(matrice, region);
	printf("3\n");
	inclure_region(coord);
	printf("4\n");
	crea_file();
	printf("5\n");
	while(choix!=4&&choix!=3){
		
		printf("\n	Entrez le nombre entier correspondant à votre choix : \n");
		printf("		0- Afficher la region dans laquelle vous vous trouvez \n");
		printf("		1- Continuer \n");
		printf("		2- Sauvegarder \n");
		printf("		3- Sauvegarder et quitter \n");
		printf("		4- Quittez sans sauvegarder \n");
		printf("		Votre choix : ");
		scanf(" %i",&choix);
	
		switch(choix){
			case 0 : aff_region_monde(); break;
			case 1 : continuer(matrice); deplacement_monde(); creer_region(); tradRandom(matrice, region); inclure_region(coord);break;
			case 2 : crea_file(); break;
			case 3 : crea_file(); break;
			case 4 : break;
			default : printf("	Veuillez saisir une valeur entière comprise entre 0 et 4. \n");
		}	
	}
}

void charger_par(int matrice[N][N]){
	char charger[16];
	int i=charger_partie(charger,&joueur,&coord,monde);
	int choix=0;
	
	if(i==1){
		while(choix!=4){
			printf("\n	Entrez le nombre entier correspondant à votre choix : \n");
			printf(" 		0- afficher la region dans laquelle vous vous trouvez \n");
			printf(" 		1- Afficher les caractéristiques de l'avatar \n ");
			printf("		2- Vous déplacer dans le monde \n ");
			printf("		3- Afficher la position courante dans le monde \n ");
			printf("		4- Sauvegarder et retour à l'accueil \n ");
			printf("		Votre choix :");
			scanf("  %i",&choix);
			
			switch(choix){
				case 0 : aff_region_monde(); break;
				case 1 : afficher_joueur();break;
				case 2 : deplacement_monde(); creer_region(); tradRandom(matrice, region); inclure_region(coord); break;
				case 3 : aff_monde(); break;
				case 4 : crea_file(); break;
				default : printf("	Veuillez saisir une valeur entière comprise entre 0 et 4. \n");
			}
		}
	}
	else{
		printf("\n 	Ce fichier n'existe pas, si vous n'avez pas créer de partie, retournez à l'accueil du jeu. Sinon, réessayez. \n");
	}
}

/*
int main(){
	int choix=0;
	
	srand(time(NULL));
	
	init_monde();
	
	while(choix!=4){
		printf("Bienvenue : \n");
		printf("1 : Nouvelle partie \n");
		printf("2 : Charger partie \n");
		printf("3 : Afficher monde \n");
		printf("4 : Quittez le jeu \n");
		printf("Votre choix : ");
		scanf("%i",&choix);
	
		switch(choix){
			case 1 : nouvelle_partie(); break;
			case 2 : charger_par(); break;
			case 3 : aff_monde();break;
			case 4 : break;
			default : printf("Veuillez saisir une valeur entière comprise entre 1 et 4. \n");
		}
	}
	
	return EXIT_SUCCESS;
}
*/
