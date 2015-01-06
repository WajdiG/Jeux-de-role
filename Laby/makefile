OPTS = -Wall

prog4: IA.o pile_tab.o region.o combatRework.o accueil.o deplacement.o JDR1_0.o crea_avatar.o sauvegarde.o charger.o monde.o
	gcc IA.o pile_tab.o region.o combatRework.o accueil.o deplacement.o JDR1_0.o crea_avatar.o sauvegarde.o charger.o monde.o -lncurses -o JDR ${OPTS}
	
pile_tab.o : pile_tab.c
	gcc -c pile_tab.c ${OPTS}
	
region.o : region.c
	gcc -c region.c ${OPTS}
	
IA.o: IA.c 
	gcc -c IA.c ${OPTS}
	
combatRework.o : combatRework.c
	gcc -c combatRework.c ${OPTS}

accueil.o : accueil.c
	gcc -c accueil.c ${OPTS}
	
deplacement.o : deplacement.c
	gcc -c deplacement.c ${OPTS}
	
JDR1_0.o: JDR1_0.c
	gcc -c JDR1_0.c ${OPTS}
	
crea_avatar.o: crea_avatar.c 
	gcc -c crea_avatar.c ${OPTS}

sauvegarde.o: sauvegarde.c 
	gcc -c sauvegarde.c ${OPTS} 

charger.o: charger.c
	gcc -c charger.c ${OPTS}
	
monde.o: monde.c
	gcc -c monde.c
	
clean: 
	rm -f *.o JDR
