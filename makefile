
OPTS = -Wall

JDR: JDR1_0.o crea_avatar.o sauvegarde.o charger.o region.o pile_tab.o monde.o
	gcc JDR1_0.o crea_avatar.o sauvegarde.o charger.o region.o pile_tab.o monde.o -o JDR1 ${OPTS}
	
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
	
region.o: region.c
	gcc -c region.c ${OPTS}
	
pile_tab.o: pile_tab.c
	gcc -c pile_tab.c ${OPTS}

clean:
	rm -f *.o JDR1
