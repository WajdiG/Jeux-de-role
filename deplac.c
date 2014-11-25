#include <stdio.h>
#include <stdlib.h>




int main(){

	char direction;
	int x, y;
	
	scanf("%c", &direction);
	
	switch(direction){
		case "z" : y++; break;
		case "q" : x--; break;
		case "s" : y--; break;
		case "d" : x++; break;
		default : deplac;
	}




	return EXIT_SUCCESS;
}
