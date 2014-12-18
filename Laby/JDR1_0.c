
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
#include<ncurses.h>
#include"IA.h"
#include"region.h"
#include"JDR1_0.h"
#include "accueil.h"


extern char ** monde[X][Y];
extern t_coord coord;
extern  char region[N][N];
t_joueur joueur;


/**
*\struct afficher_joueur(void)
*\brief fonction permettant d'afficher les caractéristiques du joueur
*/
void afficher_joueur(){
	
	printw("\nVoici vos niveaux de compétences principales actuels : \n");
	printw("	Rapidité : %i \n", joueur.comp.rapidite);
	printw("	Agilité : %i \n", joueur.comp.agilite);
	printw("	Force : %i \n", joueur.comp.force);
	printw("	Puissance : %i \n", joueur.comp.puissance);
	printw("	Intelligence : %i \n", joueur.comp.intelligence);
	printw("	Perception : %i \n", joueur.comp.perception);
	printw("	Chance : %i \n", joueur.comp.chance);
	printw("Compétences de combat : \n");
	printw("	Archerie : %i \n", joueur.combat.archerie);
	printw("	Précision : %i \n", joueur.combat.precision);
	printw("	Une main : %i \n", joueur.combat.unemain);
	printw("	Deux mains : %i \n", joueur.combat.deuxmains);
	printw("	Lance : %i \n", joueur.combat.lance);
	printw("	Contondant : %i \n", joueur.combat.contondant);
	printw("	Parade : %i \n", joueur.combat.parade);
	printw("	Armure légère : %i \n", joueur.combat.armureleg);
	printw("	Armure lourde : %i \n", joueur.combat.armurelou);
	printw("\nCompétences de furtivité : \n");
	printw(" 	Crochetage : %i \n", joueur.furtif.crochetage);
	printw("	Discretion : %i \n", joueur.furtif.discretion);
	printw("	Dague : %i \n", joueur.furtif.dague);
	printw("	Acrobatie : %i \n", joueur.furtif.acrobatie);
	printw("\nCompétences de dialogue : \n");
	printw("	Charisme : %i \n", joueur.dial.charisme);
	printw("	Persuasion : %i \n", joueur.dial.persuasion);
	printw("	Marchandage : %i \n", joueur.dial.marchandage);
	printw("\nCompétences de magie : \n");
	printw("	Destruction : %i \n", joueur.magie.destruction);
	printw("	Guérison : %i \n", joueur.magie.guerison);
	printw("	Invocation : %i \n", joueur.magie.invocation);
			
	printw("Pseudo : %s \n", joueur.pseudo);
	
	if(joueur.physique.race==1){
		printw("Race : elfe \n");
	}
	else if(joueur.physique.race==2){
		printw("Race : humain \n");
	}
	else if(joueur.physique.race==3){
		printw("Race : nain \n");
	}
	else if(joueur.physique.race==4){
		printw("Race : orc \n");
	}
	else{
		printw("Race : troll \n");
	}
	
	int m=joueur.physique.taille/100;
	int c=joueur.physique.taille%100;
	
	if(c==0){
		printw("Taille : %i m \n", m);
	}
	else{
		printw("Taille : %i m %i \n", m,c);
	}
	
	if(joueur.physique.poids==1){
		printw("Corpulence : anorexique \n");
	}
	else if(joueur.physique.poids==2){
		printw("Corpulence : mince \n");
	}
	else if(joueur.physique.poids==3){
		printw("Corpulence : moyenne \n");
	}
	else if(joueur.physique.poids==4){
		printw("Corpulence : surpoids \n");
	}
	else if(joueur.physique.poids==5){
		printw("Corpulence : obèse \n");
	}
	else{
		printw("Corpulence : obèsité morbide \n");
	}
}

void nouvelle_partie(int matrice[N][N]){
	int choix=0;
	int principale=1;
    int secondaire=1;
	
	crea_ava(&joueur,principale,secondaire);
	creer_region();
	tradRandom(matrice, region);
	inclure_region(coord);
	crea_file(joueur, coord, joueur.pseudo, monde);
	
	while(choix!=4&&choix!=3){
		
		printw("\n Entrez le nombre entier correspondant à votre choix : \n");
		printw("0- Afficher la region dans laquelle vous vous trouvez \n");
		printw("1- Continuer \n");
		printw("2- Sauvegarder \n");
		printw("3- Sauvegarder et quitter \n");
		printw("4- Quittez sans sauvegarder \n");
		printw("Votre choix :");
		scanw("%i", &choix);
	
		switch(choix){
			case 0 : clear(); aff_region_monde(); break;
			case 1 : continuer(matrice); deplacement_monde(); creer_region(); tradRandom(matrice, region); inclure_region(coord);break;
			case 2 : crea_file(joueur, coord, joueur.pseudo, monde); break;
			case 3 : crea_file(joueur, coord, joueur.pseudo, monde); break;
			case 4 : break;
			default : printw("Veuillez saisir une valeur entière comprise entre 0 et 4. \n");
		}	
	}
}

void charger_par(int matrice[N][N]){
	char charger[16];
	int i=charger_partie(charger,&joueur,&coord,monde);
	int choix=0;
	
	if(i==1){
		while(choix!=4){
			printw("\n Entrez le nombre entier correspondant à votre choix : \n");
			printw(" 0- afficher la region dans laquelle vous vous trouvez \n");
			printw(" 1- Afficher les caractéristiques de l'avatar \n ");
			printw("2- Vous déplacer dans le monde \n ");
			printw("3- Afficher la position courante dans le monde \n ");
			printw("4- Sauvegarder et retour à l'accueil \n ");
			printw("Votre choix :");
			scanw("%i", &choix);
			
			switch(choix){
				case 0 : clear(); aff_region_monde(); break;
				case 1 : clear(); afficher_joueur();break;
				case 2 : continuer(matrice); deplacement_monde(); creer_region(); tradRandom(matrice, region); inclure_region(coord); break;
				case 3 : clear(); aff_monde(); break;
				case 4 : crea_file(joueur, coord, joueur.pseudo, monde); break;
				default : printw("Veuillez saisir une valeur entière comprise entre 0 et 4. \n");
			}
		}
	}
	else{
		printw("\n Ce fichier n'existe pas, si vous n'avez pas créer de partie, retournez à l'accueil du jeu. Sinon, réessayez. \n");
	}
}
