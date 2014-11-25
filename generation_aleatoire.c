//PAS TERMINER, PARFOIS 3 COFFRE AU LIEU DE 4, CHEMIN ENTRE LES COFFRES A FAIRE 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#define N 20
#define M 20

char mat[N][M];
int tab[8];

/**
 *\fn initmat
 *\brief initialise la matrice où toutes les cases valent X, ainsi que le tableau tab où tout vaut 1
 */
void initmat(){
	int i,j;
	
	for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				mat[i][j]='X';
			}
	}
	
	for(i=0;i<8;i++){
		tab[i]=1;
	}
}

/**
 *\fn aff_mat
 *\brief affiche la matrice à l'écran
 */
void aff_mat(){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
}

/**
 *\fn verif_coffre(int , int)
 *\brief initialise la matrice, toutes les cases valent X
 *\param i entier représentant l'absisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre) et 1 si non
 */
int verif_coffre(int i, int j){
	if(mat[i+1][j]=='C'||mat[i+1][j]=='P'){
		return 0;
	}
	else if(mat[i-1][j]=='C'||mat[i-1][j]=='P'){
		return 0;
	}
	else if(mat[i+1][j+1]=='C'||mat[i+1][j+1]=='P'){
		return 0;
	}
	else if(mat[i-1][j+1]=='C'||mat[i-1][j+1]=='P'){
		return 0;
	}
	else if(mat[i+1][j-1]=='C'||mat[i+1][j-1]=='P'){
		return 0;
	}
	else if(mat[i-1][j-1]=='C'||mat[i-1][j-1]=='P'){
		return 0;
	}
	else if(mat[i][j+1]=='C'||mat[i][j+1]=='P'){
		return 0;
	}
	else if(mat[i][j-1]=='C'||mat[i][j-1]=='P'){
		return 0;
	}
	
	return 1;
}

/**
 *\fn verif_cour(int , int)
 *\brief verifie que la case dans laquelle on se trouve soit différente de C (un coffre) ou P (le joueur) 
 *\param i entier représentant l'absisse dans la matrice
 *\param j entier représentant l'ordonnée dans la matrice
 *\return int renvoie 0 si la case vérifiée contient C (un coffre) ou P (le joueur) et 1 si non
 */
int verif_cour(int i, int j){
	if(mat[i][j]=='C'||mat[i][j]=='P'){
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
	
	for(k=0;k<4;k++){
		do{
			i=rand()%(N-2)+1;
			j=rand()%(M-2)+1;
		}while(!verif_coffre(i,j)||j==0||i==0);
		mat[i][j]='C';
		tab[2*k]=i;
		tab[2*k+1]=j;
	}
}

/**
 *\fn gen_chemin
 *\brief permet de générer un chemin entre les coffres (C) et le joueur (P)
 */
void gen_chemin_joueur(){
	
	int a,b,k;
	
	for(k=0;k<4;k++){
		a=tab[2*k];
		b=tab[2*k+1];
	
		if(a==1){
			while(b>1){
				b--;
				if(verif_cour(a,b)){ 
					mat[a][b]=' ';	
				}
			}
		
		}
		else if(b==1){
			while(a>1){
				a--;
				if(verif_cour(a,b)){ 
					mat[a][b]=' ';	
				}
			}
		}
		else{
			while((a!=1||b!=2) && (a!=2||b!=2) && (a!=2||b!=1)){
				if(b>1){
					b--;
					if(verif_cour(a,b)){ 
						mat[a][b]=' ';
					}	
				}
				if(a>1){
					a--;
					if(verif_cour(a,b)){ 
						mat[a][b]=' ';	
					}
				}
			}
		}
	}
}

/**
 *\fn gen_chemin
 *\brief permet de générer un chemin entre les coffres (C)
 */
void gen_chemin_coffre(){
	int a,b,c,d;
	
	a=tab[0];
	b=tab[1];
	c=tab[2];
	d=tab[3];
	
	printf("\n %i %i %i %i \n", a,b,c,d);
	
	if(a==c){
		while(b>d){
			b--;
			if(!verif_cour(a,b)){
				mat[a][b]=' ';
			}
		}
		while(b<d){
			b++;
			if(!verif_cour(a,b)){
				mat[a][b]=' ';
			}
		}
	}
	else if(b==d){
		while(a>c){
			a--;
			if(!verif_cour(a,b)){
				mat[a][b]=' ';
			}
		}
		while(a<c){
			a++;
			if(!verif_cour(a,b)){
				mat[a][b]=' ';
			}
		}
	}
	
	else{
		if(a>c&&b>d){
			while(a>c&&b>d){
				a--;
				b--;
				if(!verif_cour(a,b)){
					mat[a][b]=' ';
				}
			}
			if(a==c){
				while(b>d){
					b--;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
			else if(b==d){
				while(a>c){
					a--;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
		}
		
		if(a>c&&b<d){
			while(a>c&&b<d){
				a--;
				b++;
				if(!verif_cour(a,b)){
					mat[a][b]=' ';
				}
			}
			if(a==c){
				while(b<d){
					b++;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
			else if(b==d){
				while(a>c){
					a--;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
		}
		
		if(a<c&&b>d){
			while(a>c&&b<d){
				a++;
				b--;
				if(!verif_cour(a,b)){
					mat[a][b]=' ';
				}
			}
			if(a==c){
				while(b>d){
					b--;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
			else if(b==d){
				while(a<c){
					a++;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
		}
		
		if(a<c&&b<d){
			while(a>c&&b<d){
				a++;
				b++;
				if(!verif_cour(a,b)){
					mat[a][b]=' ';
				}
			}
			if(a==c){
				while(b<d){
					b++;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
			else if(b==d){
				while(a<c){
					a++;
					if(!verif_cour(a,b)){
						mat[a][b]=' ';
					}
				}
			}
		}
	}
}

/**
 *\fn carre
 *\brief créer un espace autour du coffre et du joueur
 */
void carre(){
	
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(!verif_cour(i,j)&&i!=0&&j!=0){
				if(i+1!=(N-1)){
					mat[i+1][j]=' ';
					if(j+1!=(M-1)){
						mat[i+1][j+1]=' ';
					}
					if(j-1!=0){
						mat[i+1][j-1]=' ';
					}
				}
				if(i-1!=0){
					mat[i-1][j]=' ';
					if(j+1!=(M-1)){
						mat[i-1][j+1]=' ';
					}
					if(j-1!=0){
						mat[i-1][j-1]=' ';
					}
				}
				if(j+1!=(M-1)){
					mat[i][j+1]=' ';
				}
				if(j-1!=0){
					mat[i][j-1]=' ';
				}
			}
		}
	}
}

int main(){
	
	int w=0;
	
	while(w!=1){
		
		initmat();
		place_coffre();
		mat[1][1]='P';
		
		gen_chemin_joueur();
		
		gen_chemin_coffre();
		
		carre();
		
		
		aff_mat();
		
		printf("1-continuer, 0-recommencer : ");
		scanf("%i",&w); 
	}
	
	return EXIT_SUCCESS;
}
