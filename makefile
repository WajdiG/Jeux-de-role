JDR: JDR1_0.o crea_avatar.o sauvegarde.o charger.o
	gcc JDR1_0.o crea_avatar.o sauvegarde.o charger.o -o JDR1
	
JDR1_0.o: JDR1_0.c
	gcc -c JDR1_0.c
	
crea_avatar.o: crea_avatar.c 
	gcc -c crea_avatar.c 

sauvegarde.o: sauvegarde.c 
	gcc -c sauvegarde.c 

charger.o: charger.c
	gcc -c charger.c
