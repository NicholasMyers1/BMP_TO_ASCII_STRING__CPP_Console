#include "includesVoids.h"
void CHECK_IF_FILE_EXISTS(string file){
	string lineData="\0";

	//check if the file is null, exists, doesn't exist, etc: 
	FILES.readFile_.open(file);
	getline(FILES.readFile_,lineData);
		if(!FILES.readFile_){//file does not exist;
			FILES.readFile_.close();
			cout<<"This file does not exist, or it is not of a 'bmp' type.\n";
			WINDOW.mode=-1;//INIT();
		}
		else{//find out the extension, then read the file if it is a png;
			FILES.readFile_.close();
			CHECK_EXTENSION(file);
		}
}//end void;
void CHECK_EXTENSION(string file){
	string fileExtension="\0";
	//find the extension of the file: etc: 
	for(int n=file.length()-1;n>-1;n--){//find extension: 
		if(file[n]>64&&file[n]<91)file[n]+=32;//convert to lowercase:
		if(file[(n)]=='.')break;
		else fileExtension+=file[n];
	}
	reverse(fileExtension.begin(),fileExtension.end());//reverse the string to a be read correctly;
	if(fileExtension=="bmp")
	FILES.fileName=file;//READ_FILE(file);//read the file: 
	else{
		cout<<"This file is not of a 'bmp' type.\n";
		WINDOW.mode=-1;//INIT();
	}
}//end void;
void READ_FILE(string file){
	BYTE * data;
	FILE * file_type;
	
	//set the size of the image: 
	FILES.size=FILES.width*FILES.height*3;
		
	//open the file sand read it: 
	file_type=fopen(file.c_str(),"rb");
    	data=new BYTE[FILES.size];
    	fread(data,FILES.size,1,file_type);
	fclose(file_type);

	//convert the contents of the file to decimal digits (0-255): 
	unsigned __int8 imageData[FILES.size];
	for(int n=0;n<FILES.size;n++){
		imageData[n]=data[n];
		int decimalColor=(int)imageData[n];
		//convert:
		stringstream convert_;
		convert_<<decimalColor;
		FILES.fileData.insert(FILES.fileData.length(),(string)convert_.str()+" ");
		convert_.str("");convert_.clear();
	}
}//end void;
void WRITE_FILE(){
	//convert:
	stringstream convert_;
	FILES.writeFile_.open("_output_BMP_to_string.txt",ios::app);
		FILES.writeFile_<<"string "<<FILES.enterString<<"=\"";
		convert_<<FILES.width;
		FILES.writeFile_<<"WIDTH: "<<convert_.str()<<",";
		convert_.str("");convert_.clear();
		convert_<<FILES.height;
		FILES.writeFile_<<"HEIGHT: "<<convert_.str()<<";";
		convert_.str("");convert_.clear();
		for(int n=0;n<FILES.fileData.length();n++){
			FILES.writeFile_<<FILES.fileData[n];
		}
		FILES.writeFile_<<"\";\n";
	FILES.writeFile_.close();
}
