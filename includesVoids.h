#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
	#include <iostream>
	#include <fstream>
	#include <algorithm>
	#include <stdio.h>
	#include <windef.h>
	#include <sstream>
	//#include <cstdlib>
	using namespace std;/*	-lAdvApi32	-lwinmm	*/
	//VOIDS: 
		//INIT.cpp:
			void INIT();
		//MAIN.cpp: 
			int main(int argc,char **argv);
		//READ_WRITE.cpp: 
			void CHECK_IF_FILE_EXISTS(string file);	
			void READ_FILE(string file); 
			void CHECK_EXTENSION(string file);
			void WRITE_FILE();
		//KEYBOARD_INPUT.cpp: 
			string KEY_INPUT();
	//STRUCTURES:
		struct _FILES{
			string enterString;
			string fileName;
			string fileData;
			ifstream readFile_;	
			ofstream writeFile_;
			//image data for files: 
				int width, height, size;
		};	extern _FILES FILES;
		struct _RETURN{string returnString;};
			extern _RETURN RETURN;
		struct _WINDOW{int mode;};
			extern _WINDOW WINDOW;
#endif
