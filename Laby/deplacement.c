/**
 *\file deplacement.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#define N 20
#define MUR 0
#define CHEMIN 1
#define COFFRE 2
#define JOUEUR 3
#define OBJECTIF 4
#define MOB 5

typedef struct {int x, y;}t_coordonees;

t_coordonees mes_choix[4];
t_coordonees ma_position = {17, 2};
t_coordonees mob_position = {2, 17};

void affichage(int matrice[N][N]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
                switch(matrice[i][j]){
                    case(MUR) : printf("|-|"); break;
                    case(CHEMIN) : printf("   "); break;
                    case(JOUEUR) : printf("*_*"); break;
                    case(COFFRE) : printf("[C]"); break;
                    case(OBJECTIF) : printf(" X "); break;
                    case(MOB) : printf(">_<"); break;
                }
		}
		printf("\n");
	}
}

void initialisation(int matrice[N][N]){

	int entier;
	int i, j;
	FILE * fichier;

    fichier = fopen("maptest.txt","r");

    while(!feof(fichier)){

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                fscanf(fichier,"%i", &entier);
                matrice[i][j] = entier;
            }
        }
    }
    fclose(fichier);
}

void coordonnees(int matrice[N][N]){
		
		char direction;
        t_coordonees tampon;
		printf("\n Ou souhaitez-vous vous deplacer ?\n\n");
		scanf("%c", &direction);		
		tampon.x = ma_position.x;
        tampon.y = ma_position.y;
		switch(direction){
			case 'z' : ma_position.x-- ; break;
			case 'q' : ma_position.y-- ; break;
			case 's' : ma_position.x++ ; break;
			case 'd' : ma_position.y++ ; break;
		}		
		if(matrice[ma_position.x][ma_position.y] == 0){
			ma_position.x = tampon.x;
			ma_position.y = tampon.y;
			printf("\n aïe ! \n");
		}
		else{
			matrice[tampon.x][tampon.y] = 1;
		}              
}

void IA(int matrice[N][N]){
		srand(time(NULL));
		char direction;
		t_coordonees tampon;
		char deplac_mob[5]={'x','z','q','s','d'};
		int dir=rand()%(4-0)+0;
		
		int cpt ;		
		for(cpt=0 ; cpt<5 ; cpt++){
			printf("%c", deplac_mob[cpt]);
		}
		printf("\n %i \n", dir);
        
		direction=deplac_mob[dir];
		tampon.x = mob_position.x;
        tampon.y = mob_position.y;
		switch(direction){
			case 'x' : break;
			case 'z' : mob_position.x-- ; break;
			case 'q' : mob_position.y-- ; break;
			case 's' : mob_position.x++ ; break;
			case 'd' : mob_position.y++ ; break;
		}	
		if(matrice[mob_position.x][mob_position.y] == 0){
			mob_position.x = tampon.x;
			mob_position.y = tampon.y;
			printf("\n BOOM ! \n");
		}
		else{
			matrice[tampon.x][tampon.y] = 1;
		}          
}


void placement_perso(int matrice[N][N], int *compteur){
	matrice[ma_position.x][ma_position.y] = JOUEUR;
	affichage(matrice);
	coordonnees(matrice);
	if(matrice[ma_position.x][ma_position.y] == COFFRE){
        *compteur = *compteur + 1;
	}
}

void placement_mob(int matrice[N][N]){
	matrice[mob_position.x][mob_position.y] = MOB;
	IA(matrice);

}

int nb_coffre_map(int matrice[N][N]){
    int i, j;
    int cpt = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(matrice[i][j] == COFFRE){
                cpt++;
            }
        }
    }
    return cpt;
}

int main(){
    int matrice[N][N];
    int compteur = 0;
    int nb_coffre;
	initialisation(matrice);
	printf("\n\n");
	nb_coffre = nb_coffre_map(matrice);
	printf("                 II            II IIIIII II     IIII    IIII  IIII  IIII IIIIII                             \n");
	printf("                  II    II    II  II     II    II   II II  II II IIII II II                                 \n");
	printf("                   II  IIII  II   IIII   II   II       II  II II  II  II IIII                               \n");
	printf("                    IIII  IIII    II     II    II   II II  II II      II II                                 \n");
	printf("                     II    II     IIIIII IIII   IIII    IIII  II      II IIIIII                             \n");
	printf("\n");
	printf("                                            IIIIII  IIII                                                    \n");
	printf("                                              II   II  II                                                   \n");
	printf("                                              II   II  II                                                   \n");
	printf("                                              II   II  II                                                   \n");
	printf("                                              II    IIII                                                    \n");
	printf("\n");
	printf("II   IIIIII  IIII   IIII   II  II IIIIII    IIII  IIIIII   IIII   IIII   IIII  II     II IIIIII III   II    \n");
	printf("II   II     II  II II  II  II  II II       II  II II       II II  II II II  II  II   II  II     IIIII II    \n");
	printf("II   IIII   IIIIII II      II  II IIII     II  II IIII     II  II IIII  IIIIII  II  II   IIII   II II II    \n");
	printf("II   II     II  II II  III II  II II       II  II II       II II  III   II  II   IIII    II     II  IIII    \n");
	printf("IIII IIIIII II  II  IIII I  IIII  IIIIII    IIII  II       IIII   II II II  II    II     IIIIII II   III    \n");
	printf("\n");
	printf("                                             IIIIIIII                                                       \n");
	printf("                                           III======III                                                     \n");
	printf("                                          II          II                                                    \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                         II            II                                                   \n");
	printf("                                          I            I                                                    \n");
	printf("\n");
	printf("                                  Press enter to start the game                                             \n");
	
	char verif = 'a';
	while(verif != '\n'){
		scanf("%c", &verif);
	}
	
    while(matrice[ma_position.x][ma_position.y] != OBJECTIF){
        while(compteur < nb_coffre){
			placement_mob(matrice);
            placement_perso(matrice, &compteur);
            
        }
        matrice[2][17] = OBJECTIF;
        placement_mob(matrice);
        placement_perso(matrice, &compteur);
        
        
    }
        printf("IIIIIII   IIIIII IIIIIII II     II IIIIIIII\n");
        printf("II    I   I    I II   II II     II II    II\n");
        printf("II     I  I   I  II   II II     II II    II\n");
        printf("II    I   IIII   II   II II     II II    II\n");
        printf("IIIIIII   II     IIIIIII II     II II    II\n");
        printf("II    I   I I    II   II II     II II    II\n");
        printf("II     I  I  I   II   II  II   II  II    II\n");
        printf("II    I   I   I  II   II   II II   II    II\n");
        printf("IIIIIII   I    I II   II    II     IIIIIIII\n");
        return 0;
}
