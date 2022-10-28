#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <curses.h>


using namespace std;


// void menu() {

// 	int pointer = 1;
	
// 	int input;
	
	
	


// 	do {
		
// 		switch(pointer) {
// 		case 1 :
// 			puts("NEW GAME         <");
// 			puts("LOAD GAME");
// 			puts("SETTING");
// 			puts("HOW TO PLAY");
// 			puts("EXIT");
// 			break;
		
// 		case 2:
// 			puts("NEW GAME");
// 			puts("LOAD GAME       <");
// 			puts("SETTING");
// 			puts("HOW TO PLAY");
// 			puts("EXIT");
// 			break;
// 		case 3:
// 			puts("NEW GAME");
// 			puts("LOAD GAME");
// 			puts("SETTING          <");
// 			puts("HOW TO PLAY");
// 			puts("EXIT");
// 			break;
// 		case 4:
// 			puts("NEW GAME");
// 			puts("LOAD GAME");
// 			puts("SETTING");
// 			puts("HOW TO PLAY      <");
// 			puts("EXIT");
// 			break;
// 		case 5:
// 			puts("NEW GAME");
// 			puts("LOAD GAME");
// 			puts("SETTING");
// 			puts("HOW TO PLAY");
// 			puts("EXIT             <");
// 			break;
// 	}
// 		printf(">>> ");
// 		input = getch();
// 		switch(input) {

// 			case KEY_UP: 
// 				if(pointer == 1) {
// 					pointer = 5; break;
// 				}
// 				else {
// 					pointer--; break;
// 				}
// 			case KEY_DOWN:
// 				if(pointer == 5) {
// 					pointer = 1; break;
// 				} else {
// 					pointer++; break;
// 				}
// 		}
// 		system("clear");
// 	} while(input != KEY_ENTER);
		

// 	printf("Entering Menu %d\n", pointer);

// }
	
int checkString(char str, char sub){
	char *p1, *p2, *p3;
	int i=0,j=0,flag=0;

	p1 = str;
	p2 = sub;

	for(i = 0; i<strlen(str); i++)
	{
		if(*p1 == *p2)
		{
			p3 = p1;
			for(j = 0;j<strlen(sub);j++)
			{
				if(*p3 == *p2)
				{
				p3++;p2++;
				} 
				else
				break;
			}
			p2 = sub;
			if(j == strlen(sub))
			{
				flag = 1;
				return 1;
			}
		}
		p1++; 
	}
	if(flag==0)
	{
		return 0;
	}
}


// void newgame() {

// 	char name[7] = "TinTin";

// 	FILE * fp;
// 	fp = fopen("./database/player.dat", "r");
// 	char x[10000];
// 	do {
// 		fscanf(fp, "%[^#]#", x);
// 		if(strstr(&x, &name) != NULL){
// 			puts("Name already taken");
// 			break;
// 		}
// 	} while(!feof(fp));

	

// }


int main() {

	
	char string[] = "Bruh Bro";
	char sub[] = "Bro";

	printf("%d", checkString(string, sub));

	return 0;

}
