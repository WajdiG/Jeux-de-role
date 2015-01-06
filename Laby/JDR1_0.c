
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
#include<ncurses.h>
#include "accueil.h"


extern char ** monde[X][Y]; /**< matrice de matrice représentant le monde, chaque case du monde contient une matrice region */
extern t_coord coord; /**< variable de type t_coord contenant les coordonnées du joueur dans la matrice monde */
extern  char region[N][N]; /**< matrice de type caractère contenant une region du monde */
t_joueur joueur; /**< variable de type t_joueur contenant toutes les données de l'avatar du joueur */
t_statcombat statcombat;/**< variable de type t_statcombat contenant toutes les données liées aux statistiques de combats du joueur */


/**
*\fn afficher_joueur(void)
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
	
	//affiche la taille en fonction de la présence ou non de centimètre
	if(c==0){
		printw("Taille : %i m \n", m);
	}
	else{
		printw("Taille : %i m %i \n",m,c);
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

/**
 *\fn nouvelle_partie(int **) 
 *\brief fonction permettant au joueur de démarrer une nouvelle partie
 *\param matrice prend en paramètre une matrice de taille NxN
 */
void nouvelle_partie(int matrice[N][N]){
	int choix=0;
	int principale=1;
    int secondaire=1;
	int quitter=0;
	
	//appelle des 5 fonctions necessaire à la création d'une nouvelle partie
	crea_ava(&joueur,principale,secondaire);
	creer_region();
	tradRandom(matrice, region);
	inclure_region(coord);
	crea_file(joueur, coord, joueur.pseudo, monde);
	
	//menu de jeu
	while(choix!=4&&choix!=3&&quitter!=1){
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
			case 1 : quitter=continuer(matrice); 
					if(quitter!=1){deplacement_monde(); creer_region(); tradRandom(matrice, region); inclure_region(coord);}break;
			case 2 : crea_file(joueur, coord, joueur.pseudo, monde); break;
			case 3 : crea_file(joueur, coord, joueur.pseudo, monde); break;
			case 4 : break;
			default : printw("Veuillez saisir une valeur entière comprise entre 0 et 4. \n");
		}	
	}
}

/**
 *\fn charger_par(int **) 
 *\brief fonction permettant au joueur de charger une partie et de la continuer
 *\param matrice prend en paramètre une matrice de taille NxN
 */
void charger_par(int matrice[N][N]){
	char charger[16];
	int choix=0;
	//met dans i la valeur de charger_partie : 1 si la partie existe et 0 si non.
	int i=charger_partie(charger,&joueur,&coord,monde);
	
	if(i==1){
		//menu permettant au joueur de poursuivre sa partie
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
		printw("\n Ce fichier n'existe pas, si vous n'avez pas créer de partie, retournez à l'accueil du jeu. Sinon, réessayez. \n");

	}
}*/
