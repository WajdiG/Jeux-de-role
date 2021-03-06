/**
*\file region.c
*\brief regroupe toutes les fonctions nécessaires à la création d'une région : génération aléatoire d'un labyrinthe
*\author Wajdi Guedouar
*\version 0.1
*\date 25 Novembre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<ncurses.h>
#include "pile_tab.h"
#include "region.h"

char region[N][N]; /**< matrice de matrice représentant le monde, chaque case du monde contient une matrice region */


/**
 *\fn initregion(void)
 *\brief initialise la region où toutes les cases valent X, ainsi que le tableau tab où tout vaut 1
 */
void initregion(){
	int i,j;
	
	for(i=0;i<N;i++){	//initialise la matrice monde
		for(j=0;j<N;j++){
			region[i][j]='X';
		}
	}
	
	for(i=0;i<(NB_COFFRE+4);i++){	//initialise le tableau tab
		tab[i]=1;
	}
}


/**
 *\fn aff_region(void)
 *\brief affiche la region à l'écran
 */
void aff_region(){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printw("%c",region[i][j]);
		}
		printw("\n");
	}
}

/**
 *\fn verif_coffre(int , int)
 *\brief recherche la présence d'un coffre 'C' ou d'un joueur 'P' dans la matrice region autour des coordonnées i j passées en paramètre
 *\param i entier représentant l'absisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre) ou P (un joueur) et 1 si non
 */
int verif_coffre(int i, int j){
	if(region[i+1][j]=='C'||region[i+1][j]=='P'){
		return 0;
	}
	else if(region[i-1][j]=='C'||region[i-1][j]=='P'){
		return 0;
	}
	else if(region[i+1][j+1]=='C'||region[i+1][j+1]=='P'){
		return 0;
	}
	else if(region[i-1][j+1]=='C'||region[i-1][j+1]=='P'){
		return 0;
	}
	else if(region[i+1][j-1]=='C'||region[i+1][j-1]=='P'){
		return 0;
	}
	else if(region[i-1][j-1]=='C'||region[i-1][j-1]=='P'){
		return 0;
	}
	else if(region[i][j+1]=='C'||region[i][j+1]=='P'){
		return 0;
	}
	else if(region[i][j-1]=='C'||region[i][j-1]=='P'){
		return 0;
	}
	
	return 1;
}

/**
 *\fn verif_cour(int , int)
 *\brief verifie que la case dans laquelle on se trouve soit différente de C (un coffre) ou P (le joueur) 
 *\param i entier représentant l'abscisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre), M (un monstre) ou P (le joueur) et 1 si non
 */
int verif_cour(int i, int j){
	if(region[i][j]=='C'||region[i][j]=='P'||region[i][j]=='M'){
		return 0;
	}
	return 1;
}

/**
 *\fn place_coffre
 *\brief permet de placer des coffres C aléatoirement dans la matrice
 */
void place_coffre(){
	int i,j;
	int k=0;
	srand(time(NULL));
	
	for(k=0;k<NB_COFFRE;k++){	//genere un nombre de coffre égale à NB_COFFRE
		do{
			i=rand()%(N-2)+1;
			j=rand()%(N-2)+1;
		}while(!verif_coffre(i,j)||j==0||i==0);
		region[i][j]='C';
		//sauvegarde les coordonées du coffre dans le tableau tab
		tab[2*k]=i;
		tab[2*k+1]=j;
	}
	
}

/**
 *\fn place_joueur(void)
 *\brief permet de placer le joueur aleatoirement sur la map
 */
void place_joueur(){
	int i,j;
	
	do{
		i=rand()%(N-2)+1;
		j=rand()%(N-2)+1;
	}while(!verif_coffre(i,j)||j==0||i==0);
		region[i][j]='P';	
		//sauvegarde les coordonées du joueur dans le tableau tab
		tab[(2*NB_COFFRE)]=i;
		tab[(2*NB_COFFRE)+1]=j;
}

/**
 *\fn place_monstre(void)
 *\brief permet de placer le monstre aleatoirement sur la map
 */
void place_monstre(){
	int i,j;
	
	do{
		i=rand()%(N-2)+1;
		j=rand()%(N-2)+1;
	}while(!verif_coffre(i,j)||j==0||i==0);
		region[i][j]='M';
		//sauvegarde les coordonées du monstre dans le tableau tab
		tab[(2*NB_COFFRE)+2]=i;
		tab[(2*NB_COFFRE)+3]=j;
}

 /**
 *\fn chemin(void)
 *\brief permet de générer un chemin depuis P (le joueur) vers les bord de la matrice, depuis C (un coffre) vers un chemin existant
 */
void chemin(){
	 
	int i,j,k,l,b; 
	 
	for(k=-1; k<=1; k++){	
		for(l=-1; l<=1; l++){//crée des couloirs a partir du personnage et du monstre vers les extremités du laby
			if((k==0||l==0) && k!=l){
				i=tab[2*NB_COFFRE];
				j=tab[(2*NB_COFFRE)+1];
				 
				while(i>0&&j>0&&i<N-1&&j<N-1){
					if(verif_cour(i,j)){
						region[i][j]=' ';
					}
					i+=k;
					j+=l;
				}
			}
			if((k==0||l==0) && k!=l){
				i=tab[(2*NB_COFFRE)+2];
				j=tab[(2*NB_COFFRE)+3];
				 
				while(i>0&&j>0&&i<N-1&&j<N-1){
					if(verif_cour(i,j)){
						region[i][j]=' ';
					}
					i+=k;
					j+=l;
				}
			}
		}
	}
	 
	 
	for(b=0;b<NB_COFFRE;b++){	//créer des couloirs depuis les coffres jusqu'à un couloir existant ou la bordure de la matrice
		i=tab[2*b];
		j=tab[2*b+1];
		
		for(i=tab[2*b]-1;verif_cour(i,j)&&region[i][j]!=' '&&i>0;i--){
			empiler(i);		
		}
		while(!pilevide()){
			depiler(&i);
			region[i][j]=' ';
		}
		
		
		for(i=tab[2*b]+1;verif_cour(i,j)&&region[i][j]!=' '&&i<N-1;i++){
			empiler(i);		
		}
		while(!pilevide()){
			depiler(&i);
			region[i][j]=' ';
		}
		
		i=tab[2*b];
	
		for(j=tab[2*b+1]-1;verif_cour(i,j)&&region[i][j]!=' '&&j>0;j--){
			empiler(j);		
		}
		while(!pilevide()){
			depiler(&j);
			region[i][j]=' ';
		}
		
		
		for(j=tab[2*b+1]+1;verif_cour(i,j)&&region[i][j]!=' '&&j<N-1;j++){
			empiler(j);		
		}
		while(!pilevide()){
			depiler(&j);
			region[i][j]=' ';
		}
		
	}
 }
 
 /**
 *\fn carre(void)
 *\brief créer un espace autour des coffres et du joueur
 */
void carre(){
	
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(!verif_cour(i,j)&&i!=0&&j!=0){
				if(i+1!=(N-1)){
					region[i+1][j]=' ';
					if(j+1!=(N-1)){
						region[i+1][j+1]=' ';
					}
					if(j-1!=0){
						region[i+1][j-1]=' ';
					}
				}
				if(i-1!=0){
					region[i-1][j]=' ';
					if(j+1!=(N-1)){
						region[i-1][j+1]=' ';
					}
					if(j-1!=0){
						region[i-1][j-1]=' ';
					}
				}
				if(j+1!=(N-1)){
					region[i][j+1]=' ';
				}
				if(j-1!=0){
					region[i][j-1]=' ';
				}
			}
		}
	}
}

 /**
 *\fn creer_region(void)
 *\brief creer une region : labyrinthe aléatoire
 */
void creer_region(){
		
	initregion();
	initpile();
	place_coffre();
	place_joueur();
	place_monstre();
	chemin();
	carre();
}
