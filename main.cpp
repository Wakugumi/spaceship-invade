#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

// User-defined header
#include "T143_utility.h"

#define KEY_UP 72
#define KEY_DOWN 80


using namespace std;



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
			
			case 2:
				puts("NEW GAME");
				puts("LOAD GAME        <");
				puts("SETTING");
				puts("HOW TO PLAY");
				puts("EXIT");
				break;
			case 3:
				puts("NEW GAME");
				puts("LOAD GAME");
				puts("SETTING          <");
				puts("HOW TO PLAY");
				puts("EXIT");
				break;
			case 4:
				puts("NEW GAME");
				puts("LOAD GAME");
				puts("SETTING");
				puts("HOW TO PLAY      <");
				puts("EXIT");
				break;
			case 5:
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
                        	if(pointer == 1) { pointer = 5; break; }
                        	else {
                        		pointer--; break;
							}
                        	
                        case VK_DOWN:  
                            if( pointer == 5 ) { pointer = 1; break; }
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
		default:
			puts("Out of index");
	}
 }
	


int main() {

	
//	char string[] = "Bruh Bro";
//	char sub[] = "Bro";
//
//	printf("%d", checkString(string, sub));

    loadgame();

	return 0;

}
