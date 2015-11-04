#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void initRand(){
	srand(time(NULL));
}

char randChar(){
	int iCase = rand() % 1486387;

	/*	Tire une lettre au hasard en prenant en 
		compte leur fréquence d'apparition
		dans la langue française.
	*/
	if(iCase < 745) return 'k';
	if(iCase < 2492) return 'w';
	if(iCase < 4585) return 'z';
	if(iCase < 9310) return 'y';
	if(iCase < 15238) return 'x';
	if(iCase < 23589) return 'j';
	if(iCase < 34887) return 'h';
	if(iCase < 48175) return 'g';
	if(iCase < 61997) return 'b';
	if(iCase < 78348) return 'f';
	if(iCase < 99237) return 'q';
	if(iCase < 124212) return 'v';
	if(iCase < 169733) return 'm';
	if(iCase < 216068) return 'p';
	if(iCase < 266071) return 'c';
	if(iCase < 322340) return 'd';
	if(iCase < 405102) return 'o';
	if(iCase < 488770) return 'l';
	if(iCase < 585555) return 'u';
	if(iCase < 686055) return 'r';
	if(iCase < 794867) return 'n';
	if(iCase < 905970) return 't';
	if(iCase < 1021435) return 'i';
	if(iCase < 1138545) return 'a';
	if(iCase < 1260440) return 's';
	if(iCase < 1486387) return 'e';
	return '?';
}

int getIChar(char c){
	if(c == 'a') return 0;
	if(c == 'b') return 1;
	if(c == 'c') return 2;
	if(c == 'd') return 3;
	if(c == 'e') return 4;
	if(c == 'f') return 5;
	if(c == 'g') return 6;
	if(c == 'h') return 7;
	if(c == 'i') return 8;
	if(c == 'j') return 9;
	if(c == 'k') return 10;
	if(c == 'l') return 11;
	if(c == 'm') return 12;
	if(c == 'n') return 13;
	if(c == 'o') return 14;
	if(c == 'p') return 15;
	if(c == 'q') return 16;
	if(c == 'r') return 17;
	if(c == 's') return 18;
	if(c == 't') return 19;
	if(c == 'u') return 20;
	if(c == 'v') return 21;
	if(c == 'w') return 22;
	if(c == 'x') return 23;
	if(c == 'y') return 24;
	if(c == 'z') return 25;
	return -1;
}

int randCase(){
	return getIChar(randChar());
}