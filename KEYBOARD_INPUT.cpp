#include "includesVoids.h"
string KEY_INPUT(){
	char *line=new char[255];	

	string afterInput="\0";//get the input from the user;

	//get user input: 
	cin.getline(line,255);
	afterInput=line;//get input until user hits the enter key;

	//switch the window mode: 
	switch(WINDOW.mode){//switch the window mode; mode 0: input file name; mode 1: choose the language if necessary;
		case 0:	
			for(int n=0;n<afterInput.length();n++){
				if(afterInput[n]=='\"')afterInput.erase(n,1);
			}
			WINDOW.mode=1;
			break;
		case 1: 
			for(int n=0;n<afterInput.length();n++){
				if(	afterInput[0]<(int)65&&afterInput[0]>(int)0||
					afterInput[0]<(int)95&&afterInput[0]>(int)90||
					afterInput[0]<(int)97&&afterInput[0]>(int)95||
					afterInput[0]>(int)122
				){
					cout<<"You have an invalid input for your string.\n";
					break;
				}
				if(n>0){
					if(	afterInput[n]<(int)48&&afterInput[n]>(int)0||
						afterInput[n]<(int)65&&afterInput[n]>(int)57||
						afterInput[n]<(int)95&&afterInput[n]>(int)90||
						afterInput[n]<(int)97&&afterInput[n]>(int)95||
						afterInput[n]>(int)122
					){
						cout<<"You have an invalid input for your string.\n";
						break;
					}
				}
				if(n==afterInput.length()-1){
					WINDOW.mode=2;
				}
			}
			break;
		case 2:	case 3:  
			for(int n=0;n<afterInput.length();n++){
				if(afterInput.length()==1){
					if(afterInput[0]=='0'){
						cout<<"You have an invalid input for your image dimension.\n";
						break;
					}
				}
				if(n>0){
					if(afterInput[n]<(int)48||afterInput[n]>(int)57){
						cout<<"You have an invalid input for your image dimension.\n";
						break;
					}
				}
				if(n==afterInput.length()-1){
					WINDOW.mode+=1;
				}
			}
	}return(afterInput);
}//end void;
