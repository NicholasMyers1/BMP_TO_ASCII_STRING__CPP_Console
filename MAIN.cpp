#include "includesVoids.h"
int main(int argc,char **argv){//main and set window properties;

	while(1){
		system("CLS");
		INIT();//reset the code each iteration; while(1) means the program won't exit;
		
		//cout the text so the user knows what to do: 
		cout<<"Drag in 24-bit bitmap (24-bit BMP) file, or enter the file's full file path, name and its extension.\n(ex: \"C:\\users\\%USERNAME%\\desktop\\abcde.bmp\")\n";
		cout<<"File: ";
		RETURN.returnString=KEY_INPUT();//get file input from user;
		
		//check if the user input is valid and find the syntax errors: 
		CHECK_IF_FILE_EXISTS(RETURN.returnString);//check file;check if it exists and not empty, get extension, read file;
		if(WINDOW.mode==-1){
			system("PAUSE");
			INIT();
			continue;
		}
		
		//have the user enter the string name for this image: 
		while(WINDOW.mode==1){
			cout<<"Enter a valid name for your string: ";
			RETURN.returnString=KEY_INPUT();//get file input from user;
			FILES.enterString=RETURN.returnString;
		}
		//set the width and height of the image: 
		while(WINDOW.mode==2){
			cout<<"Enter the width of the BMP image: ";
			RETURN.returnString=KEY_INPUT();
		}
		if(WINDOW.mode==3)istringstream(RETURN.returnString)>>FILES.width;//convert: 
		while(WINDOW.mode==3){
			cout<<"Enter the height of the BMP image: ";
			RETURN.returnString=KEY_INPUT();
		}
		if(WINDOW.mode==4)istringstream(RETURN.returnString)>>FILES.height;//convert: 
		
		//read the image: 
		READ_FILE(FILES.fileName);//read the file: 
		
		//write to the output file: 
		WRITE_FILE();
		cout<<"Your string was saved to: '_output_BMP_to_string.txt'\n";
		
		//at the end of the loop, pause the system to allow the user to see everything displayed until a key is pressed:
		system("PAUSE");INIT();
	}
	return 0;
}//end void;
