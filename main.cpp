#include <iostream>
#include <time.h>
#include <stdlib.h>
//#include <ncurses.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//TODO: ncurses implementation and symbols doesn't go into alphabet[]

#define MAX 67
char const lowerCase[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 
					'o', 'p', 'q', 'r', 's', 't', 'u', 
					'v', 'w', 'x', 'y', 'z' }; 
char const upperCase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N',
					'O', 'P', 'Q', 'R', 'S', 'T', 'U',
					'V', 'W', 'X', 'Y', 'Z'
					};
char const symbols[15] = {'!', '@', '#', '$', '%','^','&','*',
							',','.','?',';',':','~','`'
						};
char const num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct settings{
	int length = 16;
	bool hasSymbols = true;
	bool hasNumbers = true;
	bool hasLowerCase = true;
	bool hasUpperCase = true;
};



void titleSetup(){
	std::cout << "Password Generator version 0.2" << std::endl;
	std::cout << "Created by John Skilitis" << std::endl;
}

char* makePassword(settings x, char* customPass){
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
		for(int i = arrayLength; i < arrayLength+15; i++){
			alphabet[i] = symbols[j];
			j++;
		}
		arrayLength = arrayLength+15;
	}
	for(int i = 0; i < x.length-1; i++){
		int temp = rand() % (arrayLength-1) +1;
		customPass[i] = alphabet[temp];
	}
	return customPass;
}

void changeSettings(settings x, char option){
	switch(option){
		case "1":
			int newLen;
			std::cout << "Enter new length: "
			std::cin >> x.length;
			std::cout << "\nNew length = " << x.length << std::endl;
	}
}

void settingsDisplay(settings x, char* customPass){
	system("CLS");
	char reply;
	
	std::cout << "Press a number to change settings" << std::endl;
	std::cout << "Press q to return to main menu" << std::endl;
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
		changeSettings(x, reply);
	}
		
}

void menuDisplay(settings x, char* customPass){
	system("CLS");
	int option = -1;
	titleSetup();
	std::cout << std::string(5, '\n');
	std::cout << "1. Create New Password \n2. Settings \n3. Changelog\n";  
    std::cout << std::string(11, '\n');
//    option == getch();
	std::cin >> option;
    switch(option){
    	case 1:
    		std::cout << makePassword(x, customPass) << std::endl;
    		break; 
    	case 2:
    		settingsDisplay(x);
    		break;
    	case 3:
    		std::cout << "We Changed Things" << std::endl;
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


