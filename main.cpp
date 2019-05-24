#include <iostream>
#include <time.h>
#include <stdlib.h>
//#include <ncurses.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//TODO: ncurses implementation and changelog

#define MAX 94
char const lowerCase[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 
					'o', 'p', 'q', 'r', 's', 't', 'u', 
					'v', 'w', 'x', 'y', 'z' }; 
char const upperCase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N',
					'O', 'P', 'Q', 'R', 'S', 'T', 'U',
					'V', 'W', 'X', 'Y', 'Z'
					};
char const symbols[32] = { '!', '\'','\"', '#', '$', '%', '&', '(',
					')', '*', '+', ',', '-', '.', '/', ':', ';', '<',
					'=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', 
					'{', '|', '}', '~',
						};
char const num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct settings{
	int length = 16;
	bool hasSymbols = true;
	bool hasNumbers = true;
	bool hasLowerCase = true;
	bool hasUpperCase = true;
};

void titleSetup();
void makePassword(settings x, char* customPass);
void changeSettings(settings x, char option, char* customPass);
void settingsDisplay(settings x, char* customPass);
void menuDisplay(settings x, char* customPass);
void init();
void viewChangeLog(settings x, char* customPass);

void titleSetup(){
	std::cout << "Password Generator version 0.3 \t\t\t\t\t\t\t\t\t\tPress q to quit." << std::endl;
	std::cout << "Created by John Skilitis" << std::endl;
}

void makePassword(settings x, char* customPass){
	system("CLS");
	char alphabet[MAX];
	int j = 0;
	int arrayLength = 0;
	if(x.hasLowerCase){
		j = 0;
		for(int i = arrayLength; i < arrayLength+26; i++){
			alphabet[i] = lowerCase[j];
			j++;
		}
		arrayLength = arrayLength+26;
	}
	if(x.hasUpperCase){
		j = 0;
		for(int i = arrayLength; i < arrayLength+26; i++){
			alphabet[i] = upperCase[j];
			j++;
		}
		arrayLength = arrayLength+26;
	}
	if(x.hasNumbers){
		j = 0;
		for(int i = arrayLength; i < arrayLength+10; i++){
			alphabet[i] = num[j];
			j++;
		}
		arrayLength = arrayLength+10;
	}
	if(x.hasSymbols){
		j = 0;
		for(int i = arrayLength; i < arrayLength+32; i++){
			alphabet[i] = symbols[j];
			j++;
		}
		arrayLength = arrayLength+32;
	}
	for(int i = 0; i < x.length-1; i++){
		int temp = rand() % (arrayLength-1) +1;
		customPass[i] = alphabet[temp];
	}
	std::cout << customPass << std::endl;
	std::cout << std::string(5, '\n');
	std::cout << "Press q to quit \nPress r to make a new password" << std::endl;
	
	char reply;
	std::cin >> reply;
	
	if(reply == 'r')
		makePassword(x, customPass);
	else if(reply == 'q')
		menuDisplay(x, customPass);
	
}

void changeSettings(settings x, char option, char* customPass){
	std::cout << std::string(15, '\n');
	switch(option){
		case 49:
			int newLen;
			std::cout << "Enter new length: ";
			std::cin >> x.length;
			//std::cout << "\nNew length = " << x.length << std::endl;
			break;
		case 50:
			if(x.hasLowerCase){
				//std::cout << "Password will no longer contain lowercase letters." << std::endl;
				x.hasLowerCase = false;
			}
			else{
				//std::cout << "Password will now contain lowercase letters." << std::endl;
				x.hasLowerCase = true;
			}
			break;
		case 51:
			if(x.hasUpperCase){
				//std::cout << "Password will no longer contain uppercase letters." << std::endl;
				x.hasUpperCase = false;
			}
			else{
				//std::cout << "Password will now contain uppercase letters." << std::endl;
				x.hasUpperCase = true;
			}
			break;
		case 52:
			if(x.hasNumbers){
				//std::cout << "Password will no longer contain numbers." << std::endl;
				x.hasNumbers = false;
			}
			else{
				//std::cout << "Password will now contain numbers." << std::endl;
				x.hasNumbers = true;
			}
			break;
		case 53:
			if(x.hasSymbols){
				//std::cout << "Password will no longer contain symbols." << std::endl;
				x.hasSymbols = false;
			}
			else{
				//std::cout << "Password will now contain symbols." << std::endl;
				x.hasSymbols = true;
			}
			break;
	}
	settingsDisplay(x, customPass);
}

void settingsDisplay(settings x, char* customPass){
	system("CLS");
	char reply;
	
	std::cout << "Press 1-5 to change a setting\n" << std::endl;
	std::cout << "Press q to return to main menu\n\n" << std::endl;
	std::cout << "1. Password Length = " << x.length << std::endl;
	std::cout << "2. Contains Lowercase Letters = " << x.hasLowerCase << std::endl;
	std::cout << "3. Contains Uppercase Letters = " << x.hasUpperCase << std::endl;
	std::cout << "4. Contains Numbers = " << x.hasNumbers << std::endl;
	std::cout << "5. Contains Symbols = " << x.hasSymbols << std::endl;
	std::cin >> reply;
	if(reply == 'q'){
		menuDisplay(x, customPass);
	}
	else if(reply >= 49 && reply <= 53){
		changeSettings(x, reply, customPass);
	}
		
}

void viewChangeLog(settings x, char* customPass){
	system("CLS");
	std::cout << "Press q to quit" << std::endl;
	std::cout << std::string(5, '\n');
	std::cout << "We Changed Things!" << std::endl;
	char reply;
	std::cin >> reply;
	if(reply == 'q'){
		menuDisplay(x, customPass);
	}
}
void menuDisplay(settings x, char* customPass){
	system("CLS");
	char option = -1;
	titleSetup();
	std::cout << std::string(5, '\n');
	std::cout << "1. Create New Password \n2. Settings \n3. Changelog";  
    std::cout << std::string(11, '\n');
//    option == getch();
	std::cin >> option;
    switch(option){
    	case 49:
    		makePassword(x, customPass);
    		break; 
    	case 50:
    		settingsDisplay(x, customPass);
    		break;
    	case 51:
    		viewChangeLog(x, customPass);
    	case 113:
    		return;
	}
}


void init(){
//	initscr();
//	noecho();
	settings x;
	char customPass[x.length];
	

	menuDisplay(x, customPass);
}


int main() {
	srand(time(0)); 
	init();	
	return 0;
}


