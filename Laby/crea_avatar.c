/**
*\file crea_avatar.c
*\brief regroupe toutes les fonctions nécessaire à la création de l'avatar
*\author Wajdi Guedouar
*\version 0.1
*\date 20 octobre 2014
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include "crea_avatar.h"

#define P 16 /**<constante définissant la taille maximale du pseudo*/

char pseudo[P];/**<tableau destiné à contenir le pseudo du joueur*/


/**
 *\fn void initstruct(t_joueur*)
 *\brief fonction permettant d'initialiser toutes les valeurs contenue dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void initstruct(t_joueur *joueur){	//fonction initialisant les valeurs des structures inclues dans t_joueur

		(*joueur).comp.agilite=10;
		(*joueur).comp.rapidite=10;
		(*joueur).comp.intelligence=10;
		(*joueur).comp.perception=10;
		(*joueur).comp.force=10;
		(*joueur).comp.puissance=10;
		(*joueur).comp.chance=10;

		(*joueur).vie.sante=100;
		(*joueur).vie.mana=100;
		(*joueur).vie.endu=100;

		(*joueur).combat.archerie=10;
		(*joueur).combat.precision=10;
		(*joueur).combat.unemain=10;
		(*joueur).combat.deuxmains=10;
		(*joueur).combat.lance=10;
		(*joueur).combat.contondant=10;
		(*joueur).combat.parade=10;
		(*joueur).combat.armureleg=10;
		(*joueur).combat.armurelou=10;
		(*joueur).combat.corpscorps=10;

		(*joueur).furtif.acrobatie=10;
		(*joueur).furtif.crochetage=10;
		(*joueur).furtif.discretion=10;
		(*joueur).furtif.dague=10;

		(*joueur).dial.marchandage=10;
		(*joueur).dial.charisme=10;
		(*joueur).dial.persuasion=10;

		(*joueur).magie.destruction=10;
		(*joueur).magie.guerison=10;
		(*joueur).magie.invocation=10;
}



/**
 *\fn void creer_pseudo(t_joueur*)
 *\brief fonction permettant au joueur de créer un pseudo et de le stocké dans le tableau char nom[] de la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
//ATTENTION PSEUDO EN DEUX PARTIE BUG, A RESOUDRE !!
void creer_pseudo(t_joueur *joueur){	//fonction permettant à l'utilisateur de se choisir un pseudo

	int i=0;
	int j=0;

	char pseudotest[100];								//Tableau contenant le pseudo entré par l'utilisateur pour tester sa taille

	for(i=0;i<P;i++){pseudo[i]='\0';}					//initialise les tableaux
	for(i=0;i<100;i++){pseudotest[i]='\0';}

	do{												//boucle test visant à ne pas dépasser le nombre limite de caractère pour le pseudo de l'utilisateur

		j=0;

		printw("Veuillez saisir un pseudo compris entre 3 et 15 caractère, sans espace : ");
		scanw("%s", pseudotest);						//insère la chaîne de caractère dans le tableau pseudotest

		for(i=0;pseudotest[i]!='\0';i++){j++;}			//compte le nombre de caractère contenu dans le tableau pseudotest

	}while(j<3||j>P-1);

	for(i=0;i<j;i++){pseudo[i]=pseudotest[i];}			//copie le pseudo valide dans le tableau pseudo

	pseudo[i]='\0';										// termine la chaîne de caractère par un '\0'

	printw("Votre pseudo est %s. \n",pseudo);


	for(i=0;i<j+1;i++){
		(*joueur).pseudo[i]=pseudo[i];
	}
}


/**
 *\fn void race(t_joueur*)
 *\brief fonction permettant au joueur de choisir une race parmis les choix du type énuméré t_race, son choix sera alors sauvegardé dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void race(t_joueur *joueur){	//fonction permettant à l'utilisateur de choisir la race de son avatar

	int i=0;
	int choix=0;

	while(i==0){

		do{						//test afin que le chiffre saisit corresponde bien à un choix possible
			printw("\nChoisissez votre race en tapant le chiffre correspondant : \n");
			printw("1- Elfe \n");
			printw("2- Humain \n");
			printw("3- Nain \n");
			printw("4- Orc \n");
			printw("5- Troll \n");
			printw("Votre choix :");

			scanw("%i", &choix);			
		}while(choix<1||choix>5);


        switch(choix){                                    //présentation des caractéristiques liées aux différentes races
		case 1 : printw("Vous êtes un Elfe. Les Elfes ont un bonus de Perception, d'Agilité et de Rapidité. Vous êtes équipé d'une épée courte et d'un arc long ce qui fait de vous une menace permanente dans toutes les situations. \n"); (*joueur).physique.race=elfe;break;
		case 2 : printw("Vous êtes un Humain, les Humains ont un bonus d'Agilité, de Force et de Rapidité. Bien que les humains soient polyvalent en ce qui concerne leur technique de combat, vous êtes équipé d'une épée courte et d'un arc court ce qui diminue la portée de vos flèches contrairement aux arcs longs. \n"); (*joueur).physique.race=humain;break;
		case 3 : printw("Vous êtes un Nain, les Nains ont un bonus de Perception, de Force et de Puissance. Vous êtes équipé de dague de lancer et d'une hache à deux mains ce qui fait de vous un adversaire redoutable en combat raproché. \n"); (*joueur).physique.race=nain;break;
		case 4 : printw("Vous êtes un Orc, les Orcs ont un bonus de Puissance, de Force et de Rapidité. Vous êtes équipé d'un arc court et d'une masse à une main vous rendant aussi dangereux que vous l'espériez. \n"); (*joueur).physique.race=orc;break;
        case 5 : printw("Vous êtes un Troll, les Trolls ont un gros bonus de Puissance et de Force. Vous êtes équipé d'un marteau de guerre à deux mains, rien ne peux vous arrêter ! \n"); (*joueur).physique.race=troll;break;
        }


		printw(" L'équipement lié à votre race est un équipement par défaut qui pourra être modifié au cour du jeu. Etes vous sûre de votre choix ? \n");
		printw("tapez 0 pour changer, n'importe quel autre chiffre entier pour valider : ");
		scanw("%i", &i);							//donne à l'utilisateur la possibilité de changer son choix.
	}
}


/**
 *\fn void sexe(t_joueur*)
 *\brief fonction permettant au joueur de choisir le sexe de son avatar, son choix sera sauvegardé dans le type énuméré t_sexe de la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void sexe(t_joueur *joueur){	//fonction permettant à l'utilisateur de choisir le sexe de son avatar
								//fonction permettant à l'utilisateur de choisir le sexe de son avatar
	int choix=-1;

	do{						//test afin que le chiffre saisit corresponde bien à un choix possible
		printw("\nLe sexe de votre personnage n'aura pas d'impact sur ses compétences, il peut toutefois vous donnez des choix différents lors de vos quètes et dialogues. Choisissez votre sexe : \n");
		printw("0- Masculin \n");
		printw("1- Féminin \n");
		printw("2_ Sans \n");
		printw("Votre choix :");

		scanw("%i", &choix);				
	}while(choix!=0&&choix!=1&&choix!=2);


    switch(choix){
	case 0: (*joueur).physique.sexe=homme; printw("Vous êtes un mâle. \n"); break;
	case 1 : (*joueur).physique.sexe=femme; printw("Vous êtes une femelle. \n"); break;
	case 2 : (*joueur).physique.sexe=sans; printw("Vous n'avez pas de sexe. \n"); break;
    }
}

/**
 *\fn void taille(t_joueur*)
 *\brief fonction permettant au joueur de choisir sa taille (en centimètre) parmis des choix proposés dépendant de sa race. Une fois valider, son choix sera sauvegardé dans l'entier int taille de la structure t_joueur 
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void taille(t_joueur *joueur){	//fonction permettant à l'utilisateur de choisir la taille de son avatar
	int tal=0;

	if((*joueur).physique.race==nain){
		while(tal<100||tal>150){
			printw("\nChoisissez la taille de votre avatar en cm (comprise entre 100 et 150), la taille de votre avatar aura une influence sur votre expérience de jeu. \n votre taille : ");
			scanw("%i", &tal);
		}
	}
	else if((*joueur).physique.race==humain||(*joueur).physique.race==elfe||(*joueur).physique.race==orc){
		while(tal<140||tal>220){
			printw("\nChoisissez la taille de votre avatar en cm (comprise entre 140 et 220), la taille de votre avatar aura une influence sur votre expérience de jeu. \n votre taille : ");
			scanw("%i", &tal);
		}
	}
	else{
		while(tal<160||tal>280){
			printw("\nChoisissez la taille de votre avatar en cm (comprise entre 160 et 280), la taille de votre avatar aura une influence sur votre expérience de jeu. \n votre taille : ");
			scanw("%i", &tal);
		}
	}

	printw("Vous mesurez %i cm.\n",tal);

	(*joueur).physique.taille=tal;
}

/**
 *\fn void poids(t_joueur*)
 *\brief fonction permettant au joueur de choisir le poids de son avatar (en kg) en fonction de sa race, une fois choisit, la fonction calcule l'IMC de l'avatar et en fonction du résultat, associe une des valeurs du type énuméré t_poids dans la structure t_joueur
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void poids(t_joueur *joueur){	//fonction permettant à l'utilisateur de choisir le poids de son avatar
    float ch=10000.0;
	float poids=0.0;

	float taille=(*joueur).physique.taille;
    float imc=0.0;


	if((*joueur).physique.race==elfe||(*joueur).physique.race==humain){
		do{					//test afin de que le poids soit dans la fourchette voulue
			printw("\nVeuillez saisir un nombre entier correspondant au poids de votre avatar compris entre 40 et 200kg : ");
			scanw("%f", &poids);
		}while(poids<40||poids>200);

        imc= (poids/(taille*taille))*ch;

		if(imc<16.5){
			printw("vous êtes anoréxique, vous pourrez passer par tout les chemins y compris les passages les plus étroits étroits, vote avatar aura un grand bonus d'agilité et de rapidité et un grand malus de force et de puissance. Vous risquez d'avoir certaine surprise durant votre partie ...\n");
			(*joueur).physique.poids=anorexique;
		}
		else if(imc>=16.5&&imc<18.5){
			printw("vous êtes mince voir très mince, vous pourrez emprunter la plupart des chemins, votre avatar aura un léger bonus d'agilité et de rapidité et un léger malus de force et de puissance. \n");
			(*joueur).physique.poids=mince;
		}
		else if(imc>=18.5&&imc<25){
			printw("Vous êtes bien batît, vous pourrez passer sur les chemins classiques, vous avez des compétences équilibrées \n");
			(*joueur).physique.poids=moyen;
		}
		else if(imc>=25&&imc<30){
			printw("Vous êtes en surpoids, vous ne pourrez pas passer par tout les chemins. vous avez un bonus de force et de puissance et un malus de rapidité et d'agilité. \n");
			(*joueur).physique.poids=surpoids;
		}
		else if(imc>=30&&imc<35){
			printw("Vous êtes obèse, vous ne pourrez passer que par les chemins suffisament large pour vous. Vous avez un grand bonus de force et de puissance et un grand malus de rapidité et d'agilité. \n");
			(*joueur).physique.poids=obese;
		}
		else if(imc>=35){
			printw("Vous êtes rangé(e) dans la catégorie \"obèsité morbide\". Vous avez un énorme bonus de force et puissance et un énorme malus de rapidité et d'agilité. Vous risquez d'avoir certaines surprise durant votre aventure... \n");
			(*joueur).physique.poids=obesemo;
		}
	}
	else if((*joueur).physique.race==nain){
		while(poids<40||poids>200){					//test afin que le poids soit dans la fourchette voulue
			printw("Veuillez saisir un nombre entier correspondant au poids de votre avatar compris entre 40 et 200kg : ");
			scanw("%f", &poids);
		}

        imc=(poids/(((*joueur).physique.taille)*((*joueur).physique.taille)))*10000;

		if(imc<45){
			printw("vous êtes anoréxique, vous pourrez passer par les passages étroits, vote avatar aura un grand bonus d'agilité et de rapidité et un grand malus de force et de puissance. Vous risquez d'avoir certaine surprise durant votre partie ...\n");
			(*joueur).physique.poids=anorexique;
		}
		else if(imc>=45&&imc<48){
			printw("vous êtes mince voir très mince, vous pourrez emprunter la plupart des chemins mais pas tous, vos caractéristiques ont un léger bonus d'agilité et de rapidité et un léger malus de force et de puissance. \n");
			(*joueur).physique.poids=mince;
		}
		else if(imc>=48&&imc<57){
			printw("Vous êtes de corpulence moyenne, vous ne pourrez passer que sur les chemins classiques, vous avez des compétences équilibrées \n");
			(*joueur).physique.poids=moyen;
		}
		else if(imc>=57&&imc<60){
			printw("Vous êtes en surpoids, vous ne pourrez passer que par les chemins suffisament large pour vous. Vous avez un grand bonus de force et de puissance et un grand malus de rapidité et d'agilité. \n");
			(*joueur).physique.poids=surpoids;
		}
		else{
			printw("Vous êtes obèse. Vous avez un énorme bonus de force et puissance et un énorme malus de rapidité et d'agilité. Vous risquez d'avoir certaines surprise durant votre aventure... \n");
			(*joueur).physique.poids=obese;
		}
	}
	else if((*joueur).physique.race==orc){
		while(poids<40||poids>200){					//test afin que le poids soit dans la fourchette voulue
			printw("Veuillez saisir un nombre entier correspondant au poids de votre avatar compris entre 40 et 200kg : ");
			scanw("%f", &poids);
		}


        imc=(poids/(((*joueur).physique.taille)*((*joueur).physique.taille)))*10000;
		

		if(imc<18){
			printw("vous êtes anoréxique, vous pourrez passer par les passages étroits, vote avatar aura un grand bonus d'agilité et de rapidité et un grand malus de force et de puissance. Vous risquez d'avoir certaine surprise durant votre partie ...\n");
			(*joueur).physique.poids=anorexique;
		}
		else if(imc>=18&&imc<21){
			printw("vous êtes mince voir très mince, vous pourrez emprunter la plupart des chemins mais pas tous, vos caractéristiques ont un léger bonus d'agilité et de rapidité et un léger malus de force et de puissance. \n");
			(*joueur).physique.poids=mince;
		}
		else if(imc>=21&&imc<27){
			printw("Vous êtes de corpulence moyenne, vous ne pourrez passer que sur les chemins classiques, vous avez des compétences équilibrées \n");
			(*joueur).physique.poids=moyen;
		}
		else if(imc>=27&&imc<30){
			printw("Vous êtes en surpoids, vous ne pourrez passer que par les chemins suffisament large pour vous. Vous avez un grand bonus de force et de puissance et un grand malus de rapidité et d'agilité. \n");
			(*joueur).physique.poids=surpoids;
		}
		else{
			printw("Vous êtes obèse. Vous avez un énorme bonus de force et puissance et un énorme malus de rapidité et d'agilité. Vous risquez d'avoir certaines surprise durant votre aventure... \n");
			(*joueur).physique.poids=obese;
		}
	}
	else if((*joueur).physique.race==troll){
		while(poids<100||poids>350){					//test afin que le poids soit dans la fourchette voulue
			printw("Veuillez saisir un nombre entier correspondant au poids de votre avatar compris entre 100 et 350kg : ");
			scanw("%f", &poids);
		}


        imc=(poids/(((*joueur).physique.taille)*((*joueur).physique.taille)))*10000;
	

		if(imc<32){
			printw("vous êtes anoréxique, vous pourrez passer par les passages étroits, vote avatar aura un grand bonus d'agilité et de rapidité et un grand malus de force et de puissance. Vous risquez d'avoir certaine surprise durant votre partie ...\n");
			(*joueur).physique.poids=anorexique;
		}
		else if(imc>=32&&imc<36){
			printw("vous êtes mince voir très mince, vous pourrez emprunter la plupart des chemins mais pas tous, vos caractéristiques ont un léger bonus d'agilité et de rapidité et un léger malus de force et de puissance. \n");
			(*joueur).physique.poids=mince;
		}
		else if(imc>=36&&imc<44){
			printw("Vous êtes de corpulence moyenne, vous ne pourrez passer que sur les chemins classiques, vous avez des compétences équilibrées \n");
			(*joueur).physique.poids=moyen;
		}
		else if(imc>=44&&imc<48){
			printw("Vous êtes en surpoids, vous ne pourrez passer que par les chemins suffisament large pour vous. Vous avez un grand bonus de force et de puissance et un grand malus de rapidité et d'agilité. \n");
			(*joueur).physique.poids=surpoids;
		}
		else{
			printw("Vous êtes obèse. Vous avez un énorme bonus de force et puissance et un énorme malus de rapidité et d'agilité. Vous risquez d'avoir certaines surprise durant votre aventure... \n");
			(*joueur).physique.poids=obese;
		}
	}
}

/**
 *\fn void initCaract(t_joueur*)
 *\brief fonction mettant à jour les compétences secondaires et principales du joueur en fonctions de l'IMC et de la race du joueur.
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void initCaract(t_joueur *joueur){	//fonction permettant de modifier les structures inclues dans t_joueur en fonction des choix de l'utilisateur concernant race;taille;poids


	if((*joueur).physique.race==elfe){									//adaptation des caractéristiques en fonction de la race
		(*joueur).comp.rapidite+=2;
		(*joueur).comp.perception+=2;
		(*joueur).comp.agilite+=2;
		(*joueur).combat.archerie+=3;
		(*joueur).combat.precision+=3;
		(*joueur).combat.unemain+=3;
		(*joueur).combat.deuxmains+=3;
		(*joueur).combat.armureleg+=3;
		(*joueur).furtif.discretion+=3;
		(*joueur).furtif.acrobatie+=3;
		(*joueur).dial.charisme+=3;
        (*joueur).combat.armurelou-=3;
        (*joueur).dial.marchandage-=3;
        (*joueur).combat.corpscorps-=3;
	}
	else if((*joueur).physique.race==humain){
		(*joueur).comp.rapidite+=2;
		(*joueur).comp.force+=2;
		(*joueur).comp.agilite+=2;
		(*joueur).combat.archerie+=3;
		(*joueur).combat.deuxmains+=3;
		(*joueur).dial.persuasion+=3;
		(*joueur).furtif.crochetage+=3;
		(*joueur).combat.parade+=3;
	}
	else if((*joueur).physique.race==nain){
		(*joueur).comp.perception+=2;
		(*joueur).comp.force+=2;
		(*joueur).comp.puissance+=2;
		(*joueur).combat.contondant+=3;
		(*joueur).combat.parade+=3;
		(*joueur).combat.unemain+=3;
		(*joueur).combat.armurelou+=3;
		(*joueur).dial.marchandage+=3;
		(*joueur).combat.archerie-=3;
		(*joueur).furtif.discretion-=3;
		(*joueur).furtif.acrobatie-=3;
	}
	else if((*joueur).physique.race==orc){
		(*joueur).comp.rapidite+=2;
		(*joueur).comp.puissance+=2;
		(*joueur).comp.force+=2;
		(*joueur).combat.archerie+=3;
		(*joueur).combat.precision+=3;
		(*joueur).combat.unemain+=3;
		(*joueur).combat.parade+=3;
		(*joueur).combat.lance+=3;
		(*joueur).combat.armureleg+=3;
		(*joueur).furtif.dague+=3;
		(*joueur).furtif.crochetage-=3;
		(*joueur).dial.charisme+=3;
		(*joueur).dial.marchandage+=3;

	}
	else{
		(*joueur).comp.force+=5;
		(*joueur).comp.puissance+=5;
		(*joueur).combat.contondant+=3;
		(*joueur).combat.corpscorps+=3;
		(*joueur).combat.unemain+=3;
		(*joueur).combat.deuxmains+=3;
        (*joueur).furtif.acrobatie-=3;
        (*joueur).furtif.discretion-=3;
        (*joueur).dial.persuasion-=3;
	}


	if((*joueur).physique.poids==anorexique){									//adaptation des caractéristiques en fonction du poids
		(*joueur).comp.rapidite+=4;
		(*joueur).comp.agilite+=4;
		(*joueur).comp.force-=4;
		(*joueur).comp.puissance-=4;
	}
	else if((*joueur).physique.poids==mince){
		(*joueur).comp.rapidite+=2;
		(*joueur).comp.agilite+=2;
		(*joueur).comp.force-=2;
		(*joueur).comp.puissance-=2;
	}
	else if((*joueur).physique.poids==moyen);
	else if((*joueur).physique.poids==surpoids){
		(*joueur).comp.rapidite-=2;
		(*joueur).comp.agilite-=2;
		(*joueur).comp.force+=2;
		(*joueur).comp.puissance+=2;
		}
	else if((*joueur).physique.poids==obese){
		(*joueur).comp.rapidite-=3;
		(*joueur).comp.agilite-=3;
		(*joueur).comp.force+=3;
		(*joueur).comp.puissance+=3;
	}
	else{
		(*joueur).comp.rapidite-=4;
		(*joueur).comp.agilite-=4;
		(*joueur).comp.force+=4;
		(*joueur).comp.puissance+=4;
	}
}

/**
 *\fn void attribution_points(t_joueur*,int,int)
 *\brief fonction permettant au joueur de répartir un nombre donné de points de compétences principales et secondaires.
 *\param *joueur pointeur sur la structure t_joueur joueur
 *\param principale nombre de points de compétences principales à répartir
 *\param secondaire nombre de points de compétences secondaires à répartir
 */
void attribution_points(t_joueur *joueur, int principale, int secondaire){  //fonction permettant à l'utilisiateur de distribuer des points de compétence.
	int cpt,sec;
	int choix=0;

	cpt=principale;
	sec=secondaire;

	while(cpt>0){

		printw("\nVous avez %i points de compétences à répartir parmis vos compétences principales : \n",cpt);
		printw("1	Rapidité : %i \n", (*joueur).comp.rapidite);
		printw("2	Agilité : %i \n", (*joueur).comp.agilite);
		printw("3	Force : %i \n", (*joueur).comp.force);
		printw("4	Puissance : %i \n", (*joueur).comp.puissance);
		printw("5	Intelligence : %i \n", (*joueur).comp.intelligence);
		printw("6	Perception : %i \n", (*joueur).comp.perception);
		printw("7	Chance : %i \n", (*joueur).comp.chance);
		printw("Saisisser la compétence à augmenter : \n");
		scanw("%i", &choix);
		
		while(choix<1||choix>7){
			printw("Saisissez une valeur entière valide :");
			scanw("%i", &choix);
		}

		switch(choix){
			case 1 : (*joueur).comp.rapidite++;break;
			case 2 : (*joueur).comp.agilite++;break;
			case 3 : (*joueur).comp.force++;break;
			case 4 : (*joueur).comp.puissance++;break;
			case 5 : (*joueur).comp.intelligence++;break;
			case 6 : (*joueur).comp.perception++;break;
			case 7 : (*joueur).comp.chance++;break;
		}
		cpt--;
	}
	clear();
	printw("\nVoici vos niveaux de compétences principales actuels : \n");
	printw("	Rapidité : %i \n", (*joueur).comp.rapidite);
	printw("	Agilité : %i \n", (*joueur).comp.agilite);
	printw("	Force : %i \n", (*joueur).comp.force);
	printw("	Puissance : %i \n", (*joueur).comp.puissance);
	printw("	Intelligence : %i \n", (*joueur).comp.intelligence);
	printw("	Perception : %i \n", (*joueur).comp.perception);
	printw("	Chance : %i \n", (*joueur).comp.chance);

	while(sec>0){
		printw("\nVous avez %i points de compétences à répartir parmis vos compétences secondaires : \n",sec);
		printw("Compétences de combat : \n");
		printw("1	Archerie : %i \n", (*joueur).combat.archerie);
		printw("2	Précision : %i \n", (*joueur).combat.precision);
		printw("3	Une main : %i \n", (*joueur).combat.unemain);
		printw("4	Deux mains : %i \n", (*joueur).combat.deuxmains);
		printw("5	Lance : %i \n", (*joueur).combat.lance);
		printw("6	Contondant : %i \n", (*joueur).combat.contondant);
		printw("7	Parade : %i \n", (*joueur).combat.parade);
		printw("8	Armure légère : %i \n", (*joueur).combat.armureleg);
		printw("9	Armure lourde : %i \n", (*joueur).combat.armurelou);
		printw("10  	Corps à corps : %i \n", (*joueur).combat.corpscorps);
		printw("\nCompétences de furtivité : \n");
		printw("11	Crochetage : %i \n", (*joueur).furtif.crochetage);
		printw("12	Discretion : %i \n", (*joueur).furtif.discretion);
		printw("13	Dague : %i \n", (*joueur).furtif.dague);
		printw("14	Acrobatie : %i \n", (*joueur).furtif.acrobatie);
		printw("\nCompétences de dialogue : \n");
		printw("15	Charisme : %i \n", (*joueur).dial.charisme);
		printw("16	Persuasion : %i \n", (*joueur).dial.persuasion);
		printw("17	Marchandage : %i \n", (*joueur).dial.marchandage);
		printw("\nCompétences de magie : \n");
		printw("18	Destruction : %i \n", (*joueur).magie.destruction);
		printw("19	Guérison : %i \n", (*joueur).magie.guerison);
		printw("20	Invocation : %i \n", (*joueur).magie.invocation);
		printw("Saisisser la compétence à augmenter : \n");
		scanw("%i", &choix);

		while(choix<1||choix>19){
			printw("Saisissez une valeur entière valide :");
			scanw("%i", &choix);
		}

		switch(choix){
			case 1 : (*joueur).combat.archerie++;break;
			case 2 : (*joueur).combat.precision++;break;
			case 3 : (*joueur).combat.unemain++;break;
			case 4 : (*joueur).combat.deuxmains++;break;
			case 5 : (*joueur).combat.lance++;break;
			case 6 : (*joueur).combat.contondant++;break;
			case 7 : (*joueur).combat.parade++;break;
			case 8 : (*joueur).combat.armureleg++;break;
			case 9 : (*joueur).combat.armurelou++;break;
			case 10 : (*joueur).combat.corpscorps++;break;
			case 11 : (*joueur).furtif.crochetage++;break;
			case 12 : (*joueur).furtif.discretion++;break;
			case 13 : (*joueur).furtif.dague++;break;
			case 14 : (*joueur).furtif.acrobatie++;break;
			case 15 : (*joueur).dial.charisme++;break;
			case 16 : (*joueur).dial.persuasion++;break;
			case 17 : (*joueur).dial.marchandage++;break;
			case 18 : (*joueur).magie.destruction++;break;
			case 19 : (*joueur).magie.guerison++;break;
			case 20 : (*joueur).magie.invocation++;break;

		}
		sec--;
	}

	clear();
	printw("\nVoici vos niveaux de compétences secondaires actuels : \n");

    printw("Compétences de combat : \n");
    printw("	Archerie : %i \n", (*joueur).combat.archerie);
    printw("	Précision : %i \n", (*joueur).combat.precision);
    printw("	Une main : %i \n", (*joueur).combat.unemain);
    printw("	Deux mains : %i \n", (*joueur).combat.deuxmains);
    printw("	Lance : %i \n", (*joueur).combat.lance);
    printw("	Contondant : %i \n", (*joueur).combat.contondant);
    printw("	Parade : %i \n", (*joueur).combat.parade);
    printw("	Armure légère : %i \n", (*joueur).combat.armureleg);
    printw("	Armure lourde : %i \n", (*joueur).combat.armurelou);
    printw("\nCompétences de furtivité : \n");
    printw("    Crochetage : %i \n", (*joueur).furtif.crochetage);
    printw("	Discretion : %i \n", (*joueur).furtif.discretion);
    printw("	Dague : %i \n", (*joueur).furtif.dague);
    printw("	Acrobatie : %i \n", (*joueur).furtif.acrobatie);
    printw("\nCompétences de dialogue : \n");
    printw("	Charisme : %i \n", (*joueur).dial.charisme);
    printw("	Persuasion : %i \n", (*joueur).dial.persuasion);
    printw("	Marchandage : %i \n", (*joueur).dial.marchandage);
    printw("\nCompétences de magie : \n");
    printw("	Destruction : %i \n", (*joueur).magie.destruction);
    printw("	Guérison : %i \n", (*joueur).magie.guerison);
    printw("	Invocation : %i \n", (*joueur).magie.invocation);
}

/**
 *\fn void config(t_joueur*)
 *\brief fonction permettant au joueur de voir un récapitulatif du contenu de la fonction t_joueur et lui permet de revenir sur la race, la taille, le poids, le sexe et le pseudo. Si non, il peut lancer l'aventure.
 *\param *joueur pointeur sur la structure t_joueur joueur
 */
void config(t_joueur *joueur){	//Fonction permettant à l'utilisateur de revenir sur un choix concernant le physique de votre avatar

	int choix=0;
	int m,c;

	printw("\nChacun de vos choix concernant les caractéristiques physiques de votre avatar auront un impact sur votre expérience de jeu et sur les compétences suivantes : Rapidité, Agilité, Perception, Force et Puissance. Vous aurez à chaques choix la possibilité de changer d'avis. \n");

	while(choix!=6){

		printw("\n Voici vos caractéristiques actuelles : \n");			//récapitulatif des compétences de l'avatar
		printw("	Rapidité    : %i \n", (*joueur).comp.rapidite);
		printw("	Agilité     : %i \n", (*joueur).comp.agilite);
		printw("	Force       : %i \n", (*joueur).comp.force);
		printw("	Puissance   : %i \n", (*joueur).comp.puissance);
		printw("	Intelligence: %i \n", (*joueur).comp.intelligence);
		printw("	Perception  : %i \n", (*joueur).comp.perception);
		printw("	Chance 	: %i \n", (*joueur).comp.chance);
		printw("Pseudo : %s \n", (*joueur).pseudo);
		if((*joueur).physique.race==1){
			printw("Race : elfe \n");
        }
        else if((*joueur).physique.race==2){
            printw("Race : humain \n");
        }
        else if((*joueur).physique.race==3){
            printw("Race : nain \n");
        }
        else if((*joueur).physique.race==4){
            printw("Race : orc \n");
        }
        else{
            printw("Race : troll \n");
        }
        
        m=(*joueur).physique.taille/100;
        c=(*joueur).physique.taille%100;
        
        if(c==0){
			printw("Taille : %i m \n", m);
		}
		else{
			printw("Taille : %i m %i \n", m,c);
		}
        
        if((*joueur).physique.poids==1){
			printw("Corpulence : anorexique \n");
        }
        else if((*joueur).physique.poids==2){
            printw("Corpulence : mince \n");
        }
        else if((*joueur).physique.poids==3){
            printw("Corpulence : moyenne \n");
        }
        else if((*joueur).physique.poids==4){
            printw("Corpulence : surpoids \n");
        }
        else if((*joueur).physique.poids==5){
            printw("Corpulence : obèse \n");
        }
        else{
            printw("Corpulence : obèsité morbide \n");
        }
        
																		//Offre la possibilité de modifier l'une des options de l'avatar
		printw("\nSélectionnez l'une des options suivantes : \n");
		printw("1- Modifier votre pseudo \n");
		printw("2- Modifier votre race \n");
		printw("3- Modifier votre poids \n");
		printw("4- Modifier votre sexe \n");
		printw("5_ Modifier votre taille \n");
		printw("6- Commencez l'aventure \n");
		printw("Votre choix doit être compris entre 1 et 6 : ");
		scanw("%i", &choix);

		switch(choix){
			case '1' : creer_pseudo(joueur); break;
			case '2' : race(joueur); printw("Vous devez maintenant ajuster votre taille et votre poids. \n"); taille(joueur); poids(joueur); initCaract(joueur); break;
			case '3' : poids(joueur); initCaract(joueur); break;
			case '4' : sexe(joueur); break;
			case '5' : taille(joueur); poids(joueur); initCaract(joueur); break;
			case '6' : break;
			default : printw("Veuillez saisir une valeur valide comprise entre 1 et 6. \n");
		}
	}

	printw("Que l'aventure commence ... \n");
}

/**
 *\fn void crea_ava(t_joueur*,int,int)
 *\brief fonction permettant d'appeler toutes les fonctions du fichier crea_avatar.c dans l'ordre voulu
 *\param *joueur pointeur sur la structure t_joueur joueur
 *\param principale nombre de points de compétences principales à répartir
 *\param secondaire nombre de points de compétences secondaires à répartir
 */
void crea_ava(t_joueur *joueur,int principale,int secondaire){ //fonction contenant toutes les fonctions nécessaires à la création de l'avatar

	initstruct(joueur);
	creer_pseudo(joueur);
	race(joueur);
	clear();
	sexe(joueur);
	taille(joueur);
	poids(joueur);
	clear();
	initCaract(joueur);
	clear();
    	attribution_points(joueur,principale,secondaire);
	clear();
    	config(joueur);
	clear();
}
