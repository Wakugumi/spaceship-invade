#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
#include <unistd.h>
#include <curses.h>

// User-defined header
#include "T143_utility.h"

#define KEY_UP 72
#define KEY_DOWN 80


using namespace std;


struct Player {
	
};


void newgame() {

 	char name[1000];

 	FILE * fp;
 	fp = fopen("./database/player.dat", "r");
 	char x[10000];
 	
 	// ----------------------------- Input and Validation --------------------------- //
	 do {
		printf("Input your new name : ");
 		scanf("%s", name);
 		puts("");
 		int length;
 		for(length = 0; name[length] != '\0'; ++length);
 		if( length <= 3 ){ // Validation
 			puts("Username must be more than 3 characters");
 			puts("");
 			continue;
		 }
 		
 		fscanf(fp, "%[^#]", x);
 		
 		if(checkString(x, name)) { // If name was found
 			puts("Sorry but name already taken! [press enter]");
 			continue;
 		} else { // If entered username is safe
 			break;
		 }
 	} while(!feof(fp));
	puts("");
	printf("Creating new game under the name [%s]...\n", name);
	usleep(3000000);
	
	fclose(fp);	
	
	puts("New game created. Redirecting...");
	usleep(1000000);
	system("cls");
	

 }

void loadgame() {
	
	// Definitions
	int input;
	FILE * fp;
	fp = fopen("./database/player.dat", "r");
	
//	do {
//		fscanf(fp, "%s\n", x);
//		puts(x);
//	} while(!feof(fp));

	char list[10][10000];	
	int count = 0;
	
	do {
		fscanf(fp, "%s\n", list[count]);
		count++;
	} while(!feof(fp));
	
	fclose(fp);
	puts("");
	
	
	// Display
	puts("Save Data :");
	for(int i = 0; i < count; i++) {
		printf("%d. %s\n", i + 1, list[i]);
	}
	puts("");
	printf(">>> ");
	scanf("%d", &input);
	
	printf("Loading game data [%s]", list[input-1]);

}


int setting() {
	puts("Welcome to the game!\n");
	puts("Basic Movement");
	puts("'w' - Move Up");
	puts("'a' - Move Left");
	puts("'s' - Move Down'");
	puts("'d' - Move Right");
	puts("");
	puts("Lobby Arena");
	puts("'SPACE' - Interact");
	puts("'y' - Talk");
	puts("'o' - Open Backpack");
	puts("");
	puts("Game Arena");
	puts("'SPACE' - Shoot");
	puts("'r' - Reload");
	puts("'f' - Skill");
	puts("'1' - Use Potion");
	puts("'2' - Use Max Potion");
	puts("'3' - Use Energy");
	puts("'4' - Use Max Energy");
	puts("'g' - Use Bomb");
	
	puts("");
	printf("Back to menu? [press enter]");
	while(!kbhit());
	
	// GOTO menu()
	return 1; // For callback purpose
}

int howtoplay() {
	FILE * fp;
	fp = fopen("./howtoplay.txt", "r");
	char text[1000];
	do {
		fscanf(fp, "%s\n", text);
		printf("%s\n", text);
	} while(!feof(fp));
	fclose(fp);
	printf("Back to menu ? [press enter]");
	while(!kbhit());
	return 1;
}


void menu() {

 	int pointer = 1;
	
 	int input;

 	do {
		
 		switch(pointer) {
			case 1 :
				puts("NEW GAME         <");
				puts("LOAD GAME");
				puts("SETTING");
				puts("HOW TO PLAY");
				puts("EXIT");
				break;
			
			case 2 :
				puts("NEW GAME");
				puts("LOAD GAME        <");
				puts("SETTING");
				puts("HOW TO PLAY");
				puts("EXIT");
				break;
			case 3 :
				puts("NEW GAME");
				puts("LOAD GAME");
				puts("SETTING          <");
				puts("HOW TO PLAY");
				puts("EXIT");
				break;
			case 4 :
				puts("NEW GAME");
				puts("LOAD GAME");
				puts("SETTING");
				puts("HOW TO PLAY      <");
				puts("EXIT");
				break;
			case 5 :
				puts("NEW GAME");
				puts("LOAD GAME");
				puts("SETTING");
				puts("HOW TO PLAY");
				puts("EXIT             <");
				break;
 		}
 		printf(">>> ");
        input = 0;

        HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  

        DWORD Events = 0;   
        DWORD EventsRead = 0; 

        bool Running = true;



        GetNumberOfConsoleInputEvents(rhnd, &Events);

        if(Events != 0) { 


            INPUT_RECORD eventBuffer[Events];


            ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);
            for(DWORD i = 0; i < EventsRead; ++i){

                if(eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown){


                    switch(eventBuffer[i].Event.KeyEvent.wVirtualKeyCode){
                        case VK_UP:
                        	if(pointer == 0) { pointer = 5; break; }
                        	else {
                        		pointer--; break;
							}
                        	
                        case VK_DOWN:  
                            if( pointer == 6 ) { pointer = 1; break; }
                            else {
                            	pointer++; break;
							}
						case VK_RETURN:
							input = 1;
							break;

                    }
                }

            } 

        

        } 

 		system("cls");
 	} while(input != 1);
		

 	printf("Entering Menu %d\n", pointer);
 	
 	switch(pointer){
 		case 1:
 			newgame();
 			break;
 		case 2:
 			loadgame();
 			break;
 		case 3:
 			if(setting()){
 				menu();
			 }
			 break;
		case 4:
			if(howtoplay()) {
				menu();
			}
			break;
	}
 }
	


int main() {

	
//	char string[] = "Bruh Bro";
//	char sub[] = "Bro";
//
//	printf("%d", checkString(string, sub));

	menu();

	return 0;

}



#TODO
